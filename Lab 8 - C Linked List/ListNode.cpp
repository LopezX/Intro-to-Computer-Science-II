#include "ListNode.h"

ListNode *insert(ListNode *ptr, string val) {
    insert(&ptr, val);
    return ptr;
}

void insert(ListNode **ptr, string val) {
    ListNode *temp = (*ptr);
    (*ptr) = NULL;
    delete (*ptr);
    (*ptr) = new ListNode;
    (*ptr)->data = val;
    (*ptr)->next = temp;
}

ListNode *remove(ListNode *ptr) {
    remove(&ptr);
    return ptr;
}

void remove(ListNode** ptr) {
    ListNode *temp = (*ptr);
    if (temp->next != NULL) {
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    else {
        delete *(ptr);
        *(ptr) = new ListNode;
        *(ptr) = NULL;
    }
}

void printForward(ostream &out, ListNode *ptr) {
    if (ptr != NULL) {
        ListNode *temp = ptr->next;
        out << ptr->data << endl;
        if (temp != NULL) {
            printForward(out, temp);
        }
    }
}

void printReverse(ostream &out, ListNode *ptr) {
    ListNode *temp = ptr->next;
    if (temp != NULL) {
        printReverse(out, temp);
    }
    out << ptr->data << endl;
}
