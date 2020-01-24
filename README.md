# Assignment 1 - Part 2
For Part 2 of the assignment, we have chosen to design a basic API for a Queue.  
Additional documentation for behavior can be found in the respective .h files.

## Object
**Language:** CwC  
**Interpretation:** Represents the root of the class hierarchy.  
**Behavior:**  
- _equals(Object*)_ -> bool  
- _hash()_ -> size_t
- _to_string()_ -> char*

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

## UML Diagram
![UML Diagram](https://github.com/ifteda/CS4500-A1-Part2/blob/master/uml%20diagram.png?raw=true)