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
 * Header for Queue3 class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_QUEUE3_H
#define PROJECT_10___QUEUES_PROJ10_QUEUE3_H

#include "proj10-MyList.h"

template <class T>
class Queue3 : public MyList<T> {
public:
    /**
     * enqueue
     *
     * pushes a value to the end of the MyList class
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
     * pops the front value of the MyList class
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
void Queue3<T>::enqueue( T e ) {
    this->pushBack(e);
}

template<class T>
void Queue3<T>::dequeue( T& e ) {
    this->popFront(e);
}

#endif //PROJECT_10___QUEUES_PROJ10_QUEUE3_H
