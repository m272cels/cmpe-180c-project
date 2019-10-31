$ ./main.out 5 5 5
Available array has:
5 5 5
What is the maximum resource demand for Customer 0?
Resource 1: 3
Resource 2: 3
Resource 3: 3
What is the maximum resource demand for Customer 1?
Resource 1: 3
Resource 2: 3
Resource 3: 3
What is the current resource allocation for Customer 0?
Resource 1: 0
Resource 2: 0
Resource 3: 0
What is the current resource allocation for Customer 1?
Resource 1: 0
Resource 2: 0
Resource 3: 0
banker creating thread for customer 0
banker creating thread for customer 1
max for customer 0 is [3, 3, 3]
max for customer 1 is [3, 3, banker waiting for customers to finish...
3request for customer 0 contains: 2 1 2
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
]
request for customer 1 contains: 1 3 0
customer 1 wants to request resources.
request successful!customer

allocation:
1 has acquired lock.
2 enter safety algorithm...1
Breaking out now, either customers all finished or no more customers can be finished.
customer 21 has released lock.
request successful!

allocation:
2 1 2
1 3 0
need:
1 2 1
2 0 3
available: 2 1 3


1 3 0
need:
1 2 1
2 0 3
available: 2 1 3

request for customer 0 contains: 0 2 0
customer 0 wants to request resources.
customer 0 has acquired lock.
Error: Not enough resources are available.customer 0 has released lock.
request failed

allocation:
2 1 2
1 3 0
need:
1 2 1
2 0 3
available: 2 1 3

request for customer 1 contains: 0 0 2
customer 1 wants to request resources.
customer 1 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 1 has released lock.
request successful!

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

request for customer 1 contains: 0 0 0
customer 1 wants to request resources.
customer 1 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 1 has released lock.
request successful!

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

request for customer 0 contains: 0 0 1
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
Woops! Request would cause unsafe state. Rolling back...

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

customer 0 has released lock.
request failed

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

request for customer 0 contains: 1 2 0
customer 0 wants to request resources.
customer 0 has acquired lock.
Error: Not enough resources are available.customer 0 has released lock.
request failed

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

request for customer 0 contains: 0 0 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
2 1 2
1 3 2
need:
1 2 1
2 0 1
available: 2 1 1

request for customer 1 contains: 0 0 1
customer 1 wants to request resources.
customer 1 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 1 has released lock.
request successful!

allocation:
2 1 2
1 3 3
need:
1 2 1
2 0 0
available: 2 1 0

request for customer 1 contains: 2 0 0
customer 1 wants to request resources.
customer 1 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 1 has released lock.
request successful!

allocation:
2 1 2
3 3 3
need:
1 2 1
0 0 0
available: 0 1 0

request for customer 0 contains: 1 1 0
customer 0 wants to request resources.
customer 0 has acquired lock.
Error: Not enough resources are available.customer 0 has released lock.
request failed

allocation:
2 1 2
3 3 3
need:
1 2 1
0 0 0
available: 0 1 0

finished!

allocation:
2 1 2
3 3 3
need:
1 2 1
0 0 0
available: 0 1 0

customer 1 wants to release resources.
customer 1 has acquired lock.
customer 1 has released lock.

allocation:
2 1 2
0 0 0
need:
1 2 1
0 0 0
available: 3 4 3

request for customer 0 contains: 0 1 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
2 2 2
0 0 0
need:
1 1 1
0 0 0
available: 3 3 3

request for customer 0 contains: 1 0 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 2 2
0 0 0
need:
0 1 1
0 0 0
available: 2 3 3

request for customer 0 contains: 0 1 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 3 2
0 0 0
need:
0 0 1
0 0 0
available: 2 2 3

request for customer 0 contains: 0 0 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 3 2
0 0 0
need:
0 0 1
0 0 0
available: 2 2 3

request for customer 0 contains: 0 0 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 3 2
0 0 0
need:
0 0 1
0 0 0
available: 2 2 3

request for customer 0 contains: 0 0 0
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 3 2
0 0 0
need:
0 0 1
0 0 0
available: 2 2 3

request for customer 0 contains: 0 0 1
customer 0 wants to request resources.
customer 0 has acquired lock.
enter safety algorithm...
Breaking out now, either customers all finished or no more customers can be finished.
customer 0 has released lock.
request successful!

allocation:
3 3 3
0 0 0
need:
0 0 0
0 0 0
available: 2 2 2

finished!

allocation:
3 3 3
0 0 0
need:
0 0 0
0 0 0
available: 2 2 2

customer 0 wants to release resources.
customer 0 has acquired lock.
customer 0 has released lock.

allocation:
0 0 0
0 0 0
need:
0 0 0
0 0 0
available: 5 5 5


all customers finished, banker is done for the day