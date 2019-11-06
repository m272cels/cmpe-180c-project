#include <iostream>
#include <unistd.h>
#include "main.h"

using namespace std;

int const NUMBER_OF_CUSTOMERS = 5;
int const NUMBER_OF_RESOURCES = 3;

int i,j;

/* the available amount of each resource */
int available[NUMBER_OF_RESOURCES];

/*the maximum demand of each customer */
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the amount currently allocated to each customer */
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the remaining need of each customer */
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

// check whether a customer still needs any resources.
// returns false if need is all 0 for this customer
bool customer_still_has_need(int customer_num) {
  for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
    if (need[customer_num][i] > 0) {
      return true;
    }
  }
  return false;
}

// struct for passing customer num from banker thread to customer threads
typedef struct _customer_thread_data_t {
  int customer_num;
} customer_thread_data_t;

void * run_customer_thread(void * arg) {
  // wait at least 1 second for banker to initialize all customers
  sleep((rand() % 9) + 1);

  customer_thread_data_t *data = (customer_thread_data_t *) arg;
  int customer_num = data->customer_num;
  int i;

  while(customer_still_has_need(customer_num)) {
    int request[NUMBER_OF_RESOURCES];
    for (i = 0; i < NUMBER_OF_RESOURCES; i++)
      request[i] = rand() % (need[customer_num][i] + 1);

    cout << "customer " << customer_num << " wants to request resources." << endl;
    bank_mutex::acquire();

    cout << "customer " << customer_num << " has acquired lock." << endl;
    cout << "request for customer " << customer_num << " contains: ";
    for (i = 0; i < NUMBER_OF_RESOURCES; i++)
      cout << request[i] << " ";
    cout << endl;

    int result = request_resources(customer_num, request);

    string readable_result = "";
    if (result == 0) {
      readable_result = "request successful!";
    }
    else if (result == -1) {
      readable_result = "request failed";
    }
    cout << "customer " << customer_num << " " << readable_result << endl;
    print_everything();

    bank_mutex::release();
    cout << "customer " << customer_num << " has released lock." << endl;

    // wait a semi-random amount of time before making another request
    sleep((rand() % 9) + 1);
  }

  cout << "customer " << customer_num << " finished!" << endl;
  print_everything();


  cout << "customer " << customer_num << " wants to release resources." << endl;
  bank_mutex::acquire();
  cout << "customer " << customer_num << " has acquired lock." << endl;

  release_resources(customer_num, allocation[customer_num]);
  print_everything();

  bank_mutex::release();
  cout << "customer " << customer_num << " has released lock." << endl;

  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  // take command-line arguments (e.g. 10 5 7) and put into available array
  for (i = 1; i < argc; i++)
    available[i - 1] = atoi(argv[i]);

  cout << "Available array has:\n";
  for (i = 0; i < NUMBER_OF_RESOURCES; i++)
    cout << available[i] << " ";

  cout << endl;
  int temp;
  // initialize the maximum
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "What is the maximum resource demand for Customer " << i << "?\n";
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << "Resource " << j + 1 << ": ";
      cin >> temp;
      maximum[i][j] = temp;
      need[i][j] = temp;
    }
  }

  // initialize the allocation
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "What is the current resource allocation for Customer " << i << "?\n";
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << "Resource " << j + 1 << ": ";
      cin >> temp;
      allocation[i][j] = temp;
      need[i][j] -= temp;
      available[j] -= temp;
    }
  }

  srand(time(NULL));

  pthread_t customer_threads[NUMBER_OF_CUSTOMERS];
  customer_thread_data_t customer_data[NUMBER_OF_CUSTOMERS];
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "banker creating thread for customer " << i << endl;
    customer_data[i].customer_num = i;
    pthread_create(&customer_threads[i], NULL, run_customer_thread, &customer_data[i]);
  }

  cout << "banker waiting for customers to finish..." << endl;
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    pthread_join(customer_threads[i], NULL);
  }

  cout << endl << "all customers finished, banker is done for the day";
  return 0;
}

// Check if each element of left_array <= each element of right_array
bool less_than_or_equals_arrays(int left_array[], int right_array[]) {
  for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
    if (left_array[j] > right_array[j]) {
      return false;
    }
  }
  return true;
}

// safety algorithm
bool bank_is_safe() {
  int work[NUMBER_OF_RESOURCES];
  int finish[NUMBER_OF_CUSTOMERS];
  int i;
  for (i = 0; i < NUMBER_OF_RESOURCES; i++)
    work[i] = available[i];

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    finish[i] = false;

  while(true) {
    for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
      if (!finish[i] && less_than_or_equals_arrays(need[i], work))
        break;
    }
    if (i == NUMBER_OF_CUSTOMERS)
      break;

    for(j = 0; j < NUMBER_OF_RESOURCES; j++)
      work[j] += allocation[i][j];

    finish[i] = true;
  }

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    if (!finish[i])
      return false;
  }
  return true;
}

// validates that request is within need and within available resources
// tests allocating the resource is safe using safety algorithm, then rolls back if unsafe
int request_resources(int customer_num, int request[]) {
  if (!less_than_or_equals_arrays(request, need[customer_num])) {
    cout << "Error: Customer request exceeded max claim." << endl;
    return -1;
  }

  if (!less_than_or_equals_arrays(request, available)) {
    cout << "Error: Not enough resources are available." << endl;
    return -1;
  }

  allocate_resources(customer_num, request);

  if (!bank_is_safe()) {
    // cout << "Woops! Request would cause unsafe state. Rolling back..." << endl;
    deallocate_resources(customer_num, request);
    // print_everything();
    return -1;
  }

  return 0;
}

// key part of request_resource where resource transactions actually take place
int allocate_resources(int customer_num, int allocate[]) {
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] -= allocate[i];
    allocation[customer_num][i] += allocate[i];
    need[customer_num][i] -= allocate[i];
  }
  return 0;
}

// used for reversing allocation of resources in request_resource when allocation unsafe
int deallocate_resources(int customer_num, int deallocate[]) {
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] += deallocate[i];
    allocation[customer_num][i] -= deallocate[i];
    need[customer_num][i] += deallocate[i];
  }
  return 0;
}

// when customer is done, release resources without affecting need
int release_resources(int customer_num, int release[]) {
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] += release[i];
    allocation[customer_num][i] -= release[i];
  }
  return 0;
}

// helper method that prints all the important shared data structures
void print_everything() {
  cout << endl << "allocation: " << endl;
  for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << allocation[i][j] << " ";
    }
    cout << endl;
  }
  cout << "need: " << endl;
  for (int i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    for (int j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << need[i][j] << " ";
    }
    cout << endl;
  }
  cout << "available: ";
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    cout << available[i] << " ";
  }
  cout << endl << endl;
}

namespace bank_mutex {
  bool available = true;

  void acquire() {
    while (!available)
      ;
    available = false;
  }

  void release() {
    available = true;
  }
}