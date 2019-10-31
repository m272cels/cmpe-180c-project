/*
Implementation:
You should invoke your program by passing the number of resources of
each type on the command line. For example, if there were three
resource types, with ten instances of the first type, five of the
second type, and seven of the third type, you would invoke your
program follows:

./a.out 10 5 7

The available array would be initialized to these values. You may
initialize the maximum array (which holds the maximum demand of each
customer) using any method you find convenient.
*/
#include <iostream>
#include <unistd.h>
#include "main.h"
// include resource request algo
// inside resource request algo, include safety algo

using namespace std;

int const NUMBER_OF_CUSTOMERS = 2; // n in the textbook
int const NUMBER_OF_RESOURCES = 3; // m in the textbook

int i,j;

/* the available amount of each resource */
int available[NUMBER_OF_RESOURCES];

/*the maximum demand of each customer */
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the amount currently allocated to each customer */
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the remaining need of each customer */
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

bool customer_still_has_need(int customer_num) {
  for (int i = 0; i < NUMBER_OF_RESOURCES; i++) {
    if (need[customer_num][i] > 0) {
      return true;
    }
  }
  return false;
}

typedef struct _customer_thread_data_t {
  int customer_num;
} customer_thread_data_t;

void * run_customer_thread(void * arg) {
  customer_thread_data_t *data = (customer_thread_data_t *) arg;
  int customer_num = data->customer_num;
  int i;
  cout << "max for customer " << customer_num << " is [";
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    cout << maximum[customer_num][i];
    if (i + 1 != NUMBER_OF_RESOURCES)
      cout << ", ";
  }
  cout << "]" << endl;

  while(customer_still_has_need(customer_num)) {
    int request[NUMBER_OF_RESOURCES];
    for (i = 0; i < NUMBER_OF_RESOURCES; i++)
      request[i] = rand() % (need[customer_num][i] + 1);

    cout << "request for customer " << customer_num << " contains: ";
    for (i = 0; i < NUMBER_OF_RESOURCES; i++)
      cout << request[i] << " ";
    cout << endl;

    cout << "customer " << customer_num << " wants to request resources." << endl;
    bank_mutex::acquire();
    cout << "customer " << customer_num << " has acquired lock." << endl;

    int result = request_resources(customer_num, request);

    bank_mutex::release();
    cout << "customer " << customer_num << " has released lock." << endl;

    string readable_result = "";
    if (result == 0) {
      readable_result = "request successful!";
    }
    else if (result == -1) {
      readable_result = "request failed";
    }
    cout << "customer " << customer_num << " " << readable_result << endl;

    print_everything();

    sleep(rand() % 10);
  }

  cout << "customer " << customer_num << " finished!" << endl;
  print_everything();


  cout << "customer " << customer_num << " wants to release resources." << endl;
  bank_mutex::acquire();
  cout << "customer " << customer_num << " has acquired lock." << endl;

  release_resources(customer_num, allocation[customer_num]);

  bank_mutex::release();
  cout << "customer " << customer_num << " has released lock." << endl;


  print_everything();

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
    }
  }

  srand(time(NULL));

  pthread_t customer_threads[NUMBER_OF_CUSTOMERS];
  customer_thread_data_t customer_data[NUMBER_OF_CUSTOMERS];
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "banker creating thread for customer " << i << endl;
    customer_data[i].customer_num = i;
    pthread_create(&customer_threads[i], NULL, run_customer_thread, &customer_data[i]);
    // sleep(1);
  }

  cout << "banker waiting for customers to finish..." << endl;

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    pthread_join(customer_threads[i], NULL);
  }

  cout << endl << "all customers finished, banker is done for the day";

  /* for each customer (async, in between each time you do this, sleep a random number of seconds)
    USE bank_MUTEX LOCKS!!
      // alternate request or release resource
      // randomly decide how much of each resource to request or release
      TRY only request, randomly decide how much of each resource
      make the request
      RELEASE only if finished
      log the result
      */

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

bool safety_algorithm() {
  cout << "enter safety algorithm..." << endl;
  // cout << "STEP 1" << endl;
  // STEP 1
  int work[NUMBER_OF_RESOURCES]; // length m
  int finish[NUMBER_OF_CUSTOMERS]; // length n
  int i;
  for (i = 0; i < NUMBER_OF_RESOURCES; i++)
    work[i] = available[i];

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++)
    finish[i] = false;


  // cout << "work contains: ";
  // for (i = 0; i < NUMBER_OF_CUSTOMERS; i++)
  //   cout << work[i] << " ";

  // cout << "\n";
  // cout << "finish contains: ";
  // for (i = 0; i < NUMBER_OF_RESOURCES; i++)
  //   cout << finish[i] << " ";

  // return true;

  while(true) {
    // cout << "STEP 2\n";
    // STEP 2
    for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
      bool condition_a = !finish[i]; // finish[i] == false
      // cout << "Need[i] contains ";
      // for(j = 0; j < NUMBER_OF_RESOURCES; j++)
      //   cout << need[i][j] << " ";

      // cout << "\nWork contains ";
      // for (j = 0; j < NUMBER_OF_RESOURCES; j++)
      //   cout << work[j] << " ";

      // cout << "\n";
      // cout << "Comparing need and work for Customer " << i + 1 << "\n";
      bool condition_b = less_than_or_equals_arrays(need[i], work);
      // cout << "Condition A: " << condition_a << " and Condition B: " << condition_b << "\n";
      if (condition_a && condition_b) {
        break;
      }
    }
    // GO TO STEP 4 IF i == NUMBER_OF_RESOURCES
    if (i == NUMBER_OF_CUSTOMERS) {
      cout << "Breaking out now, either customers all finished or no more customers can be finished.\n";
      break;
    }

    // cout << "STEP 3\n";
    // STEP 3
    for(j = 0; j < NUMBER_OF_RESOURCES; j++) {
      work[j] += allocation[i][j];
    }
    finish[i] = true;
  }

  // cout << "STEP 4\n";
  // STEP 4
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    if (!finish[i]) {
      return false;
    }
  }
  return true;
}

int request_resources(int customer_num, int request[]) {

  // STEP 1
  // if (!need_covers_request) {
  if (!less_than_or_equals_arrays(request, need[customer_num])) {
    cout << "Error: Customer request exceeded max claim.";
    return -1;
  }


  // STEP 2
  // if (!available_covers_request) {
  if (!less_than_or_equals_arrays(request, available)) {
    cout << "Error: Not enough resources are available.";
    return -1;
  }

  // STEP 3
  allocate_resources(customer_num, request);

  // cout << "try allocating resources..." << endl;
  // cout << "allocation contains: ";
  // for (i = 0; i < NUMBER_OF_RESOURCES; i++)
  //   cout << allocation[customer_num][i] << " ";
  // cout << endl;

  // STEP 4
  bool state_is_safe = safety_algorithm();
  if (!state_is_safe) {
    cout << "Woops! Request would cause unsafe state. Rolling back..." << endl;
    deallocate_resources(customer_num, request);

    print_everything();

    return -1;
  }

  return 0;
}

// STEP 3 of request_resources
int allocate_resources(int customer_num, int allocate[]) {
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] -= allocate[i];
    allocation[customer_num][i] += allocate[i];
    need[customer_num][i] -= allocate[i];
  }

  // available = available - request;
  // allocation[customer_num] = allocation[customer_num] + request;
  // need[customer_num] = need[customer_num] - request;
  return 0;
}

// STEP 4 of request_resources, but also standalone
int deallocate_resources(int customer_num, int deallocate[]) {
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] += deallocate[i];
    allocation[customer_num][i] -= deallocate[i];
    need[customer_num][i] += deallocate[i];
  }
  // available = available + request;
  // allocation[customer_num] = allocation[customer_num] - request;
  // need[customer_num] = need[customer_num] + request;
  return 0;
}

int release_resources(int customer_num, int release[]) {
  // DON'T FORGET, CHECK bank_MUTEX LOCK (SHARED WITH request_resources)

  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] += release[i];
    allocation[customer_num][i] -= release[i];
  }
  // available = available + request;
  // allocation[customer_num] = allocation[customer_num] - request;
  // need[customer_num] = need[customer_num] + request;
  return 0;
}


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