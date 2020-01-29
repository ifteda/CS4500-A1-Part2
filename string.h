// lang:: CwC

#pragma once

#include <string.h>

/**
 * String: This class represents a collection of char
 * Implements Object
 */
class String : public Object {
public:

    /**
     * Default Constructor
     */
    String();

    /**
     * Constructor
     */
    String(char* c);

    /**
     * Destructor
     */
    ~String();

    /** 
     * Compares the given Object with this one for equality
     * Overridden from Object
     * @arg obj Object against which to compare
     */
    bool equals(Object* obj);

    /**
     * Returns the hash code value for this String
     * Overridden from Object
     */
    size_t hash();

    /**
     * Returns the number of characters in this String
     */
    size_t size();

    /**
     * Compares the given String to this String
     * Returns 0 if they are equal,
     * <0 if the first unmatched character has a lower ASCII value in this String than in the given String,
     * or >0 if it has a higher ASCII value in this String than in the given String
     * @arg str String against which to compare
     */
    size_t compare(String* str);

    /** 
     * Concatenates the given String at the end of this String
     * Returns the result of the concatenation
     * @arg str String to concatenate
     */
    String* concat(String* str);

    /**
     * Returns this String as a char*
     * Inherited from Object
     */
    char* to_string();
    
};