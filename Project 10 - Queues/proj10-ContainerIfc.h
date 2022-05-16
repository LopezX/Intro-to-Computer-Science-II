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
 * Header file for the proj10-ContainerIfc.h class
 */

#ifndef PROJECT_10___QUEUES_PROJ10_CONTAINERIFC_H
#define PROJECT_10___QUEUES_PROJ10_CONTAINERIFC_H

class BADINDEX {};

template <class T>
class ContainerIfc {
public:
    virtual ContainerIfc <T>& pushFront(T) =0;
    virtual ContainerIfc <T>& pushBack(T)  =0;
    virtual ContainerIfc <T>& popFront(T&) =0; // throws BADINDEX
    virtual ContainerIfc <T>& popBack(T&)  =0; // throws BADINDEX
    virtual int getSize()                  =0;
    virtual bool isEmpty()                 =0;
    virtual T  front()                     =0; // throws BADINDEX
    virtual T  back()                      =0; // throws BADINDEX
    virtual T&  operator [](int)           =0; // throws BADINDEX
    virtual void erase()                   =0;
};

#endif //PROJECT_10___QUEUES_PROJ10_CONTAINERIFC_H
