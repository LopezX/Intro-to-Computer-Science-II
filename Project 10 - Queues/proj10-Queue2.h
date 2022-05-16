/**
 * file: proj10-Queue2.h
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 10 - Queues
 * due date: 5/2/2022
 *
 * date modified: 4/27/2022
 *      - file was created
 *
 * date modified: 5/1/2022
 *      - defined Queue2
 *      - defined enqueue
 *      - started to define dequeue
 *
 * date modified: 5/2/2022
 *      - updated dequeue
 *
 * Header for Queue2 class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_QUEUE2_H
#define PROJECT_10___QUEUES_PROJ10_QUEUE2_H

#include "proj10-MyVector.h"

template <class T>
class Queue2 : public MyVector<T> {
private:
    int front, rear;

public:
    /**
     * Queue2
     *
     * default constructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    Queue2();

    /**
     * enqueue
     *
     * pushes a value to the end of the MyVector class
     *
     * Parameters:
     *      - e: a T value
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void enqueue( T );

    /**
     * dequeue
     *
     * pops the front value of the MyVector class
     *
     * Parameters:
     *      - e: a T value
     *
     * Output:
     *      return: none
     *      reference parameters: e
     *      stream: none
     */
    void dequeue( T& ); // throws BADINDEX
};

template<class T>
Queue2<T>::Queue2() {
    this->front = -1;
    this->rear = -1;
}

template<class T>
void Queue2<T>::enqueue( T e ) {
    if (this->size >= this->capacity) {
        int oldCapacity = this->capacity;
        this->capacity *= 2;
        int *temp = new int [this->capacity];
        this->rear = -1;
        for (int i = 0; i < this->size; i++) {
            this->rear++;
            this->front = (this->front + 1) % oldCapacity;
            temp[this->rear] = this->data[front];
        }
        this->front = -1;
        delete [] this->data;
        this->data = temp;
    }
    this->rear = (this->rear + 1) % this->capacity;
    this->data[this->rear] = e;
    this->size++;
}

template<class T>
void Queue2<T>::dequeue( T& e ) {
    this->front = (this->front + 1) % this->capacity;
    if (this->front > this->rear) {
        this->front--;
        throw (BADINDEX());
    }
    e = this->data[this->front];
}


#endif //PROJECT_10___QUEUES_PROJ10_QUEUE2_H
