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

int main() {
  // take arguments (e.g. 10 5 7, put into available array)
  // initialize the maximum

  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    cout << "What is the maximum resource demand for Customer " << i + 1 << "?\n";
    for (j = 0; j < NUMBER_OF_RESOURCES; j++) {
      cout << "Resource " << j + 1 << ": ";
      cin >> maximum[i][j];
    }
  }

  for (i = 0 ; i < NUMBER_OF_CUSTOMERS; i++){
    for (j = 0 ; j < NUMBER_OF_RESOURCES; j++){
      cout << maximum[i][j] << "\n";
    }
  }

  // for each customer
    // start a thread
      // thread will randomly request resources, constrained by max
      // banker main thread has to know if this will cause deadlock or is unsafe
      // if not unsafe, give resources to thread
      // if thread gets max resources, it exits






  // do Banker's Algorithm
  return 0;
}

// need[i] = [2,1,0]
// work = [5,1,8]
bool compare_arrays(int ary1[], int ary2[]) {
  for (j = 0; j < NUMBER_OF_CUSTOMERS; j++) {
    if (ary1[j] > ary2[j]) {
      return false;
    }
  }
  return true;
}

bool safety_algorithm() {
  // STEP 1
  int work[NUMBER_OF_CUSTOMERS];
  int finish[NUMBER_OF_RESOURCES];
  int i;
  for (i = 0; i < NUMBER_OF_CUSTOMERS; i++) {
    work[i] = available[i];
  }
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    finish[i] = false;
  }

  while(true) {
    // STEP 2
    for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
      bool condition_a = !finish[i]; // finish[i] == false
      bool condition_b = compare_arrays(need[i], work);
      if (condition_a && condition_b) {
        break;
      }
    }
    // GO TO STEP 4 IF i > NUMBER_OF_RESOURCES
    if (i > NUMBER_OF_RESOURCES) {
      break;
    }

    // STEP 3
    for(j = 0; j < NUMBER_OF_RESOURCES; j++) {
      work[j] += allocation[i][j];
    }
    finish[i] = true;
  }

  // STEP 4
  for (i = 0; i < NUMBER_OF_RESOURCES; i++) {
    if (!finish[i]) {
      return false;
    }
  }
  return true;
}