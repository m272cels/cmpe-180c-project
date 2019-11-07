$ ./main.out 10 5 7
Available array has:
10 5 7
What is the maximum resource demand for Customer 0?
Resource 1: 4
Resource 2: 4
Resource 3: 4
What is the maximum resource demand for Customer 1?
Resource 1: 4
Resource 2: 4
Resource 3: 4
What is the maximum resource demand for Customer 2?
Resource 1: 4
Resource 2: 4
Resource 3: 4
What is the maximum resource demand for Customer 3?
Resource 1: 4
Resource 2: 4
Resource 3: 4
What is the maximum resource demand for Customer 4?
Resource 1: 4
Resource 2: 4
Resource 3: 4
What is the current resource allocation for Customer 0?
Resource 1: 0
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 1?
Resource 1: 0
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 2?
Resource 1: 0
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 3?
Resource 1: 0
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 4?
Resource 1: 0
Resource 2: 0
Resource 3: 0
banker creating thread for customer 0
banker creating thread for customer 1
banker creating thread for customer 2
banker creating thread for customer 3
banker creating thread for customer 4
banker waiting for customers to finish...
customer 0 sleeping for 6 seconds...
customer 1 sleeping for 3 seconds...
customer customer 3 sleeping for 6 seconds...
customer 4 sleeping for 5 seconds...
2 sleeping for 3 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
customer 1 wants to request resources.
request for customer 2 contains: 2 3 0
customer 2 request successful!

allocation:
0 0 0
0 0 0
2 3 0
0 0 0
0 0 0
need:
4 4 4
4 4 4
2 1 4
4 4 4
4 4 4
available: 8 2 7

customer 2 has released lock.
customer 2 sleeping for 5 seconds...
customer 1 has acquired lock.
request for customer 1 contains: 0 3 0
Error: Not enough resources are available.
customer 1 request failed

allocation:
0 0 0
0 0 0
2 3 0
0 0 0
0 0 0
need:
4 4 4
4 4 4
2 1 4
4 4 4
4 4 4
available: 8 2 7

customer 1 has released lock.
customer 1 sleeping for 7 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 2 2 1
customer 4 request failed

allocation:
0 0 0
0 0 0
2 3 0
0 0 0
0 0 0
need:
4 4 4
4 4 4
2 1 4
4 4 4
4 4 4
available: 8 2 7

customer 4 has released lock.
customer 4 sleeping for 4 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 2 1customer  3 wants to request resources.
0
customer 0 request successful!

allocation:
2 1 0
0 0 0
2 3 0
0 0 0
0 0 0
need:
2 3 4
4 4 4
2 1 4
4 4 4
4 4 4
available: 6 1 7

customer 0 has released lock.
customer customer 0 sleeping for 33 has acquired lock. seconds...

request for customer 3 contains: 4 1 3
customer 3 request failed

allocation:
2 1 0
0 0 0
2 3 0
0 0 0
0 0 0
need:
2 3 4
4 4 4
2 1 4
4 4 4
4 4 4
available: 6 1 7

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 2 0 1
customer 2 request successful!

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
0 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
4 4 4
available: 4 1 6

customer 2 has released lock.
customer 2 sleeping for 4 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 2 0 0
customer 4 request successful!

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
2 4 4
available: 2 1 6

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 2 3 0
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
2 4 4
available: 2 1 6

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 3 2 4
Error: Not enough resources are available.
customer 1 request failed

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
2 4 4
available: 2 1 6

customer 1 has released lock.
customer 1 sleeping for 6 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 1 4
customer 3 request failed

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
2 4 4
available: 2 1 6

customer 3 has released lock.
customer 3 sleeping for 4 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 2 4 3
Error: Not enough resources are available.customer
customer 2 wants to request resources.4 request failed

allocation:
2 1 0
0 0 0
4 3 1
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 1 3
4 4 4
2 4 4
available: 2 1 6

customer 4 has released lock.
customer 4 sleeping for 3 seconds...

customer 2 has acquired lock.
request for customer 2 contains: 0 1 2
customer 2 request successful!

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 0 1
4 4 4
2 4 4
available: 2 0 4

customer 2 has released lock.
customer 2 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 2 4
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
2 0 0
need:
2 3 4
4 4 4
0 0 1
4 4 4
2 4 4
available: 2 0 4

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 2 0 1
customer 4 request successful!

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 1
4 4 4
0 4 3
available: 0 0 3

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 2 3
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 1
4 4 4
0 4 3
available: 0 0 3

customer 3 has released lock.
customer 3 sleeping for 4 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 3 2 0
Error: Not enough resources are available.
customer 1 request failed

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 1
4 4 4
0 4 3
available: 0 0 3

customer 1 has released lock.
customer 1 sleeping for 7 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 2 0
Error: Not enough resources are available.
customer 4 request failed

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 1
4 4 4
0 4 3
available: 0 0 3

customer 4 has released lock.
customer 4 sleeping for 4 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 2customer  2 2
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
0 0 0
4 4 3
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 1
4 4 4
0 4 3
available: 0 0 3

customer 0 has released lock.
customer 0 sleeping for 6 seconds...
2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 0 0 1
customer 2 request successful!

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 3
available: 0 0 2

customer 2 has released lock.
customer 2 sleeping for 6 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 1 4
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 1
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 3
available: 0 0 2

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 0 1
customer 4 request successful!

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 4 has released lock.
customer 4 sleeping for 7 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 1 3 4
Error: Not enough resources are available.
customer 1 request failed

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 1 has released lock.
customer 1 sleeping for 5 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 2 4
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 3 has released lock.
customer 3 sleeping for 4 seconds...
customer customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 1 4
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
0 0 0
4 4 4
2 finished!

allocation:
2 1 0
0 0 0
4 4 4
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 2 wants to release resources.
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 0 has released lock.
customer 0 sleeping for 7 seconds...
customer 2 has acquired lock.

allocation:
2 1 0
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 3 4
4 4 4
0 0 0
4 4 4
0 4 2
available: 4 4 5

customer 2 has released lock.
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 3 1 4
customer 1 request successful!

allocation:
2 1 0
3 1 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
1 3 0
0 0 0
4 4 4
0 4 2
available: 1 3 1

customer 1 has released lock.
customer 1 sleeping for 7 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 3 0 2
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
3 1 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
1 3 0
0 0 0
4 4 4
0 4 2
available: 1 3 1

customer 3 has released lock.
customer 3 sleeping for 7 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 0 0
customer 4 request successful!

allocation:
2 1 0
3 1 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
1 3 0
0 0 0
4 4 4
0 4 2
available: 1 3 1

customer 4 has released lock.
customer 4 sleeping for 6 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 2 2 4
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
3 1 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
1 3 0
0 0 0
4 4 4
0 4 2
available: 1 3 1

customer 0 has released lock.
customer 0 sleeping for 7 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 1 2 0
customer 1 request successful!

allocation:
2 1 0
4 3 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 1 0
0 0 0
4 4 4
0 4 2
available: 0 1 1

customer 1 has released lock.
customer 1 sleeping for 6 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 4 3 3
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
4 3 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 1 0
0 0 0
4 4 4
0 4 2
available: 0 1 1

customer 3 has released lock.
customer 3 sleeping for 6 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 0 2
Error: Not enough resources are available.
customer 4 request failed

allocation:
2 1 0
4 3 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 1 0
0 0 0
4 4 4
0 4 2
available: 0 1 1

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 4 2
Error: Not enough resources are available.
customer 4 request failed

allocation:
2 1 0
4 3 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 1 0
0 0 0
4 4 4
0 4 2
available: 0 1 1

customer 4 has released lock.
customer 4 sleeping for 4 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 1 0 3
Error: Not enough resources are available.
customer 0 request failed

allocation:
2 1 0
4 3 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 1 0
0 0 0
4 4 4
0 4 2
available: 0 1 1

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 0 1 0
customer 1 request successful!

allocation:
2 1 0
4 4 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 0 0
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 1 has released lock.
customer 1 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 4 3 0
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 1 0
4 4 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 0 0
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 3 has released lock.
customer 3 sleeping for 3 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 1
Error: Not enough resources are available.
customer 4 request failed

allocation:
2 1 0
4 4 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 0 0
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 4 has released lock.
customer 4 sleeping for 7 seconds...
customer 1 finished!

allocation:
2 1 0
4 4 4
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 0 0
0 0 0
4 4 4
0 4 2
available: 0 0 1

customer 1 wants to release resources.
customer 1 has acquired lock.

allocation:
2 1 0
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 3 4
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 4 5

customer 1 has released lock.
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 3 2
customer 0 request successful!

allocation:
2 4 2
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 0 2
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 1 3

customer 0 has released lock.
customer 0 sleeping for 4 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 2 4 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 4 2
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 0 2
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 1 3

customer 3 has released lock.
customer 3 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 2 2 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
2 4 2
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 0 2
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 1 3

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 0 2
customer 0 request successful!

allocation:
2 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 1 1

customer 0 has released lock.
customer 0 sleeping for 3 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 0 2
Error: Not enough resources are available.
customer 4 request failed

allocation:
2 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
2 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 4 1 1

customer 4 has released lock.
customer 4 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 1 0 0
customer 0 request successful!

allocation:
3 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
1 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 3 1 1

customer 0 has released lock.
customer 0 sleeping for 6 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 4 4
Error: Not enough resources are available.
customer 3 request failed

allocation:
3 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
1 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 3 1 1

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 2 2
Error: Not enough resources are available.
customer 4 request failed

allocation:
3 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
1 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 3 1 1

customer 4 has released lock.
customer 4 sleeping for 5 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 1 0 0
customer 0 request successful!

allocation:
4 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
0 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 2 1 1

customer 0 has released lock.
customer 0 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 1 4 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
4 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
0 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 2 1 1

customer 3 has released lock.
customer 3 sleeping for 6 seconds...
customer 0 finished!

allocation:
4 4 4
0 0 0
0 0 0
0 0 0
4 0 2
need:
0 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 2 1 1

customer 0 wants to release resources.
customer 0 has acquired lock.

allocation:
0 0 0
0 0 0
0 0 0
0 0 0
4 0 2
need:
0 0 0
0 0 0
0 0 0
4 4 4
0 4 2
available: 6 5 5

customer 0 has released lock.
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 1
customer 4 request successful!

allocation:
0 0 0
0 0 0
0 0 0
0 0 0
4 1 3
need:
0 0 0
0 0 0
0 0 0
4 4 4
0 3 1
available: 6 4 4

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 4 1 3
customer 3 request successful!

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 1 3
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 3 1
available: 2 3 1

customer 3 has released lock.
customer 3 sleeping for 7 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 1
customer 4 request successful!

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 2 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 2 0
available: 2 2 0

customer 4 has released lock.
customer 4 sleeping for 6 seconds...
customer customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 0 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 2 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 2 0
available: 2 2 0

customer 3 has released lock.
customer 3 sleeping for 4 seconds...
4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 0
customer 4 request successful!

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 3 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 1 0
available: 2 1 0

customer 4 has released lock.
customer 4 sleeping for 5 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 3 0
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 3 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 1 0
available: 2 1 0

customer 3 has released lock.
customer 3 sleeping for 3 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 0
customer 4 request successful!

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 4 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 0 0
available: 2 0 0

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 0 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 4 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 0 0
available: 2 0 0

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 4 finished!

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
4 4 4
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 0 0
available: 2 0 0

customer 4 wants to release resources.
customer 4 has acquired lock.

allocation:
0 0 0
0 0 0
0 0 0
4 1 3
0 0 0
need:
0 0 0
0 0 0
0 0 0
0 3 1
0 0 0
available: 6 4 4

customer 4 has released lock.
ERROR: THREAD JOIN FAILED FOR CUSTOMER 4

all customers finished, banker is done for the day