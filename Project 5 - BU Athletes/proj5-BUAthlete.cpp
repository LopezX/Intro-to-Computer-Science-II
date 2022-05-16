/**
 * file: proj5-BUAthlete.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *    - Function names were inputted
 *    - Began to define functions (not tested):
 *        - setEvaluation
 *        - setPosition
 *        - getEvaluation
 *        - getPosition (not yet finished)
 *
 * date modified: 3/11/2022
 *    - Began to define functions (not tested):
 *        - getPosition
 *
 * date modified: 3/20/2022
 *    - Began to define functions (not tested):
 *        - toString
 *
 * Defines the functions within the BUAthlete class.
 */

#include "proj5-BUAthlete.hpp"
#include <sstream>

void BUAthlete::setEvaluation(int eval) {
    this->evaluation = eval;
}


void BUAthlete::setPosition(Position pos) {
    this->bestFit = pos;
}


int BUAthlete::getEvaluation() {
    return this->evaluation;
}


Position BUAthlete::getPosition() {
    return this->bestFit;
}


string BUAthlete::toString() {
    ostringstream out;

    out << NCAAAthlete::toString();

    out << "Evaluation: " << this->evaluation << endl;
    out << "Position: ";
    switch (this->bestFit) {
        case 0:
            out << "OL";
            break;
        case 1:
            out << "QB";
            break;
        case 2:
            out << "RB";
            break;
        case 3:
            out << "WR";
            break;
        case 4:
            out << "TE";
            break;
        case 5:
            out << "DL";
            break;
        case 6:
            out << "DE";
            break;
        case 7:
            out << "LB";
            break;
        case 8:
            out << "CB";
            break;
        case 9:
            out << "S";
            break;
        case 10:
            out << "K";
            break;
    }
    out << endl;

    return out.str();
}