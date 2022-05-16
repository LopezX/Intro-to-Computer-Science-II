/**
 * file: proj9-MyList.h
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 9 - Linked List
 * due date: 4/25/2022
 *
 * date modified: 4/24/2022
 *      - defined:
 *          - MyList
 *          - ~MyList
 *          - Copy Constructor
 *          - pushFront
 *          - popFront
 *          - isEmpty
 *
 * date modified: 4/25/2022
 *      - defined:
 *          - erase
 *          - copy assignment operator
 *          - pushBack
 *          - back
 *          - popBack
 *          - operator []
 *          - getSize
 *      - touched on all functions for memory leaks
 *
 *
 * Header file and the functions for the MyList class
 */
#ifndef PROJECT_9___LINKED_LIST_PROJ9_MYLIST_H
#define PROJECT_9___LINKED_LIST_PROJ9_MYLIST_H

#include "proj9-ContainerIfc.h"
#include "proj9-Node.h"

template <class T>
class MyList : public ContainerIfc <T> {
public:
    /**
     * MyList
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
    MyList();

    /**
     * ~MyList
     *
     * class destructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~MyList();

    /**
     * MyList(const MyList&)
     *
     * class copy constructor
     *
     * Parameters:
     *   - that:  a const MyList object
     *
     * Output:
     *      return: none
     *      reference parameters: that
     *      stream: none
     */
    MyList(const MyList&);

    /**
     * operator =
     *
     * overload assignment operator
     *
     * Parameters:
     *   - that:  a const MyList object
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: that
     *      stream: none
     */
    MyList <T>& operator = (const MyList&);

    /**
     * pushFront
     *
     * store data element n in a new Node and adds the Node to the front of a
     * data structure (MyList)
     *
     * Parameters:
     *   - e:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushFront(T);

    /**
     * pushback
     *
     * store data element n in a new Node and adds the Node to the rear (end)
     * of a data structure (MyList)
     *
     * Parameters:
     *   - e:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: none
     *      stream: none
     */
    MyList <T>& pushBack(T);

    /**
     * popFront
     *
     * removes a data element from the front of the data structure (MyList)
     *
     * Parameters:
     *   - e:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: e
     *      stream: none
     */
    MyList <T>& popFront(T&);

    /**
     * popBack
     *
     * removes a data element from the rear (end) of the data structure
     * (MyList)
     *
     * Parameters:
     *   - e:  a T variable
     *
     * Output:
     *      return: MyList object by reference
     *      reference parameters: e
     *      stream: none
     */
    MyList <T>& popBack(T&);

    /**
     * getSize
     *
     * returns the number of Nodes currently in the linked MyList
     *
     * Parameters: none
     *
     * Output:
     *      return: int
     *      reference parameters: e
     *      stream: none
     */
    int getSize();

    /**
     * isEmpty
     *
     * returns true if there are any linked nodes in the list
     *
     * Parameters: none
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    bool isEmpty();

    /**
     * front
     *
     * returns a copy of the first data item in the linked list
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T front();

    /**
     * back
     *
     * returns a copy of the last data item in the linked list
     *
     * Parameters: none
     *
     * Output:
     *      return: T
     *      reference parameters: none
     *      stream: none
     */
    T back();

    /**
     * operator []
     *
     * returns a copy of the first data item in the linked list
     *
     * Parameters:
     *   idx:  the index of what node to access
     *
     * Output:
     *      return: T reference
     *      reference parameters: none
     *      stream: none
     */
    T& operator [](int);

    /**
     * erase
     *
     * removes all nodes from MyList
     *
     * Parameters:
     *   idx:  the index of what node to access
     *
     * Output:
     *      return: T reference
     *      reference parameters: none
     *      stream: none
     */
    void erase();

protected:
    Node<T> *head;
};

template<class T>
MyList<T>::MyList() {
    this->head = NULL;
}

template<class T>
MyList<T>::~MyList() {
    Node<T> *temp;
    while (this->head != NULL) {
        temp = this->head->next;
        delete this->head;
        this->head = temp;
    }
}

template<class T>
MyList<T>::MyList(const MyList& that) {
    this->head = NULL;
    if (that.head != NULL) {
        this->head = new Node<T>(that.head->data);
        Node<T> *thisTemp = this->head;
        Node<T> *thatTemp = that.head->next;

        while(thatTemp != NULL) {
            thisTemp->next = new Node<T>(thatTemp->data);
            thisTemp = thisTemp->next;
            thatTemp = thatTemp->next;
        }
    }
}

template<class T>
MyList <T>& MyList<T>::operator= (const MyList& that) {
    if (this->head != that.head) {
        while (this->head != NULL) {
            this->erase();
        }
        delete this->head;
        this->head = NULL;
        this->head = new Node<T>(that.head->data);
        Node<T> *thisTemp = this->head;
        Node<T> *thatTemp = that.head->next;

        while(thatTemp != NULL) {
            thisTemp->next = new Node<T>(thatTemp->data);
            thisTemp = thisTemp->next;
            thatTemp = thatTemp->next;
        }
    }
    return *this;
}

template<class T>
MyList <T>& MyList<T>::pushFront(T e) {
    Node<T> *temp = this->head;
    this->head = NULL;
    delete this->head;
    this->head = new Node<T>(e);
    this->head->next = temp;
    temp = NULL;
    delete temp;
    return *this;
}

template<class T>
MyList <T>& MyList<T>::pushBack(T e) {
    if (this->head == NULL) {
        this->head = new Node<T>(e);
    }
    else {
        Node<T> *temp = this->head;
        this->head = NULL;
        delete this->head;
        this->head = new Node<T>(temp->data);
        Node<T> *thisTemp = this->head;
        Node<T> *thatTemp = temp->next;

        while (thatTemp != NULL) {
            thisTemp->next = new Node<T>(thatTemp->data);
            thisTemp = thisTemp->next;
            thatTemp = thatTemp->next;
        }
        thisTemp->next = new Node<T>(e);
    }
    return *this;
}

template<class T>
MyList <T>& MyList<T>::popFront(T& e) {
    if (this->head == NULL) {
        throw(BADINDEX());
    }
    Node<T> *temp = head;
    head = head->next;
    e = temp->data;
    delete temp;
    return *this;
}

template<class T>
MyList <T>& MyList<T>::popBack(T& e) {
    if (this->head == NULL) {
        throw(BADINDEX());
    }
    Node<T> *temp = this->head;
    if (temp->next != NULL) {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        e = temp->next->data;
        temp->next = NULL;
    }
    else {
        e = temp->data;
        delete this->head;
        this->head = NULL;
    }
    return *this;
}

template<class T>
int MyList<T>::getSize() {
    int count = 0;
    Node<T> *temp = this->head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

template<class T>
bool MyList<T>::isEmpty() {
    bool empty = false;
    if (this->head == NULL) {
        empty = true;
    }
    return empty;
}

template<class T>
T MyList<T>::front() {
    if (this->head == NULL) {
        throw(BADINDEX());
    }
    T val;
    val = this->head->data;
    return val;
}

template<class T>
T MyList<T>::back() {
    if (this->head == NULL) {
        throw(BADINDEX());
    }
    T val;
    Node<T> *thisTemp = this->head->next;

    while (thisTemp->next != NULL) {
        thisTemp = thisTemp->next;
    }
    val = thisTemp->data;
    return val;
}

template<class T>
T& MyList<T>::operator [](int idx) {
    Node<T> *temp = this->head;
    for (int i = 0; i < idx; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        throw(BADINDEX());
    }
    return temp->data;
}

template<class T>
void MyList<T>::erase() {
    if (this->head != NULL) {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
        erase();
    }
    this->head = NULL;
}

#endif //PROJECT_9___LINKED_LIST_PROJ9_MYLIST_H
