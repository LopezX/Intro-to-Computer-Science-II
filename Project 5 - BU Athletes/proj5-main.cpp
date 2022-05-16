/**
 * file: proj5-main.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *
 * date modified: 3/21/2022
 *    - main was edited
 *
 * The main code that is used when compiling.
 */

#include "proj5-BUAthleteList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main () {
    ifstream inputFile;
    string name, loi, school, posStr;
    stringstream inSS;
    BUAthleteList BUList;
    int id, prevID, eval, count = 0;
    Position pos;
    bool top2 = false;

    inputFile.open("proj5-NCAAAthlete.csv");
    if (!inputFile) {
        cerr << "Bad File" << endl;
        return -1;
    }
    while (!inputFile.eof()) {
        prevID = id;
        inputFile >> id;
        inputFile.ignore();
        getline(inputFile, name, ',');
        getline(inputFile, loi, ',');
        getline(inputFile, school);
        if (prevID != id) {
            BUList.addNCAAAthlete(id, name, loi, school);
            count++;
        }
    }
    inputFile.close();

    BUList.sortById();

    inputFile.open("proj5-BUAthlete.csv");
    if (!inputFile) {
        cerr << "Bad File" << endl;
        return -1;
    }
    while (!inputFile.eof()) {
        inputFile >> id;
        inputFile.ignore();
        getline(inputFile, posStr, ',');
        inputFile >> eval;
        if (posStr == "OL") {
            pos = OL;
        } else if (posStr == "QB") {
            pos = QB;
        } else if (posStr == "RB") {
            pos = RB;
        } else if (posStr == "WR") {
            pos = WR;
        } else if (posStr == "TE") {
            pos = TE;
        } else if (posStr == "DL") {
            pos = DL;
        } else if (posStr == "DE") {
            pos = DE;
        } else if (posStr == "LB") {
            pos = LB;
        } else if (posStr == "CB") {
            pos = CB;
        } else if (posStr == "S") {
            pos = S;
        } else if (posStr == "K") {
            pos = K;
        }
        BUList.setBUInfo(id, pos, eval);
    }
    inputFile.close();

    BUList.sortByEvaluation();
    BUList.sortByPosition();

    cout << BUList.toString();

    return 0;
}