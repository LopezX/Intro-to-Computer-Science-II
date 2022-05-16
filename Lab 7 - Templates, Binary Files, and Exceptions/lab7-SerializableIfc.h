//
// Created by xslop on 4/4/2022.
//

#ifndef LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_SERIALIZABLEIFC_H
#define LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_SERIALIZABLEIFC_H

#include <iostream>
using namespace std;

class SerializableIfc {
public:
    virtual void writeObject( ostream & ) = 0;
    virtual void readObject( istream & ) = 0;
};

#endif //LAB_7___TEMPLATES__BINARY_FILES__AND_EXCEPTIONS_LAB7_SERIALIZABLEIFC_H