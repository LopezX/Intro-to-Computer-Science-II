//
// Created by xslop on 4/4/2022.
//

#ifndef LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_CONTAINERIFC_H
#define LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_CONTAINERIFC_H

#include "lab7-SerializableIfc.h"
#include <string>


class BadIndex{};

template <class T>
class ContainerIfc : public SerializableIfc {
public:
    virtual ContainerIfc<T>& pushBack(T) = 0;
    virtual ContainerIfc<T>& popBack(T &) = 0;
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual T& operator[](int) = 0;
    virtual string toString() = 0;
};

#endif //LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_CONTAINERIFC_H
