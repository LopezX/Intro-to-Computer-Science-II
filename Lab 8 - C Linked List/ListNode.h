//
// Created by xslop on 4/25/2022.
//

#ifndef LAB_8___C_LINKED_LIST_LISTNODE_H
#define LAB_8___C_LINKED_LIST_LISTNODE_H

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    string data;
    ListNode *next;
};

ListNode *insert(ListNode *ptr, string val);
void insert(ListNode **ptr, string val);
ListNode *remove(ListNode *ptr);
void remove(ListNode** ptr);
void printForward(ostream &out, ListNode *ptr);
void printReverse(ostream &out, ListNode *ptr);

#endif //LAB_8___C_LINKED_LIST_LISTNODE_H
