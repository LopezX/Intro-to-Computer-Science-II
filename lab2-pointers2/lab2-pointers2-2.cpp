/**
 * file: pointers2-2.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Lab 2 - Pointers 2
 * Due Date: 1/28/2022
 *
 * Date Modified: 1/24/2022
 *     - Typed Step 4 from zyBooks
 * Date Modified: 1/24/2022
 *     - Typed Step 5 from zyBooks
 * Date Modified: 1/24/2022
 *     - Typed Step 1 under Dynamic Memory from zyBooks
 *
 * This file will shows the difference in changing arrays and pointers
*/

#include <iostream>

using namespace std;

char* giveMemory( ) {
    char myArray[] = "Hello World!";
    return myArray;
}

int main() {
    //Initialize char pointer myPtr
    char *myPtr;

    //Calls the giveMemory function to have myPtr point to an array of
    //characters
    myPtr = giveMemory();
    cout << myPtr << endl;

    //Changes the 4 characters after 'H' to 'o', 'w', 'd', and 'y' in the
    //pointer
    myPtr[1] = 'o';
    myPtr[2] = 'w';
    myPtr[3] = 'd';
    myPtr[4] = 'y';

    //Prints the new char pointer
    cout << endl << myPtr << endl;

    return 0;
}

