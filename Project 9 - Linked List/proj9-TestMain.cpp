/**
 * file: proj9-TestMain.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 9 - Linked List
 * due date: 4/25/2022
 *
 * date modified: 4/24/2022
 *      - Tested class constructor
 *      - Tested pushFront
 *      - Tested popFront
 *      - Tested isEmpty
 *
 * date modified: 4/25/2022
 *      - Tested erase
 *      - Tested copy constructor
 *      - Tested copy assignment operator
 *      - Tested back
 *      - Tested popBack
 *      - Tested operator []
 *      - Tested getSize
 *
 * Test main for the functions of MyList
 */
#include <iostream>
#include "proj9-MyList.h"

using namespace std;

int main() {
    MyList<int> frontList;

    //front and isEmpty testing
    cout << "MyList frontList created." << endl;
    cout << "Testing front and isEmpty:" << endl;
    try {
        cout << frontList.front() << endl;
    }
    catch(BADINDEX) {
        cout << "frontList is empty" << endl;
    }

    if (frontList.isEmpty()) {
        cout << "isEmpty is true" << endl;
    }
    else {
        cout << "isEmpty is false" << endl;
    }

    //pushFront testing
    cout << "Testing pushFront:" << endl;
    cout << "Pushing 0 - 4 to the front of list..." << endl << endl;
    for (int i = 0; i < 5; i++) {
        frontList.pushFront(i);
    }
    int val;

    try {
        cout << "Front of list is: ";
        cout << frontList.front() << " should be 4." << endl;
    }
    catch(BADINDEX) {
        cout << "frontList is empty" << endl;
    }

    if (frontList.isEmpty()) {
        cout << "isEmpty is true" << endl;
    }
    else {
        cout << "isEmpty is false" << endl;
    }
    cout << endl;

    //popFront tested
    cout << "Testing popFront on frontList 6 times:" << endl;
    for (int i = 4; i >= -1; i--) {
        try {
            frontList.popFront(val);
            cout << val << " should be " << i << endl;
        }
        catch(BADINDEX) {
            cout << "MyList is empty" << endl;
        }
    }
    cout << endl;

    cout << "Pushing 0-9 to the front of frontList:" << endl;
    for (int i = 0; i < 10; i++) {
        frontList.pushFront(i);
    }

    try {
        cout << frontList.front() << " should be 9." << endl;
    }
    catch(BADINDEX) {
        cout << "frontList is empty" << endl;
    }

    if (frontList.isEmpty()) {
        cout << "isEmpty is true" << endl;
    }
    else {
        cout << "isEmpty is false" << endl;
    }
    cout << endl;

    //erase testing
    cout << "Testing erase of frontList:" << endl;
    frontList.erase();

    try {
        cout << frontList.front() << " should be 9." << endl;
    }
    catch(BADINDEX) {
        cout << "frontList is empty" << endl;
    }

    if (frontList.isEmpty()) {
        cout << "isEmpty is true" << endl;
    }
    else {
        cout << "isEmpty is false" << endl;
    }
    cout << endl;

    cout << "Pushing 0-9 to the front of frontList:" << endl;
    for (int i = 0; i < 10; i++) {
        frontList.pushFront(i);
    }
    try {
        cout << "Front of frontList is " << frontList.front() << endl;
    }
    catch(BADINDEX) {
        cout << "frontList is empty" << endl;
    }
    cout << endl;

    //copy constructor testing
    cout << "Testing copy constructor: " << endl;
    MyList<int> frontListCopy(frontList);

    try {
        cout << "Front of frontListCopy is " << frontListCopy.front() << endl;
    }
    catch(BADINDEX) {
        cout << "frontListCopy is empty" << endl;
    }
    cout << "frontList has: ";
    while (!frontList.isEmpty()) {
        try {
            frontList.popFront(val);
            cout << val << " ";
        }
        catch(BADINDEX) {
            cout << "frontList is empty" << endl;
        }
    }
    cout << endl;
    cout << "frontListCopy has: ";
    while (!frontListCopy.isEmpty()) {
        try {
            frontListCopy.popFront(val);
            cout << val << " ";
        }
        catch(BADINDEX) {
            cout << "frontListCopy is empty" << endl;
        }
    }
    cout << endl << endl;

    //Testing copy assignment operator
    cout << "Testing copy assignment operator:" << endl;
    cout << "Pushing 0-9 to the front of frontList:" << endl;
    for (int i = 0; i < 10; i++) {
        frontList.pushFront(i);
    }
    cout << "Setting frontListCopy equal to frontList." << endl;
    frontListCopy = frontList;

    cout << "frontListCopy has: ";
    while (!frontListCopy.isEmpty()) {
        try {
            frontListCopy.popFront(val);
            cout << val << " ";
        }
        catch(BADINDEX) {
            cout << "frontListCopy is empty" << endl;
        }
    }
    cout << endl;
    cout << "frontList has: ";
    while (!frontList.isEmpty()) {
        try {
            frontList.popFront(val);
            cout << val << " ";
        }
        catch(BADINDEX) {
            cout << "frontList is empty" << endl;
        }
    }
    cout << endl << endl;


    //Testing pushBack
    MyList<int> backList;
    cout << "MyList backList created." << endl;
    cout << "Testing pushBack:" << endl;
    cout << "Pushing 0-9 to the end of backList." << endl;
    for (int i = 0; i < 10; i++) {
        backList.pushBack(i);
    }

    cout << "Popping all values from the front of backList:" << endl;
    try {
        for (int i = 0; i < 10; i++) {
            backList.popFront(val);
            cout << val << " ";
        }
    }
    catch(BADINDEX) {
        cout << "backList is empty" << endl;
    }
    cout << endl;

    //Testing back and popBack
    cout << "Testing back and popBack:" << endl;
    cout << "Pushing 0-9 to the end of backList." << endl;
    for (int i = 0; i < 10; i++) {
        backList.pushBack(i);
    }
    cout << "The back of backList is: ";
    try {
        cout << backList.back() << " should be 9." << endl;
    }
    catch(BADINDEX)  {
        cout << "backList is empty." << endl;
    }
    cout << endl;

    cout << "Popping back all of backList:" << endl;
    try {
        while(true) {
            backList.popBack(val);
            cout << val << " ";
        }
    }
    catch (BADINDEX) {
        cout << endl;
        cout << "backList is empty" << endl;
    }

    try {
        cout << backList.back() << endl;
    }
    catch(BADINDEX)  {
        cout << "backList is empty." << endl;
    }
    cout << endl;

    //Testing operator []
    cout << "Testing [] operator:" << endl;
    cout << "Pushing 0-9 to the end of backList." << endl;
    for (int i = 0; i < 10; i++) {
        backList.pushBack(i);
    }

    try {
        cout << "Value at index 0 is " << backList[0];
        cout << " should be 0." << endl;
    }
    catch (BADINDEX) {
        cout << "N/A (out of range)." << endl;
    }

    try {
        cout << "Value at index 5 is " << backList[5];
        cout << " should be 5." << endl;
    }
    catch (BADINDEX) {
        cout << "N/A (out of range)." << endl;
    }

    try {
        cout << "Value at index 10 is " << backList[10];
        cout << " should be 10." << endl;
    }
    catch (BADINDEX) {
        cout << "N/A (out of range)." << endl;
    }
    cout << endl;

    //Testing getSize
    cout << "Testing getSize:" << endl;
    cout << "Size of backList is " << backList.getSize();
    cout << " should be 10." << endl;

    cout << "Popping two values out." << endl;
    try {
        backList.popBack(val);
        backList.popBack(val);
    }
    catch (BADINDEX) {
        cout << "backList is empty." << endl;
    }
    cout << "Size of backList is " << backList.getSize();
    cout << " should be 8." << endl;

    cout << "Popping all values out." << endl;
    for (int i = 0; i < 8; i++) {
        try {
            backList.popBack(val);
        }
        catch (BADINDEX) {
            cout << "backList is empty." << endl;
        }
    }
    cout << "Size of backList is " << backList.getSize();
    cout << " should be 0." << endl;

    return 0;
}
