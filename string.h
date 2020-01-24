// lang:: CwC

#pragma once

#include <string.h>

/**
 * String: This class represents a collection of char
 * Implements Object
 */
class String : public Object {
public:
    size_t size_; // the number of characters
    char* val_; // the characters

    /**
     * Default Constructor
     */
    String() {
        size_ = 0;
        val_ = new char[size_];
    }

    /**
     * Constructor
     */
    String(char* c) {
        size_ = strlen(c);
        val_ = new char[size_];
        for (size_t i = 0; i < size_; i++) {
            val_[i] = c[i];
        }
    }

    /**
     * Destructor
     */
    ~String() {
        delete[] val_;
    }

    /** 
     * Compares the given Object with this one for equality
     * Overridden from Object
     * @arg obj Object against which to compare
     */
    bool equals(Object* obj) {
        if (obj == nullptr) {
            return false;
        }

        String* s = dynamic_cast<String*>(obj);

        if (s == nullptr) {
            return false;
        }

        return strcmp(val_, s->val_) == 0;
    }

    /**
     * Returns the hash code value for this String
     * Overridden from Object
     */
    size_t hash() {
        size_t h = 0;
        for (int i = 0; i < size_; i++) {
            h += (int) val_[i];
        }
        return h;
    }

    /**
     * Returns the number of characters in this String
     */
    size_t size() {
        return size_;
    }

    /**
     * Compares the given String to this String
     * Returns 0 if they are equal,
     * <0 if the first unmatched character has a lower ASCII value in this String than in the given String,
     * or >0 if it has a higher ASCII value in this String than in the given String
     * @arg str String against which to compare
     */
    size_t compare(String* str) {
        return strcmp(val_, str->val_);
    }

    /** 
     * Concatenates the given String at the end of this String
     * Returns the result of the concatenation
     * @arg str String to concatenate
     */
    String* concat(String* str) {
        size_t newSize = size_ + str->size();
        char* newString = new char[size_];
        for (int i = 0; i < size_; i++) {
            newString[i] = val_[i];
        }
        for (int i = size_; i < newSize; i++) {
            newString[i] = str->val_[i - size_];
        }
        size_ = newSize;
        val_ = newString;
    }

    /**
     * Returns this String as a char*
     * Inherited from Object
     */
    char* to_string() {
        return val_;
    }
};