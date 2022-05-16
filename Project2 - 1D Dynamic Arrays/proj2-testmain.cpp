/**
 * file:  proj2-testmain.cpp
 * author:  Xavier Lopez
 * course: CSI 1440 02
 * assignment:  Project 2
 * due date:  1/31/2021
 *
 * date modified:  1/30/2022
 *      - Tested functions with aTest1:
 *          = bubbleSort
 * date modified:  1/31/2022
 *      - Tested functions with aTest1:
 *          = minimumValue
 *          = maximumValue
 *          = averageValue
 *          = medianValue
 *      - Tested functions with:
 *          = aTest2
 *          = aTest3
 *          = aTest4
 *          = aTest5
 *          = aTest6
 *          = Functions tested:
 *              + bubbleSort
 *              + minimumValue
 *              + maximumValue
 *              + averageValue
 *              + medianValue
 *
 * This file tests each of the functions for Project 2
 */

#include "proj2-arrayFunctions.h"
#include <iostream>

using namespace std;

int main() {
    int *aTest1 = new int [10];  //Random integers
    int *aTest2 = new int [5];   //Smallest value in front, largest value in the back
    int *aTest3 = new int [8];   //Largest value in front, smallest value in the back
    int *aTest4 = new int [4];   //Negative values are inputted
    int *aTest5 = new int [10];  //Multiples of same integers
    int *aTest6 = new int [6];   //Largest value and smallest value in the middle

    cout << "Test 1: Random integers in array" << endl;
    cout << "Initializing random integers for pointer array..." << endl;
    //Assigns each pointer location a value
    for (int i = 0; i < 10; i++) {
        aTest1[i] = rand() % 100;
    }
    cout << endl;

    cout << "Beginning function tests: " << endl << endl;

    cout << "Array intially:" << endl;
    //Prints aTest1 as it is
    for (int i = 0; i < 10; i++) {
        cout << aTest1[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest1 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest1, 10);

    //Prints aTest1 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << aTest1[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of aTest1
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest1, 10) << endl;
    cout << "Maximum Value = " << largestValue(aTest1, 10)  << endl;
    cout << "Median Value  = " << medianValue(aTest1, 10)   << endl;
    cout << "Average Value = " << averageValue(aTest1, 10)  << endl;

    delete [] aTest1; //deletes pointer array to prevent memory leak after use

    cout << endl;
    cout << "End of Test 1" << endl << endl << endl;

    //Beginning of Test 2
    cout << "Test 2: Smallest value front, largest value back" << endl;
    cout << "Initializing integers for pointer array..." << endl;
    aTest2[0] = 1;
    aTest2[1] = 5;
    aTest2[2] = 8;
    aTest2[3] = 3;
    aTest2[4] = 100;
    cout << endl;

    cout << "Array intially:" << endl;
    //Prints aTest2 as it is
    for (int i = 0; i < 5; i++) {
        cout << aTest2[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest2 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest2, 5);

    //Prints aTest2 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << aTest2[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of the aTest2
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest2, 5) << endl;
    cout << "Maximum Value = " << largestValue(aTest2, 5)  << endl;
    cout << "Median Value  = " << medianValue(aTest2, 5)   << endl;
    cout << "Average Value = " << averageValue(aTest2, 5)  << endl;

    cout << endl;
    cout << "End of Test 2" << endl << endl << endl;

    delete [] aTest2;  //deletes pointer array to prevent memory leak after use

    //Beginning of Test 3
    cout << "Test 3: Largest value front, smallest value back" << endl;
    cout << "Initializing integers for pointer array..." << endl;
    aTest3[0] = 9076;
    aTest3[1] = 700;
    aTest3[2] = 899;
    aTest3[3] = 3000;
    aTest3[4] = 81;
    aTest3[5] = 100;
    aTest3[6] = 41;
    aTest3[7] = 6;
    cout << endl;

    cout << "Array intially:" << endl;
    //Prints aTest3 as it is
    for (int i = 0; i < 8; i++) {
        cout << aTest3[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest3 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest3, 8);

    //Prints aTest3 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << aTest3[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of aTest3
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest3, 8) << endl;
    cout << "Maximum Value = " << largestValue(aTest3, 8)  << endl;
    cout << "Median Value  = " << medianValue(aTest3, 8)   << endl;
    cout << "Average Value = " << averageValue(aTest3, 8)  << endl;

    cout << endl;
    cout << "End of Test 3" << endl << endl << endl;

    delete [] aTest3;

    //Beginning of Test 4
    cout << "Test 4: Negative values" << endl;
    cout << "Initializing integers for pointer array..." << endl;
    aTest4[0] = 78;
    aTest4[1] = -13;
    aTest4[2] = -7;
    aTest4[3] = 30;
    cout << endl;

    cout << "Array intially:" << endl;
    //Prints aTest3 as it is
    for (int i = 0; i < 4; i++) {
        cout << aTest4[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest3 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest4, 4);

    //Prints aTest3 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << aTest4[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of aTest3
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest4, 4) << endl;
    cout << "Maximum Value = " << largestValue(aTest4, 4)  << endl;
    cout << "Median Value  = " << medianValue(aTest4, 4)   << endl;
    cout << "Average Value = " << averageValue(aTest4, 4)  << endl;

    cout << endl;
    cout << "End of Test 4" << endl << endl << endl;

    delete [] aTest4;

    //Beginning of Test 5
    cout << "Test 5: Multiples of an integer" << endl;
    cout << "Initializing integers for pointer array..." << endl;
    aTest5[0] = 88;
    aTest5[1] = 70;
    aTest5[2] = 10;
    aTest5[3] = 134;
    aTest5[4] = 88;
    aTest5[5] = 70;
    aTest5[6] = 70;
    aTest5[7] = 91;
    aTest5[8] = 134;
    aTest5[9] = 10;
    cout << endl;

    cout << "Array intially:" << endl;
    //Prints aTest3 as it is
    for (int i = 0; i < 10; i++) {
        cout << aTest5[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest5 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest5, 10);

    //Prints aTest5 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << aTest5[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of aTest5
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest5, 10) << endl;
    cout << "Maximum Value = " << largestValue(aTest5, 10)  << endl;
    cout << "Median Value  = " << medianValue(aTest5, 10)   << endl;
    cout << "Average Value = " << averageValue(aTest5, 10)  << endl;

    cout << endl;
    cout << "End of Test 5" << endl << endl << endl;

    delete [] aTest5;

    //Beginning of Test 6
    cout << "Test 6: Largest and smallest value in the middle" << endl;
    cout << "Initializing integers for pointer array..." << endl;
    aTest6[0] = 9;
    aTest6[1] = 704;
    aTest6[2] = -1001;
    aTest6[3] = 3003;
    aTest6[4] = -10;
    aTest6[5] = 0;
    cout << endl;

    cout << "Array intially:" << endl;
    //Prints aTest6 as it is
    for (int i = 0; i < 6; i++) {
        cout << aTest6[i] << " ";
    }
    cout << endl << endl;

    //Sorts aTest6 using bubble sort
    cout << "Sorting array from least to greatest..." << endl << endl;
    bubbleSort(aTest6, 6);

    //Prints aTest6 after being sorted from least to greatest
    cout << "Array after sorting:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << aTest6[i] << " ";
    }
    cout << endl << endl;

    //Finds the minimum, maximum, and median of aTest6
    cout << "Finding the minimum, maximum, median and average..." << endl << endl;
    cout << "Minimum Value = " << smallestValue(aTest6, 6) << endl;
    cout << "Maximum Value = " << largestValue(aTest6, 6)  << endl;
    cout << "Median Value  = " << medianValue(aTest6, 6)   << endl;
    cout << "Average Value = " << averageValue(aTest6, 6)  << endl;

    cout << endl;
    cout << "End of Test 6" << endl;

    delete [] aTest6;

    return 0;
}