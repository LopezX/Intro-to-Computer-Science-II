/**
 * file: proj8-bFileSort.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 8 - Binary File Sort
 * due date: 4/11/2022
 *
 * date modified: 4/4/2022
 *      - file created
 *
 * date modified: 4/11/2022
 *      - Added file opening and file verification method
 *      - Added code that reads from file
 *      - Added code that gets user input
 *      - Added code that sorts the file from least to greatest
 *
 * Opens a binary file, reading from file, and writing
 * a user input to a binary file.
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    fstream in;
    int userInt, numInts, i, x;
    bool posFound = false;

    in.open("sortedInts", ios::in | ios::out | ios::binary);
    if ( !in ) {
        cerr << "Bad filename" << endl;
        return 1;
    }

    //Gets the numbers out of the file
    in.seekg(0, ios::end);
    numInts = in.tellg() / sizeof(int);
    cout << "Integers in the file:" << endl;
    if (in.tellg() > 0) {
        in.seekg(0, ios::beg);
        for (i = 0; i < numInts; i++) {
            in.read((char*)&x, sizeof(int));
            cout << x << "\t";
        }
    }
    cout << endl;

    //Asks user for input
    in.seekg(0, ios::end);
    cout << "Enter a number: " << endl;
    cin >> userInt;

    //Inputs user into file
    //Checks
    if (in.tellg() > 4) {
        i = 0;

        //Checks for ALL integers
        while (i < numInts && !posFound) {
            in.seekg(-1 * sizeof(int), ios::cur);
            in.read((char *) &x, sizeof(int));
            in.write((char *) &x, sizeof(int));
            in.seekg(-1 * sizeof(int), ios::cur);
            if (x < userInt) {
                in.write((char *) &userInt, sizeof(int));
                posFound = true;
            } else {
                in.seekg(-1 * sizeof(int), ios::cur);
            }
            i++;
        }

        //If the integer is the lowest, puts at beginning of file
        if (!posFound) {
            in.write((char*)&userInt, sizeof(int));
        }
    }
    else {
        in.write((char*)&userInt, sizeof(int));
    }

    in.close();

    return 0;
}
