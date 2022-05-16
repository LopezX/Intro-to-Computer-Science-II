//
// Created by xslop on 4/22/2022.
//

#ifndef PROJECT_9___LINKED_LIST_PROJ9_NODE_H
#define PROJECT_9___LINKED_LIST_PROJ9_NODE_H

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};

#endif //PROJECT_9___LINKED_LIST_PROJ9_NODE_H
