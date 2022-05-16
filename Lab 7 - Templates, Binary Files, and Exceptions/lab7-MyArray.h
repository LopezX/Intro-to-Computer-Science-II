//
// Created by xslop on 4/4/2022.
//

#ifndef LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_MYARRAY_H
#define LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_MYARRAY_H

#include "lab7-ContainerIfc.h"
#include <sstream>

template <class T>
class MyArray : public ContainerIfc<T> {
private:
    int capacity;
    int size;
    T *data;

public:
    MyArray();
    ~MyArray();
    MyArray( const MyArray &);
    MyArray& operator = ( const MyArray &);

    void writeObject( ostream & );
    void readObject( istream & );
    MyArray<T>& pushBack(T);
    MyArray<T>& popBack(T &);
    int getSize();
    bool isEmpty();
    T& operator [] (int);
    string toString();
};

template <class T>
MyArray<T>::MyArray() {
    this->size = 0;
    this->capacity = 5;
    this->data = new T [this->capacity];
}

template <class T>
MyArray<T>::~MyArray() {
    delete [] data;
}

template <class T>
MyArray<T>::MyArray( const MyArray &a) {
    this->size = a.size;
    this->capacity = a.capacity;
    this->data = new T [this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->data[i] = a.data[i];
    }
}

template <class T>
MyArray<T>& MyArray<T>::operator = ( const MyArray &a) {
    if (this != &a) {
        this->size = a.size;
        this->capacity = a.capacity;
        delete [] this->data;
        this->data = new T [this->capacity];
        for (int i = 0; i < this->size; i++) {
            this->data[i] = a.data[i];
        }
    }
    return *this;
}


template <class T>
void MyArray<T>::writeObject( ostream &out ) {
    int x;

    x = this->size;
    out.write((char*)&x, sizeof(int));


    x = this->capacity;
    out.write((char*)&x, sizeof(int));

    for (int i = 0; i < this->size; i++) {
        x = this->data[i];
        out.write((char *) &x, sizeof(int));
    }
}

template <class T>
void MyArray<T>::readObject( istream &in ) {
    int x;

    in.read((char*)&x, sizeof(int));
    this->size = x;

    in.read((char*)&x, sizeof(int));
    this->capacity = x;

    delete [] this->data;
    this->data = new T [this->capacity];
    for (int i = 0; i < this->size; i++) {
        in.read((char *) &x, sizeof(int));
        this->data[i] = x;
    }
}

template <class T>
MyArray<T>& MyArray<T>::pushBack(T e) {
    if (this->size >= this->capacity) {
        this->capacity += 5;
        T *temp = new T [this->capacity];
        for (int i = 0; i < this->size; i++) {
            temp[i] = this->data[i];
        }
        delete [] this->data;
        this->data = temp;
    }
    this->data[this->size] = e;
    this->size++;
    return *this;
}

template <class T>
MyArray<T>& MyArray<T>::popBack(T &e) {
    if ( ( this->size * 4 < this->capacity ) && ( this->capacity > 5) ) {
        this->capacity -= 5;
        T *temp = new T [this->capacity];
        for (int i = 0; i < this->size; i++) {
            temp[i] = this->data[i];
        }
        delete [] this->data;
        this->data = temp;
    }
    this->size--;
    e = this->data[this->size];
    return *this;
}

template <class T>
int MyArray<T>::getSize() {
    return this->size;
}

template <class T>
bool MyArray<T>::isEmpty() {
    bool empty = true;
    if (this->size > 0) {
        empty = false;
    }
    return empty;
}

template <class T>
T& MyArray<T>::operator [] (int n) {
    if (n >= this->size || n < 0) {
        throw(BadIndex());
    }
    return this->data[n];
}

template <class T>
string MyArray<T>::toString() {
    ostringstream out;
    out << this->size << endl;
    out << this->capacity << endl;
    if (this->size == 0) {
        out << endl;
    }
    else {
        for (int i = 0; i < this->size; i++) {
            out << this->data[i] << "\t";
        }
        out << endl;
    }

    return out.str();
}

#endif //LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_MYARRAY_H
