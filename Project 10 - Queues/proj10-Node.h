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
 * Header file for the proj10-Node.h class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_NODE_H
#define PROJECT_10___QUEUES_PROJ10_NODE_H

template <class T>
class Node {
public:
    T data;
    Node <T>*next;

    Node( T d ) {
        data = d;
        next = NULL;
    }

    ~Node( ) {
        delete next;
    }
};

#endif //PROJECT_10___QUEUES_PROJ10_NODE_H
