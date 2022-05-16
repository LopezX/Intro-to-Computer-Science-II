/**
 * file: proj10-MyVector.h
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 10 - Queues
 * due date: 5/2/2022
 *
 * date modified: 4/27/2022
 *      - file was created
 *
 * date modified: 4/30/2022
 *      - MyVector class was made
 *
 * date modified: 5/1/2022
 *      - updated shiftLeft
 *      - changed private to protected
 *
 * Header file for the MyVector class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_MYVECTOR_H
#define PROJECT_10___QUEUES_PROJ10_MYVECTOR_H

#include "proj10-ContainerIfc.h"

template <class T>
class MyVector : public ContainerIfc<T> {
public:
    /**
     * MyVector
     *
     * class constructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    MyVector ();

    /**
     * ~MyVector
     *
     * Class deconstructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~MyVector ();

    /**
     * MyVector
     *
     * Class copy constructor
     *
     * Parameters:
     *      v: a const MyVector object
     *
     * Output:
     *      return: none
     *      reference parameters: c
     *      stream: none
     */
    MyVector (const MyVector&);

    /**
     * operator =
     *
     * overloaded assignment operator
     *
     * Parameters:
     *     v: a const MyVector object
     *
     * Output:
     *      return: a reference to self
     *      reference parameters: v
     *      stream: none
     */
    MyVector<T>& operator = (const MyVector&);

    /**
     * pushFront
     *
     * add data element e to the front of the vector
     *
     * Parameters:
     *     e: a T variable
     *
     * Output:
     *      return: a reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyVector<T>& pushFront(T);

    /**
     * pushBack
     *
     * store data element e to the end of the vector
     *
     * Parameters:
     *     e: a T variable
     *
     * Output:
     *      return: a reference to self
     *      reference parameters: none
     *      stream: none
     */
    MyVector<T>& pushBack(T);

    /**
     * popFront
     *
     * removes a data element from the front of the
     * data structure (MyVector)
     *
     * Parameters:
     *     e: a T variable
     *
     * Output:
     *      return: a reference to self
     *      reference parameters: e
     *      stream: none
     */
    MyVector<T>& popFront(T&);

    /**
     * popBack
     *
     * removes a data element from the rear (end) of the
     * data structure (MyVector)
     *
     * Parameters:
     *     e: a T variable
     *
     * Output:
     *      return: a reference to self
     *      reference parameters: e
     *      stream: none
     */
    MyVector<T>& popBack(T&);

    /**
     * front
     *
     * returns a copy of the first data item in the MyVector
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T  front();

    /**
     * back
     *
     * returns a copy of the last data item in MyVector
     *
     * Parameters:
     *     in:   input stream
     *
     * Output:
     *      return: none
     *      reference parameters: in
     *      stream: none
     */
    T  back();

    /**
     * operator []
     *
     * returns a reference to data element n in MyVector
     *
     * Parameters: n
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T&  operator [](int);

    /**
     * getSize
     *
     * returns the number fo elements currently in the MyVector
     *
     * Parameters: none
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    int getSize();

    /**
     * isEmpty
     *
     * returns state information about the list
     *
     * Parameters: none
     *
     * Output:
     *      return: bool
     *      reference parameters: none
     *      stream: none
     */
    bool isEmpty();

    /**
     * erase
     *
     * erases a vector
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void erase();

protected:
    T  *data;
    int size;
    int capacity;

    /**
     * grow
     *
     * increases the capacity of data by doubling the previous
     * value and allocating the appropriate memory for data
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void grow();

    /**
     * shiftRight
     *
     * shifts all values in the array one space to the right
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void shiftRight();

    /**
     * shiftleft
     *
     * shifts all values in the array one space to the left
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void shiftLeft();
};

template <class T>
MyVector<T>::MyVector () {
    this->size = 0;
    this->capacity = 10;
    this->data = new T [this->capacity];
}

template <class T>
MyVector<T>::~MyVector () {
    delete [] this->data;
}

template <class T>
MyVector<T>::MyVector (const MyVector& v) {
    this->size = 0;
    this->capacity = 10;
    this->data = new T [this->capacity];
    for (int i = 0; i < v.size; i++) {
        if (this->size >= this->capacity) {
            this->grow();
        }
        this->data[i] = v.data[i];
        this->size++;
    }
}

template <class T>
MyVector<T>& MyVector<T>::operator = (const MyVector& v) {
    if (this != &v) {
        this->size = 0;
        this->capacity = 10;
        delete [] this->data;
        this->data = new T [this->capacity];
        for (int i = 0; i < v.size; i++) {
            if (this->size >= this->capacity) {
                this->grow();
            }
            this->data[i] = v.data[i];
            this->size++;
        }
    }
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushFront(T e) {
    this->shiftRight();
    this->data[0] = e;
    this->size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::pushBack(T e) {
    if (this->size >= this->capacity) {
        this->grow();
    }
    this->data[this->size] = e;
    this->size++;
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popFront(T& e) {
    if (this->isEmpty()) {
        throw (BADINDEX());
    }
    e = this->data[0];
    this->size--;
    this->shiftLeft();
    return *this;
}

template <class T>
MyVector<T>& MyVector<T>::popBack(T& e) {
    if (this->isEmpty()) {
        throw (BADINDEX());
    }
    e = this->data[this->size];
    this->size--;
    return *this;
}

template <class T>
T  MyVector<T>::front() {
    if (this->isEmpty()) {
        throw (BADINDEX());
    }
    return this->data[0];
}

template <class T>
T  MyVector<T>::back() {
    if (this->isEmpty()) {
        throw (BADINDEX());
    }
    return this->data[this->size - 1];
}

template <class T>
T&  MyVector<T>::operator [](int n) {
    if (n >= this->size || this->isEmpty()) {
        throw (BADINDEX());
    }
    return this->data[n];
}

template <class T>
int MyVector<T>::getSize() {
    return this->size;
}

template <class T>
bool MyVector<T>::isEmpty() {
    bool empty = true;
    if (this->size > 0) {
        empty = false;
    }
    return empty;
}

template <class T>
void MyVector<T>::erase() {
    delete [] this->data;
    this->data = new T [this->capacity];
    this->size = 0;
}

template <class T>
void MyVector<T>::grow() {
    this->capacity *= 2;
    T *temp = new T [this->capacity];
    for (int i = 0; i < this->size; i++) {
        temp[i] = this->data[i];
    }
    delete [] this->data;
    this->data = new T [this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = temp[i];
    }
    delete [] temp;
}

template <class T>
void MyVector<T>::shiftRight() {
    if (this->size >= this->capacity) {
        this->grow();
    }
    for (int i = this->size - 1; i >= 0; i--) {
        this->data[i + 1] = this->data[i];
    }
}

template <class T>
void MyVector<T>::shiftLeft() {
    for (int i = 0; i < this->size; i++) {
        this->data[i] = this->data[i + 1];
    }
}

#endif //PROJECT_10___QUEUES_PROJ10_MYVECTOR_H
