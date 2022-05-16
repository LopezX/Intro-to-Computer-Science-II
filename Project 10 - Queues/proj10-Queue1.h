/**
 * file: proj10-Queue1.h
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 10 - Queues
 * due date: 5/2/2022
 *
 * date modified: 4/27/2022
 *      - file was created
 *
 * date modified: 5/1/2022
 *      - defined enqueue and dequeue
 *
 * Header for the Queue1 class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_QUEUE1_H
#define PROJECT_10___QUEUES_PROJ10_QUEUE1_H

#include "proj10-MyVector.h"

template <class T>
class Queue1 : public MyVector<T> {
public:
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

template <class T>
void Queue1<T>::enqueue(T e) {
    this->pushBack(e);
}

template <class T>
void Queue1<T>::dequeue(T &e) {
    this->popFront(e);
}

#endif //PROJECT_10___QUEUES_PROJ10_QUEUE1_H
