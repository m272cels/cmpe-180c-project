int request_resources(int customer_num, int request[]);

int release_resources(int customer_num, int release[]);

bool less_than_or_equals_arrays(int left_array[], int right_array[]);

bool safety_algorithm();

int allocate_resources(int customer_num, int allocate[]);

int deallocate_resources(int customer_num, int allocate[]);

void * run_customer_thread(void * arg);

void print_everything();

namespace bank_mutex {
  void acquire();

  void release();
}