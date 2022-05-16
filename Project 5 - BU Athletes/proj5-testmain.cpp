/**
 * file: proj5-testmain.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *
 * date modified: 3/20/2022
 *    - Tested the NCAAAthlete class and its functions
 *    - Tested the BUAthlete class and its functions
 *
 * date modified: 3/21/2022
 *    - Tested the BUAthleteList class and its functions
 *
 * Tests the classes and their functions to ensure they work
 * properly for the main.
 */

#include "proj5-BUAthleteList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main () {
    //Testing NCAAAthlete and its functions
    NCAAAthlete anNCAA1;
    NCAAAthlete anNCAA2;

    anNCAA1.setID(1234);
    anNCAA1.setName("Xavier Lopez");
    anNCAA1.setLOI("yes");
    anNCAA1.setSchool("Baylor");

    anNCAA2.setID(4321);
    anNCAA2.setName("Nathan Lopez");
    anNCAA2.setLOI("no");
    anNCAA2.setSchool("University of Texas");

    cout << "NCAA Athlete " << anNCAA1.getName();
    cout << ", ID " << anNCAA1.getID() << ", ";
    if (anNCAA1.getLOI()) {
        cout << "does ";
    }
    else {
        cout << "doesn't ";
    }
    cout << " have an LOI. They are interested in ";
    cout << anNCAA1.getSchool();
    cout << anNCAA1.toString() << endl;

    cout << "NCAA Athlete " << anNCAA2.getName();
    cout << ", ID " << anNCAA2.getID() << ", ";
    if (anNCAA2.getLOI()) {
        cout << "does ";
    }
    else {
        cout << "doesn't ";
    }
    cout << " have an LOI. They are interested in ";
    cout << anNCAA2.getSchool();
    cout << anNCAA2.toString() << endl;


    //Testing BUAthlete class and its functions
    BUAthlete aBUAth1;
    BUAthlete aBUAth2;

    aBUAth1.setID(anNCAA1.getID());
    aBUAth1.setName(anNCAA1.getName());
    aBUAth1.setLOI("yes");
    aBUAth1.setSchool(anNCAA1.getSchool());
    aBUAth1.setEvaluation(10);
    aBUAth1.setPosition(TE);

    cout << aBUAth1.getName() << "\'s evaluation in the ";
    switch (aBUAth1.getPosition()) {
        case 0:
            cout << "OL";
            break;
        case 1:
            cout << "QB";
            break;
        case 2:
            cout << "RB";
            break;
        case 3:
            cout << "WR";
            break;
        case 4:
            cout << "TE";
            break;
        case 5:
            cout << "DL";
            break;
        case 6:
            cout << "DE";
            break;
        case 7:
            cout << "LB";
            break;
        case 8:
            cout << "CB";
            break;
        case 9:
            cout << "S";
            break;
        case 10:
            cout << "K";
            break;
    }
    cout << " position is " << aBUAth1.getEvaluation() << endl;
    cout << aBUAth1.toString() << endl;

    aBUAth2.setID(5263);
    aBUAth2.setName("John Denver");
    aBUAth2.setLOI("no");
    aBUAth2.setSchool("UTSA");
    aBUAth2.setEvaluation(3);
    aBUAth2.setPosition(WR);

    cout << aBUAth2.getName() << "\'s evaluation in the ";
    switch (aBUAth2.getPosition()) {
        case 0:
            cout << "OL";
            break;
        case 1:
            cout << "QB";
            break;
        case 2:
            cout << "RB";
            break;
        case 3:
            cout << "WR";
            break;
        case 4:
            cout << "TE";
            break;
        case 5:
            cout << "DL";
            break;
        case 6:
            cout << "DE";
            break;
        case 7:
            cout << "LB";
            break;
        case 8:
            cout << "CB";
            break;
        case 9:
            cout << "S";
            break;
        case 10:
            cout << "K";
            break;
    }
    cout << " position is " << aBUAth2.getEvaluation() << endl;
    cout << aBUAth2.toString() << endl;

    //Test BUAthleteList class and its functions
    ifstream inputFile;
    string name, loi, school, posStr;
    stringstream inSS;
    BUAthleteList BUList;
    int id, prevID, eval;
    Position pos;
    char c;
    bool firstInput = true;  //This is due to there being trash at beginning of file

    inputFile.open("proj5-NCAAAthlete.csv");
    if (!inputFile) {
        cerr << "Bad File" << endl;
        return -1;
    }
    while (!inputFile.eof()) {
        if (firstInput) {
            inputFile >> c >> c >> c;
            firstInput = false;
        }
        prevID = id;
        inputFile >> id;
        inputFile.ignore();
        getline(inputFile, name, ',');
        getline(inputFile, loi, ',');
        getline(inputFile, school);
        if (prevID != id) {
            BUList.addNCAAAthlete(id, name, loi, school);
        }
    }
    inputFile.close();
    BUList.sortById();
    firstInput = true;
    inputFile.open("proj5-BUAthlete.csv");
    if (!inputFile) {
        cerr << "Bad File" << endl;
        return -1;
    }
    while (!inputFile.eof()) {
        if (firstInput) {
            inputFile >> c >> c >> c;
            firstInput = false;
        }
        inputFile >> id;
        inputFile.ignore();
        getline(inputFile, posStr, ',');
        inputFile >> eval;
        if (posStr == "OL") {
            pos = OL;
        }
        else if (posStr == "QB") {
            pos = QB;
        }
        else if (posStr == "RB") {
            pos = RB;
        }
        else if (posStr == "WR") {
            pos = WR;
        }
        else if (posStr == "TE") {
            pos = TE;
        }
        else if (posStr == "DL") {
            pos = DL;
        }
        else if (posStr == "DE") {
            pos = DE;
        }
        else if (posStr == "LB") {
            pos = LB;
        }
        else if (posStr == "CB") {
            pos = CB;
        }
        else if (posStr == "S") {
            pos = S;
        }
        else if (posStr == "K") {
            pos = K;
        }
        BUList.setBUInfo(id, pos, eval);
    }
    inputFile.close();
    BUList.sortByEvaluation();
    BUList.sortByPosition();
    cout << BUList.toString() << endl;

    return 0;
}