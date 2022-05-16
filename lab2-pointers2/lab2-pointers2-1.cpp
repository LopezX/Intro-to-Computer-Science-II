/**
 * file: pointers2-1.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Lab 2 - Pointers 2
 * Due Date: 1/28/2022
 *
 * Date Modified: 1/24/2022
 *     - Typed Step 1 from ZYBooks
 * Date Modified: 1/24/2022
 *     - Typed Step 2 from ZYBooks
 * Date Modified: 1/24/2022
 *     - Typed step 3 from ZYBooks
 *
 * This file will show the similarities between pointers and arrays
*/

#include <iostream>

using namespace std;

int main() {
    //Initialize char array myArray and const char pointer myPtr
    char myArray[] = "Hello World!";
    const char *myPtr = "Hello World!";

    //Prints the value of myArray and myPtr
    cout << "This is from the array: " << myArray << endl;
    cout << "This is from the pointer: " << myPtr << endl;
    cout << endl;

    //Adds to myArray and prints the value of myArray
    //FIX_ME (myArray doesn't increment)
    cout << "Trying to move the array..." << endl;
    myArray += 6;
    cout << "This is from the array: " << myArray << endl;

    return 0;
}
