# Assignment 1 - Part 2
For Part 2 of the assignment, we have chosen to design a basic API for a Queue.  
Additional documentation for behavior can be found in the respective .h files.

## Object
**Language:** CwC  
**Interpretation:** Represents the root of the class hierarchy.  
**Behavior:**  
- _equals(Object*)_ -> bool  
- _hash()_ -> size_t

## Queue
**Language:** CwC  
**Superinterface(s):** Object  
**Interpretation:** Represents a collection of Object (e.g., String, Queue). Elements are stored in first-in, first-out (FIFO) order.  
**Behavior:** All virutal methods in Object, plus the following.  
- _dequeue()_ -> Object*  
- _enqueue(Object*)_ -> void
- _peek()_ -> Object*
- _remove_all()_ -> void
- _size()_ -> size_t

The methods dequeue() and remove_all() are intended to be used only when the Queue is not empty (i.e. when size() returns a number greater than 0). Like dequeue(), peek() will return a null pointer if called on an empty Queue. The following methods will mutate the Queue: dequeue(), enqueue(), remove_all().  

## String
For the purposes of this assignment, this class has been included to help convey the expected behavior of Queue through tests (found in test-queue.cpp).  
**Language:** CwC  
**Superinterface(s):** Object  
**Interpretation:** Represents a collection char.  
**State:**  
- _size__ : size_t
- _val__ : char*

**Behavior:** All virutal methods in Object, plus the following.  
- _compare(String*)_ -> size_t
- _conncat(String*)_ -> String*
- _size()_ -> size_t

The method compare() behaves similarly to the C library function strcmp(). Given an identical String, the method will return 0. Otherwise, the method returns a negative number if the implicit parameter alphanumerically preceeds the explicit paramater or a positive number if the converse is true.  
The concat() method will append the given String to end of this String.

## UML Diagram
![UML Diagram](https://github.com/ifteda/CS4500-A1-Part2/blob/master/uml%20diagram.png?raw=true)
