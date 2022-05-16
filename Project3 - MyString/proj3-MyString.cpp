/**
 * file:  proj3-MyString.cpp
 * author:  Xavier Lopez
 * course: CSI 1440 02
 * assignment:  Project 3
 * due date:  2/14/2021
 *
 * date modified:  2/10/2022
 *      - proj3-MyString.cpp was created
 *
 * date modified:  2/11/2022
 *      - defined:
 *            - MyString (default constructor)
 *
 * date modified:  2/13/2022
 *      - defined:
 *            - MyString (const char*)
 *            - ~MyString
 *            - MyString (const MyString&)
 *            - operator =
 *            - operator ==
 *            - operator []
 *            - operator <<
 *
 * date modified:  2/14/2022
 *            - operator +=
 *            - operator +
 *            - getline
 *
 * This file holds the definitions of the functions of the MyString class
 */

#include "proj3-MyString.h"

// Default Constructor
MyString::MyString() {
    this->size = 0;
    this->capacity = 10;
    this->data = new char [this->capacity];
    this->data[0] = '\0';
}

// Constructor with an initialization character string
MyString::MyString(const char *str) {
    this->size = 0;
    this->capacity = 10;
    this->data = new char [this->capacity];

    //Inserts characters into data until a null character is found
    while (str[this->size] != '\0') {
        this->data[this->size] = str[this->size];
        this->size++;

        //If the size is equal or exceeds capacity
        if (this->size >= this->capacity) {
            //Copies data into a temp char*
            char *temp = new char [this->capacity];
            for (int i = 0; i < this->size; i++) {
                temp[i] = this->data[i];
            }

            //Deletes data, reinitialize data with double capacity,
            //then return original data into new data
            delete [] this->data;
            this->capacity *= 2;
            this->data = new char [this->capacity];
            for (int i = 0; i < this->size; i++) {
                this->data[i] = temp[i];
            }
            delete [] temp;
        }
    }
    this->data[this->size] = '\0';
}

// Destructor
MyString::~MyString( ) {
    delete [] this->data;
    this->data = nullptr;
}

// Copy constructor
MyString::MyString(const MyString &s) {
    this->size = s.size;
    this->capacity = s.capacity;
    this->data = new char [this->capacity];

    //Copies data from MyString s to this MyString
    for (int i = 0; i < this->size; i++) {
        this->data[i] = s.data[i];
    }
    this->data[this->size] = '\0';
}

// Overloaded assignment operator, make a copy of MyString object
MyString& MyString::operator = (const MyString& s) {
    //Checks to see if the MyStrings do not have the same memory location
    if (this != &s) {
        //Deletes data of this MyString
        delete [] this->data;

        //Copies MyString object into this MyString
        this->size = 0;
        this->capacity = s.capacity;
        this->data = new char [this->capacity];

        //Copies data from MyString s into this MyString
        while (s.data[this->size] != '\0') {
            this->data[this->size] = s.data[this->size];
            this->size++;
        }
        this->data[this->size] = '\0';
    }
    return *this;
}

// Overloaded equivalence relational operator
bool MyString::operator == (const MyString& s) const {
    int i = 0;
    bool equal = true;
    //Checks up to the null character of either MyString to see if they are
    //equivalent
    while (equal && i <= this->size) {
        if (this->data[i] != s.data[i]) {
            equal = false;
        }
        i++;
    }
    return equal;
}

// Overloaded [ ] should return a char by reference
char& MyString::operator [ ] (int i) {
    return this->data[i];
}

// Overloaded += operator, use to concatenate two MyStrings
void MyString::operator += (const MyString& s) {
    //Checks to see if the memory locations are the same
    if (this != &s) {
        int j = this->size;
        int i = 0;

        //While the null character from MyString s is not read...
        while (s.data[i] != '\0') {
            this->data[j] = s.data[i];
            i++;
            j++;

            //If "this size" equals or exceeds capacity...
            if (j >= this->capacity) {
                //Copies data into a temp char*
                char *temp = new char [this->capacity];
                for (int k = 0; k < j; k++) {
                    temp[k] = this->data[k];
                }

                //Deletes data, reinitialize data with double capacity,
                //then return original data into new data
                delete [] this->data;
                this->capacity *= 2;
                this->data = new char [this->capacity];
                for (int k = 0; k < j; k++) {
                    this->data[k] = temp[k];
                }
                delete [] temp;
            }
        }
        this->size = j;
        this->data[this->size] = '\0';
    }
    //If the same strings are added...
    else {
        //Copies data into a temp char* and remembers original size
        int initSize = this->size;
        char *temp = new char [this->capacity];
        for (int i = 0; i < initSize; i++) {
            temp[i] = this->data[i];
        }

        //Deletes data, reinitialize data with double capacity,
        //then return original data into new data twice
        delete [] this->data;
        this->capacity *= 2;
        this->data = new char [this->capacity];
        for (int i = 0; i < initSize; i++) {
            this->data[i] = temp[i];
        }
        for (int i = 0; i < initSize; i++) {
            this->data[this->size] = temp[i];
            this->size++;
        }
        this->data[this->size] = '\0';
        delete [] temp;
    }
}

// Create a new MyString object that is the concatenation of two MyString objects
MyString MyString::operator + (const MyString& s) const {
    MyString temp(*this);
    temp += s;
    return temp;
}

// Reads an entire line from an istream. Lines are terminated with delimit which is newline
// ‘\n’ by default
void MyString::getline(istream& input, char delimit) {
    char c;
    //Changes char c to not be delimit initiallly
    if (delimit == '\n') {
        c = '\0';
    }
    else {
        c = '\n';
    }
    int i = 0;

    //While we read a character from istream and c is not the delimit...
    while (input.get(c) && c != delimit) {
        this->data[i] = c;
        i++;

        //Checks to see if the "size" is greater than capacity
        if (i >= this->capacity) {
            //Copies data into a temp char*
            char *temp = new char [this->capacity];
            for (int j = 0; j < i; j++) {
                temp[j] = this->data[j];
            }

            //Deletes data, reinitialize data with double capacity,
            //then return original data into new data
            delete [] this->data;
            this->capacity *= 2;
            this->data = new char [this->capacity];
            for (int j = 0; j < i; j++) {
                this->data[j] = temp[j];
            }
            delete [] temp;
        }
    }
    this->size = i;
    this->data[this->size] = '\0';

    //If the size is less 25% of the capacity...
    while (this->size * 4 < this->capacity && this->capacity != 10) {
        //Copies the data into a temp char*
        char *temp = new char [this->capacity];
        for (int j = 0; j < this->size; j++) {
            temp[j] = this->data[j];
        }

        //Deletes data, reinitialize data with half capacity,
        //then return original data into new data
        delete [] this->data;
        this->capacity /= 2;
        this->data = new char [this->capacity];
        for (int j = 0; j < this->size; j++) {
            this->data[j] = temp[j];
        }
        delete [] temp;
    }
}

// Return the length of the string
int MyString::length( ) const {
    return this->size;
}

// Overloaded insertion operator
ostream& operator<< (ostream& c, MyString& s) {
    for (int i = 0; i < s.size; i++) {
        c << s.data[i];
    }
    return c;
}
