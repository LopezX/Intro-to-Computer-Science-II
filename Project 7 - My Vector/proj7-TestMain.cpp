/**
 * file: proj7-TestMain.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 7 - MyVector
 * due date: 4/4/2022
 *
 * date modified: 4/3/2022
 *      - file created
 *      - Tested functions from default constructor to pushBack
 *          - referencing the order in proj7-Testmain.cpp
 *
 * date modified: 4/3/2022
 *      - Tested functions from erase to copy assignment operator
 *
 * The test main for the proj7-MyVector.h's MyVector class
 */

#include <iostream>
#include "proj7-MyVector.h"

int main() {
    //Testing MyVector default constructor
    MyVector<int> intV;

    //Testing getSize()
    cout << "MyVectors intV, intV2, and strV have been initialized." << endl;
    cout << "intV has size of:  " << intV.getSize()  << ", should be 0." << endl;
    cout << endl;

    //Testing pushFront() (which also test shiftRight())
    cout << "Pushing 0 to front of intV..." << endl;
    intV.pushFront(0);
    cout << "Pushing 1 to front of intV..." << endl;
    intV.pushFront(1);
    cout << "Pushing 2 to front of intV..." << endl;
    intV.pushFront(2);

    //Testing front(), operator[], and back()
    try {
        cout << "The front of intV has: " << intV.front() << ", should be 2." << endl;
        cout << "The 1st index of intV has: " << intV[1]  << ", should be 1." << endl;
        cout << "The last of intV has:  " << intV.back()  << ", should be 0." << endl;
        cout << endl;
    }
    catch (BADINDEX) {
        cerr << "BADINDEX DETECTED." << endl;
    }

    //Testing pushBack()
    cout << "Pushing back 3 to intV..." << endl;
    intV.pushBack(3);
    cout << "Pushing back 4 to intV..." << endl;
    intV.pushBack(4);
    cout << "Pushing back 5 to intV..." << endl;
    intV.pushBack(5);
    try {
        cout << "The third element of intV is:  " << intV[3] << ", should be 3." << endl;
        cout << "The fourth element of intV is: " << intV[4] << ", should be 4." << endl;
        cout << "The fifth element of intV is:  " << intV[5] << ", should be 5." << endl;
        cout << endl;
    }
    catch (BADINDEX) {
        cerr << "BADINDEX DETECTED" << endl;
    }

    //Testing erase()
    cout << "Erasing intV..." << endl;
    intV.erase();
    cout << "The size of intV is: " << intV.getSize() << ", should be 0." << endl;

    //Test grow() (within pushBack, as well as pushFront) and throw statements
    cout << "Filling in intV to hold 16 values, integers from 0-15..." << endl;
    for (int i = 0; i <= 15; i++) {
        intV.pushBack(i);
    }
    try {
        cout << "The elements of intV from 0th to 16th are..." << endl;
        for (int i = 0; i < intV.getSize(); i++) {
            cout << i << "th element is: " << intV[i];
            cout << ", should be " << i << endl;
        }
    }
    catch (BADINDEX) {
        cout << "BADINDEX DETECTED" << endl;
    }
    cout << "intV size is: " << intV.getSize() << endl;
    cout << endl;

    //Testing copy constructor
    cout << "Initializing intV2 via copy constructor..." << endl;
    MyVector<int> intV2(intV);
    cout << "intV2 size is: " << intV2.getSize() << ", should be 16." << endl;
    cout << "The elements of intV2 are:" << endl;
    try {
        for (int i = 0; i < intV2.getSize(); i++) {
            cout << intV2[i] << "  ";
        }
    }
    catch (BADINDEX) {
        cerr << "BADINDEX DETECTED" << endl;
    }
    cout << endl;

    //Testing popBack() and popFront();
    int n;
    try {
        cout << "Popping the front of intV2..." << endl;
        intV2.popFront(n);
        cout << "Removed " << n << ", should be 0." << endl;
        cout << "Popping the back of intV2..." << endl;
        intV2.popBack(n);
        cout << "Removed " << n << ", should be 15." << endl;
    }
    catch (BADINDEX) {
        cerr << "BADINDEX DETECTED" << endl;
    }
    cout << endl;

    //Testing copy assignment operator
    cout << "Initialized intV3..." << endl;
    MyVector<int> intV3;
    intV3 = intV2;
    cout << "Size of intV3 is: " << intV3.getSize() << endl;
    cout << "Printing elements of intV3, should contain 1-14." << endl;
    try {
        for (int i = 0; i < intV3.getSize(); i++) {
            cout << intV3[i] << " ";
        }
    }
    catch (BADINDEX) {
        cerr << "BADINDEX DETECTED" << endl;
    }
    cout << endl;

    return 0;
}
