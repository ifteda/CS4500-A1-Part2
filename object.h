// lang:: CwC

#pragma once

/**
 * Object: This class represents the root of the class hierarchy
 */
class Object {
public:

    /**
     * Constructor
     */
    Object();

    /**
     * Destructor
     */
    virtual ~Object();

    /** 
     * Compares the given Object with this one for equality
     * Subclass resonsibility
     * @arg obj Object against which to compare
     */
    virtual bool equals(Object* obj);

    /** 
     * Returns the hash code value for this Object
     * Subclass responsibility
     */
    virtual size_t hash();

};