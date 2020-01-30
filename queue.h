// lang:: CwC

#pragma once

#include <stdlib.h>

/**
 * Queue: This class represents a collection of Object
 *  stored in first-in, first-out (FIFO) order.
 */
class Queue : public Object {
public:
    /**
     * Constructor
     */
    Queue();

    /**
     * Destructor
     */
    ~Queue();

    /** 
     * Compares the given Object with this Queue for equality
     * Inherited from Object
     * @arg obj Object against which to compare
     */
    bool equals(Object* obj);

    /** 
     * Returns the hash code value for this Queue
     * Inherited from Object
     */
    size_t hash();

    /**
     * Returns the number of elements in this Queue
     */
    size_t size();

    /**
     * Adds the given Object to the end of this Queue
     */
    void enqueue(Object* obj);

    /**
     * Removes and returns the element at the head of this Queue
     * Returns nullptr if this Queue is empty
     */
    Object* dequeue();
    
    /**
     * Revtrieves the element at the head of this Queue without removal
     * Returns nullptr if this Queue is empty
     */
    Object* peek();

    /**
     * Removes all elements in this Queue
     */
    void remove_all();
};