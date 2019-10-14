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
#include "main.h"

using namespace std;

int const NUMBER_OF_CUSTOMERS = 1; // n in the textbook
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

// printing maximum
  // for (i = 0 ; i < NUMBER_OF_CUSTOMERS; i++){
  //   for (j = 0 ; j < NUMBER_OF_RESOURCES; j++){
  //     cout << maximum[i][j] << "\n";
  //   }
  // }

  // for each customer
    // start a thread
      // thread will randomly request resources, constrained by max
      // banker main thread has to know if this will cause deadlock or is unsafe
      // if not unsafe, give resources to thread
      // if thread gets max resources, it exits

  cout << "Run safety algorithm...\n";
  bool result = safety_algorithm();
  cout << "Safety algorithm returns " << result;

  return 0;
}

// need[i] = [2,1,0]
// work = [5,1,8]
bool work_covers_need(int need[], int work[]) {
  for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
    // cout << "For resource " << j + 1 <<", need is " << need[j] << " and work is " << work[j] << "\n";
    if (need[j] > work[j]) {
      return false;
    }
  }
  return true;
}

bool safety_algorithm() {
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
      bool condition_b = work_covers_need(need[i], work);
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