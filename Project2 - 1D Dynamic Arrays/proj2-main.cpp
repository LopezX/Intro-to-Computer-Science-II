/**
 * file:  proj2-testmain.cpp
 * author:  Xavier Lopez
 * course: CSI 1440 02
 * assignment:  Project 2
 * due date:  1/31/2021
 *
 * date modified:  1/31/2022
 *      - Completed entire code w/ comments
 *
 * This file holds the code for project 2
 */

#include "proj2-arrayFunctions.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
    ifstream inputFile;  //Gets the input file
    int arraySize;  //Gets the size of the array
    int n;  //Gets the number from the stringstream
    int arrayNumber = 0;  //Keeps track of how many arrays are read
    int overallMin;  //Gets the overall minimum of the arrays
    int overallMax;  //Gets the overall maximum of the arrays
    int currMin;  //Gets the current minimum of the array
    int currMax;  //Gets the current maximum of the array
    stringstream inSS;  //Allows integers to be read from a line
    string inputString;  //Gets a line from the file

    //Input File Validation
    inputFile.open("arrays.txt");
    if (!inputFile) {  //If file isn't found...
        //Prints error message
        cerr << "No File Found" << endl;
        return 1;
    }

    //If file is found...
    //While the array size can be read
    while (inputFile >> arraySize) {
        arrayNumber++;
        int *array = new int[arraySize];  //Dynamic Allocated Memory array pointer

        //Keeps track of how many arrays are read
        cout << "Array #" << arrayNumber << endl;

        //Gets the values of the array and puts it into stringstream
        inputFile.ignore();
        getline(inputFile, inputString);
        inSS.clear();
        inSS << inputString;

        //Input values into the array
        cout << "Unsorted Array:" << endl;
        for (int i = 0; i < arraySize; i++) {
            inSS >> n;
            array[i] = n;
            cout << array[i] << " ";
        }
        cout << endl;

        //Sorts the array
        bubbleSort(array, arraySize);
        cout << "Sorted array:" << endl;
        for (int i = 0; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;

        //Gets the current maximum and minimum value
        currMax = largestValue(array, arraySize);
        currMin = smallestValue(array, arraySize);

        //Sets the overall maximum and minimum value
        if (arrayNumber == 1) {
            overallMax = currMax;
            overallMin = currMin;
        }

        //If the overall maximum is less than the current maximum
        if (overallMax < currMax) {
            //Assign the overall maximum as the current maximum
            overallMax = currMax;
        }

        //If the overall minimum is greater than the current minimum
        if (overallMin > currMin) {
            //Assign the overall minimum as the current minimum
            overallMin = currMin;
        }

        //Prints the largest, smallest, average and median values of the array
        cout << "The largest value in the array is:  " << currMax << endl;
        cout << "The smallest value in the array is: " << currMin << endl;
        cout << "The average value of the array is:  " << averageValue(array, arraySize)  << endl;
        cout << "The median value in the array is:   " << medianValue(array, arraySize)   << endl;

        cout << endl;

        delete[] array;  //deletes array to prevent memory leak
    }

    //If no array were read (empty file)...
    if (arrayNumber == 0) {
        cout << "File is empty" << endl;
    }
    //If arrays were read from file...
    else {
        cout << "The overall maximum is: " << overallMax << endl;
        cout << "The overall minimum is: " << overallMin << endl;
    }
    cout << endl;

    cout << "End of program" << endl;

    return 0;
}