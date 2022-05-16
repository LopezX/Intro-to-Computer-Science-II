/**
 * file: proj5-BUAthlete.hpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *    - BUAthlete class was defined
 *
 * date modified: 3/11/2022
 *    - BUAthlete function comments edited
 *
 * Defines the BUAthlete class.
 */

#ifndef PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETE_HPP
#define PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETE_HPP

#include "proj5-NCAAAthlete.hpp"

enum Position {OL, QB, RB, WR, TE, DL, DE, LB, CB, S, K};

class BUAthlete : public NCAAAthlete {
protected:
    int evaluation;
    Position bestFit;

public:
    /**
     * setEvaluation
     *
     * setEvaluation stores the passed parameter in the evaluation data member
     *
     * Parameters:
     *      eval:  the number to store in the evaluation data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setEvaluation(int eval);

    /**
     * setPosition
     *
     * setPosition stores the passed parameter in the Position data member
     *
     * Parameters:
     *      pos:  the number to store in the Position data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setPosition(Position pos);

    /**
     * getEvaluation
     *
     * getEvaluation returns the evaluation data member
     *
     * Parameters: none
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    int getEvaluation();

    /**
     * getPosition
     *
     * getPosition returns the Position data member
     *
     * Parameters: none
     *
     * Output:
     *      return: Position
     *      reference parameters: none
     *      stream: none
     */
    Position getPosition();

    /**
     * toString
     *
     * converts an instance of a BUAthlete into a string representation
     *
     * Parameters: none
     *
     * Output:
     *      return: a string representation of the object
     *      reference parameters: none
     *      stream: none
     */
    string toString();
};
#endif //PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETE_HPP
