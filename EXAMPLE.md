$ ./main.out 10 5 7
Available array has:
10 5 7
What is the maximum resource demand for Customer 0?
Resource 1: 7
Resource 2: 5
Resource 3: 3
What is the maximum resource demand for Customer 1?
Resource 1: 3
Resource 2: 2
Resource 3: 2
What is the maximum resource demand for Customer 2?
Resource 1: 9
Resource 2: 0
Resource 3: 2
What is the maximum resource demand for Customer 3?
Resource 1: 2
Resource 2: 2
Resource 3: 2
What is the maximum resource demand for Customer 4?
Resource 1: 4
Resource 2: 3
Resource 3: 3
What is the current resource allocation for Customer 0?
Resource 1: 0
Resource 2: 1
Resource 3: 0
What is the current resource allocation for Customer 1?
Resource 1: 2
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 2?
Resource 1: 3
Resource 2: 0
Resource 3: 2
What is the current resource allocation for Customer 3?
Resource 1: 2
Resource 2: 1
Resource 3: 1
What is the current resource allocation for Customer 4?
Resource 1: 0
Resource 2: 0
Resource 3: 2
banker creating thread for customer 0
banker creating thread for customer 1
banker creating thread for customer 2
banker creating thread for customer 3
banker creating thread for customer 4
banker waiting for customers to finish...
customer 0 sleeping for 4 seconds...
customer 1 sleeping for 5 seconds...
customer 2 sleeping for 4 seconds...
customer 3 sleeping for 5 seconds...
customer 4 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 6 4 2
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
need:
7 4 3
1 2 2
6 0 0
0 1 1
4 3 1
available: 3 3 2

customer 0 has released lock.
customer 0 sleeping for 3 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 1 0 0
customer 2 request successful!

allocation:
0 1 0
2 0 0
4 0 2
2 1 1
0 0 2
need:
7 4 3
1 2 2
5 0 0
0 1 1
4 3 1
available: 2 3 2

customer 2 has released lock.
customer 2 sleeping for 5 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: customer 1 0 2
customer 1 3 wants to request resources.
request successful!

allocation:
0 1 0
3 0 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 2 0
5 0 0
0 1 1
4 3 1
available: 1 3 0

customer 1customer 3 has acquired lock.
request for customer 3 contains: 0 1 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 1 0
3 0 2
4 0 2 has released lock.
customer 1 sleeping for 5 seconds...

2 1 1
0 0 2
need:
7 4 3
0 2 0
5 0 0
0 1 1
4 3 1
available: 1 3 0

customer 3 has released lock.
customer 3 sleeping for 7 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 4 1 1
Error: Not enough resources are available.
customer 4 request failed

allocation:
0 1 0
3 0 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 2 0
5 0 0
0 1 1
4 3 1
available: 1 3 0

customer 4 has released lock.
customer 4 sleeping for 6 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 1 3 1
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
3 0 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 2 0
5 0 0
0 1 1
4 3 1
available: 1 3 0

customer 0 has released lock.
customer 0 sleeping for 4 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 5 0 0
Error: Not enough resources are available.
customer 2 request failed

allocation:
0 1 0
3 0 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 2 0
5 0 0
0 1 1
4 3 1
available: 1 3 0

customer 2 has released lock.
customer 2 sleeping for 4 seconds...
customer 1 wants to request resources.
customer 1 has acquired lock.
request for customer 1 contains: 0 2 0
customer 1 request successful!

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 1 has released lock.
customer 1 sleeping for 5 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 2 4 0
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 0 has released lock.
customer 0 sleeping for 4 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 1 1
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 3 has released lock.
customer 3 sleeping for 6 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 0 1 1
Error: Not enough resources are available.
customer 4 request failed

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 4 0 0
Error: Not enough resources are available.
customer 2 request failed

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 2 has released lock.
customer 2 sleeping for 7 seconds...
customer 1 finished!

allocation:
0 1 0
3 2 2
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 1 1 0

customer 1 wants to release resources.
customer 1 has acquired lock.

allocation:
0 1 0
0 0 0
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 4 3 2

customer 1 has released lock.
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 2 3
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 1
0 0 2
need:
7 4 3
0 0 0
5 0 0
0 1 1
4 3 1
available: 4 3 2

customer 0 has released lock.
customer 0 sleeping for 3 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 1 3 1
customer 4 request successful!

allocation:
0 1 0
0 0 0
4 0 2
2 1 1
1 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 1
3 0 0
available: 3 0 1

customer 4 has released lock.
customer 4 sleeping for 3 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 0 1
customer 3 request successful!

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
1 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
3 0 0
available: 3 0 0

customer 3 has released lock.
customer 3 sleeping for 6 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 7 0 3
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
1 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
3 0 0
available: 3 0 0

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 2 0 0
customer 4 request successful!

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
3 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
1 0 0
available: 1 0 0

customer 4 has released lock.
customer 4 sleeping for 4 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 4 0 0
Error: Not enough resources are available.
customer 2 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
3 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
1 0 0
available: 1 0 0

customer 2 has released lock.
customer 2 sleeping for 6 seconds...
customer 4 wants to request resources.
customer 4 has acquired lock.
request for customer 4 contains: 1 0 0
customer 4 request successful!

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
4 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 0 0 0

customer 4 has released lock.
customer 4 sleeping for 4 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 3 0 2
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
4 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 0 0 0

customer 0 has released lock.
customer 0 sleeping for 6 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 1 0
Error: Not enough resources are available.
customer 3 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
4 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 0 0 0

customer 3 has released lock.
customer 3 sleeping for 7 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 3 0 0
Error: Not enough resources are available.
customer 2 request failed

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
4 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 0 0 0

customer 2 has released lock.
customer 2 sleeping for 3 seconds...
customer 4 finished!

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
4 3 3
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 0 0 0

customer 4 wants to release resources.
customer 4 has acquired lock.

allocation:
0 1 0
0 0 0
4 0 2
2 1 2
0 0 0
need:
7 4 3
0 0 0
5 0 0
0 1 0
0 0 0
available: 4 3 3

customer 4 has released lock.
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 4 0 0
customer 2 request successful!

allocation:
0 1 0
0 0 0
8 0 2
2 1 2
0 0 0
need:
7 4 3
0 0 0
1 0 0
0 1 0
0 0 0
available: 0 3 3

customer 2 has released lock.
customer 2 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 3 0 0
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 1 0
0 0 0
8 0 2
2 1 2
0 0 0
need:
7 4 3
0 0 0
1 0 0
0 1 0
0 0 0
available: 0 3 3

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 0 0
customer 3 request successful!

allocation:
0 1 0
0 0 0
8 0 2
2 1 2
0 0 0
need:
7 4 3
0 0 0
1 0 0
0 1 0
0 0 0
available: 0 3 3

customer 3 has released lock.
customer 3 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 0 1 1
customer 0 request successful!

allocation:
0 2 1
0 0 0
8 0 2
2 1 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 1 0
0 0 0
available: 0 2 2

customer 0 has released lock.
customer 0 sleeping for 7 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 0 0 0
customer 2 request successful!

allocation:
0 2 1
0 0 0
8 0 2
2 1 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 1 0
0 0 0
available: 0 2 2

customer 2 has released lock.
customer 2 sleeping for 4 seconds...
customer 3 wants to request resources.
customer 3 has acquired lock.
request for customer 3 contains: 0 1 0
customer 3 request successful!

allocation:
0 2 1
0 0 0
8 0 2
2 2 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 0 1 2

customer 3 has released lock.
customer 3 sleeping for 5 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 1 0 0
Error: Not enough resources are available.
customer 2 request failed

allocation:
0 2 1
0 0 0
8 0 2
2 2 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 0 1 2

customer 2 has released lock.
customer 2 sleeping for 5 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 6 3 2
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 2 1
0 0 0
8 0 2
2 2 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 0 1 2

customer 0 has released lock.
customer 0 sleeping for 7 seconds...
customer 3 finished!

allocation:
0 2 1
0 0 0
8 0 2
2 2 2
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 0 1 2

customer 3 wants to release resources.
customer 3 has acquired lock.

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 3 has released lock.
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 0 0 0
customer 2 request successful!

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 2 has released lock.
customer 2 sleeping for 7 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 6 2 0
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 0 has released lock.
customer 0 sleeping for 6 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 0 0 0
customer 2 request successful!

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 2 has released lock.
customer 2 sleeping for 6 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 5 3 0
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 0 0 0
customer 2 request successful!

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 2 has released lock.
customer 2 sleeping for 3 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 5 2 1
Error: Not enough resources are available.
customer 0 request failed

allocation:
0 2 1
0 0 0
8 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
1 0 0
0 0 0
0 0 0
available: 2 3 4

customer 0 has released lock.
customer 0 sleeping for 5 seconds...
customer 2 wants to request resources.
customer 2 has acquired lock.
request for customer 2 contains: 1 0 0
customer 2 request successful!

allocation:
0 2 1
0 0 0
9 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
0 0 0
0 0 0
0 0 0
available: 1 3 4

customer 2 has released lock.
customer 2 sleeping for 3 seconds...
customer 2 finished!

allocation:
0 2 1
0 0 0
9 0 2
0 0 0
0 0 0
need:
7 3 2
0 0 0
0 0 0
0 0 0
0 0 0
available: 1 3 4

customer 2 wants to release resources.
customer 2 has acquired lock.

allocation:
0 2 1
0 0 0
0 0 0
0 0 0
0 0 0
need:
7 3 2
0 0 0
0 0 0
0 0 0
0 0 0
available: 10 3 6

customer 2 has released lock.
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 3 0 0
customer 0 request successful!

allocation:
3 2 1
0 0 0
0 0 0
0 0 0
0 0 0
need:
4 3 2
0 0 0
0 0 0
0 0 0
0 0 0
available: 7 3 6

customer 0 has released lock.
customer 0 sleeping for 4 seconds...
customer 0 wants to request resources.
customer 0 has acquired lock.
request for customer 0 contains: 4 3 2
customer 0 request successful!

allocation:
7 5 3
0 0 0
0 0 0
0 0 0
0 0 0
need:
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
available: 3 0 4

customer 0 has released lock.
customer 0 sleeping for 6 seconds...
customer 0 finished!

allocation:
7 5 3
0 0 0
0 0 0
0 0 0
0 0 0
need:
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
available: 3 0 4

customer 0 wants to release resources.
customer 0 has acquired lock.

allocation:
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
need:
0 0 0
0 0 0
0 0 0
0 0 0
0 0 0
available: 10 5 7

customer 0 has released lock.

all customers finished, banker is done for the day