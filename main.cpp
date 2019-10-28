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
int const NUMBER_OF_RESOURCES = 2; // m in the textbook

int i,j;

/* the available amount of each resource */
int available[NUMBER_OF_RESOURCES];

/*the maximum demand of each customer */
int maximum[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the amount currently allocated to each customer */
int allocation[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

/* the remaining need of each customer */
int need[NUMBER_OF_CUSTOMERS][NUMBER_OF_RESOURCES];

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

  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  // take command-line arguments (e.g. 10 5 7) and put into available array

  for (i = 1; i < argc; i++)
    available[i - 1] = atoi(argv[i]);

  cout << "Available array has:\n";
  for (i = 0; i < NUMBER_OF_RESOURCES; i++)
    cout << available[i] << "\n";

  int temp;
  // initialize the maximum
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "What is the maximum resource demand for Customer " << i + 1 << "?\n";
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << "Resource " << j + 1 << ": ";
      cin >> temp;
      maximum[i][j] = temp;
      need[i][j] = temp;
    }
  }

  // initialize the allocation
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "What is the current resource allocation for Customer " << i + 1 << "?\n";
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << "Resource " << j + 1 << ": ";
      cin >> temp;
      allocation[i][j] = temp;
      need[i][j] -= temp;
    }
  }

  srand(time(NULL));

  cout << "TESTING MULTITHREAD" << endl;
  cout << "NUMBER OF THREADS: " << NUMBER_OF_CUSTOMERS << endl;

  pthread_t customer_threads[NUMBER_OF_CUSTOMERS];
  customer_thread_data_t customer_data[NUMBER_OF_CUSTOMERS];
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    customer_data[i].customer_num = i;
    pthread_create(&customer_threads[i], NULL, run_customer_thread, &customer_data[i]);
    sleep(1);
  }

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    pthread_join(customer_threads[i], NULL);
  }

  // cout << "Making random requests now..." << endl;
  // TODO: DECIDE WHAT HAPPENS WHEN CUSTOMER IS DONE
    // always need to return all resources to available, but then what??
  // 1. Change need to 0
  // 2. Change max to 0
  // 3. Only if iterative, 1 main process, Add another data structure, bool completed[NUMBER_OF_CUSTOMERS], init to all false, when finished set to true and then skip
  // 4. If multithreaded, customer threads just use pthread_exit(0),
  // and the banker thread will be waiting for all customer to finish using pthread_join()
  // srand(time(NULL));
  // while (need > 0)
  // for (j = 0; customers_all_finished(); j++) {

  //   int customer_num = j % NUMBER_OF_CUSTOMERS;
  //   int request[NUMBER_OF_RESOURCES];
  //   for (i = 0; i < NUMBER_OF_RESOURCES; i++)
  //     request[i] = rand() % maximum[customer_num][i];

  //   cout << "request contains: ";
  //   for (i = 0; i < NUMBER_OF_RESOURCES; i++)
  //     cout << request[i] << " ";
  //   cout << endl;

  //   cout << "Try to request a resource..." << endl;
  //   int result = request_resources(customer_num, request);

  //   string readable_result = "";
  //   if (result == 0) {
  //     readable_result = "request successful!";
  //   }
  //   else if (result == -1) {
  //     readable_result = "request failed";
  //   }
  //   cout << readable_result << endl;

  //   // if all done, then exit
  // }



// printing maximum
  // for (i = 0 ; i < NUMBER_OF_CUSTOMERS; i++){
  //   for (j = 0 ; j < NUMBER_OF_RESOURCES; j++){
  //     cout << maximum[i][j] << "\n";
  //   }
  // }

  // for each customer
    // start a thread
      // thread will randomly request resources, constrained by max
      // INSERT HERE: Request-Resource Algorithm
      // banker main thread has to know if this will cause deadlock or is unsafe
      // if not unsafe, give resources to thread
      // if thread gets max resources, it exits
      // customer will randomly release some resources

  /* for each customer (async, in between each time you do this, sleep a random number of seconds)
    USE MUTEX LOCKS!!
      // alternate request or release resource
      // randomly decide how much of each resource to request or release
      TRY only request, randomly decide how much of each resource
      make the request
      RELEASE only if finished
      log the result
      */

  // cout << "Run safety algorithm...\n";
  // bool result = safety_algorithm();
  // cout << "Safety algorithm returns " << result;

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
  cout << "STEP 1" << endl;
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
    cout << "STEP 2\n";
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

    cout << "STEP 3\n";
    // STEP 3
    for(j = 0; j < NUMBER_OF_RESOURCES; j++) {
      work[j] += allocation[i][j];
    }
    finish[i] = true;
  }

  cout << "STEP 4\n";
  // STEP 4
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    if (!finish[i]) {
      return false;
    }
  }
  return true;
}

int request_resources(int customer_num, int request[]) {
  // DON'T FORGET, CHECK MUTEX LOCK (SHARED WITH release_resources)
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

  cout << "try allocating resources..." << endl;
  cout << "allocation contains: ";
  for (i = 0; i < NUMBER_OF_RESOURCES; i++)
    cout << allocation[customer_num][i] << " ";
  cout << endl;

  // STEP 4
  bool state_is_safe = safety_algorithm();
  if (!state_is_safe) {
    cout << "Woops! Request would cause unsafe state. Rolling back..." << endl;
    release_resources(customer_num, request);
    return -1;
  }

  // BONUS: CHECK IF CUSTOMER HAS RECEIVED MAX RESOURCES
  // OPTION 1: need[customer_num] is all 0
  // OPTION 2: allocation[customer_num] == maximum[customer_num]

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
int release_resources(int customer_num, int release[]) {
  // DON'T FORGET, CHECK MUTEX LOCK (SHARED WITH request_resources)

  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    available[i] += release[i];
    allocation[customer_num][i] -= release[i];
    need[customer_num][i] += release[i];
  }
  // available = available + request;
  // allocation[customer_num] = allocation[customer_num] - request;
  // need[customer_num] = need[customer_num] + request;
  return 0;
}

/*int main(){
if(request == true){
  cout<<"request approved";
}
else
{
  cout<<"request failed";
}
return 0;

}*/

// TEST CODE FOR INITIALIZING NEED/ALLOCATION/MAXIMUM
// // initialize the maximum
//   for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
//     cout << "What is the maximum resource demand for Customer " << i + 1 << "?\n";
//     for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
//       cout << "Resource " << j + 1 << ": ";
//       cin >> maximum[i][j];
//     }
//   }

//   // initialize the allocation
//   for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
//     cout << "What is the current allocation for Customer " << i + 1 << "?\n";
//     for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
//       cout << "Resource " << j + 1 << ": ";
//       cin >> allocation[i][j];
//     }
//   }

//   // initialize need
//   for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
//     // cout << "What is the current allocation for Customer " << i + 1 << "?\n";
//     for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
//       // cout << "Resource " << j + 1 << ": ";
//       need[i][j] = maximum[i][j] - allocation[i][j];
//     }
//   }