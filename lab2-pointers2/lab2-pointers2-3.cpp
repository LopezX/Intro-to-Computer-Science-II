/**
 * file: pointers2-3.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Lab 2 - Pointers 2
 * Due Date: 1/28/2022
 *
 * Date Modified: 1/24/2022
 *     - Typed Step 2 (both parts) under Dynamic memory from zyBooks
 *
 * This file shows how to use dynamic memory and its relation to the run-time
 * stack
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    //Initializes char array myArray, storing "Hello World!" in it
    //Initializes a NEW char pointer array with 13 storage spaces
    char myArray[] = "Hello World!";
    char *myPtr = new char[13];

    //
    strcpy(myPtr, "Hello World!");

    cout << "This is from the array: " << myArray << endl;
    cout << "This is from the pointer: " << myPtr << endl;

    cout << endl << "Let's try to change the array..." << endl;
    myArray[1] = 'o';
    myArray[2] = 'w';
    myArray[3] = 'd';
    myArray[4] = 'y';

    cout << "This is from the array: " << myArray << endl;

    cout << endl << "Let's try to change the pointer..." << endl;
    myPtr[1] = 'o';
    myPtr[2] = 'w';
    myPtr[3] = 'd';
    myPtr[4] = 'y';

    cout << "This is from the pointer: " << myPtr << endl;

    delete [] myPtr;

    return 0;
}


