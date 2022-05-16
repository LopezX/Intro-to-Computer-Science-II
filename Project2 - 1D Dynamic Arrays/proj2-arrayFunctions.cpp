/**
 * file:  proj2-testmain.cpp
 * author:  Xavier Lopez
 * course: CSI 1440 02
 * assignment:  Project 2
 * due date:  1/31/2021
 *
 * date modified:  1/30/2022
 *      - Defined functions:
 *          = bubbleSort
 *
 * date modified:  1/31/2022
 *      - Defined functions:
 *          = largestValue
 *          = smallestValue
 *          = averageValue
 *          = medianValue
 *
 * This file defines the functions for Project 2
 */

#include "proj2-arrayFunctions.h"

using namespace std;

/**
 * bubbleSort
 *
 * This function sorts the pointer array from least to greatest
 *
 * Parameters:
 *      a: integer pointer array
 *      s: size of the integer pointer array
 *
 * Output:
 *      return:  void
 *      reference parameters: none
 *      stream:  none
 */
void bubbleSort(int *a, int s) {
    int temp;
    for (int i = 0; i < s - 1; i++) {
        for (int j = 0; j < s - 1 - i; j++) {
            if (a[j] > a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

/**
 * largestValue
 *
 * This function gets the largest value from the integer array
 *
 * Parameters:
 *      a:  integer pointer array
 *      s:  the size of the integer pointer array
 *
 * Output:
 *      return:  the maximum value in the array
 *      reference parameters: none
 *      stream:  none
 */
int largestValue(int *a, int s) {
    return a[s-1];
}

/**
 * smallestValue
 *
 * This function finds the smallest value in the integer pointer array
 *
 * Parameters:
 *      a:  integer pointer array
 *      s:  the size of the integer pointer array
 *
 * Output:
 *      return:  the smallest value in the array
 *      reference parameters: none
 *      stream:  none
 */
int smallestValue(int *a, int s) {
    return a[s-s];  //returns the first value in the array
}

/**
 * averageValue
 *
 * This function computes the average for the integer pointer array
 *
 * Parameters:
 *      a:  integer pointer array
 *      s:  the size of the integer pointer array
 *
 * Output:
 *      return:  the average of the array
 *      reference parameters: none
 *      stream:  none
 */
double averageValue(int *a, int s) {
    double avg = 0;
    for (int i = 0; i < s; i++) {
        avg += a[i];
    }
    avg /= s;
    return avg;
}

/**
 * medianValue
 *
 * This function finds the median of the array, which in the case of an even
 * size, the function will return the lower of the median canidates
 *
 * Parameters:
 *      a:  integer pointer array
 *      s:  the size of the integer pointer array
 *
 * Output:
 *      return:  the median of the array
 *      reference parameters: none
 *      stream:  none
 */
int medianValue(int *a, int s) {
    double med;
    if (s % 2 == 0) {  //If s is even...
        med = a[s/2 - 1];
    }
    else {  //If s is odd...
        med = a[s/2];
    }
    return med;
}