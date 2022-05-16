/**
 * file: proj5-BUAthleteList.hpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *    - BUAthleteList class was defined
 *
 * date modified: 3/11/2022
 *    - Added comments to the functions
 *
 * Defines the BUAthleteList class.
 */

#ifndef PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETELIST_HPP
#define PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETELIST_HPP

#include "proj5-BUAthlete.hpp"

class BUAthleteList {
protected:
    BUAthlete *list;
    int capacity;
    int size;
    void resizeArray();

public:
    /**
     * ~BUAthleteList
     *
     * BUAthleteList base constructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    BUAthleteList();

    /**
     * ~BUAthleteList
     *
     * BUAthleteList destructor
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    ~BUAthleteList();

    /**
     * BUAthleteList
     *
     * Copy constructor for BUAthleteList
     *
     * Parameters:
     *      otherList: a BUAthleteList object to be copied
     *
     * Output:
     *      return: none
     *      reference parameters: otherList
     *      stream: none
     */
    BUAthleteList(const BUAthleteList &otherList);

    /**
     * operator=
     *
     * BUAthleteList copy assignment constructor
     *
     * Parameters:
     *      otherList: a BUAthleteList object to be copied
     *
     * Output:
     *      return: none
     *      reference parameters: otherList
     *      stream: none
     */
    BUAthleteList& operator=(const BUAthleteList &otherList);

    /**
     * addNCAAAthlete
     *
     * stores the information from a file to the an NCAA athlete's information
     *
     * Parameters:
     *      id:     the number to store in the athlete ID data member
     *      name:   the string to store in the athlete name data member
     *      loi:    the bool to store in the athlete LOI data member
     *      school: the string to store in the athlete school data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void addNCAAAthlete(int id, string name, string loi, string school);

    /**
     * setBUInfo
     *
     * stores the information from a file into a BU athlete's information
     *
     * Parameters:
     *      index: the athlete's ID at which the information will be stored to
     *      pos:   the Position to store in the athlete Position data member
     *      eval:  the integer to store in the athlete evaluation data member
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void setBUInfo(int index, Position pos, int eval);

    /**
     * findBUId
     *
     * converts an instance of a BUAthleteList into a string representation
     *
     * Parameters:
     *      id: finds an athlete with the id given
     *
     * Output:
     *      return: int
     *      reference parameters: none
     *      stream: none
     */
    int findBUId(int id);

    /**
     * sortById
     *
     * sorts the list by increasing order of ID number (least to greatest)
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortById();

    /**
     * sortByPosition
     *
     * sorts the list by an athlete's position (least to greatest)
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortByPosition();

    /**
     * sortByEvaluation
     *
     * sorts the list by an athlete's evaluation (greatest to least)
     *
     * Parameters: none
     *
     * Output:
     *      return: none
     *      reference parameters: none
     *      stream: none
     */
    void sortByEvaluation();

    /**
     * operator[]
     *
     * references the BU Athlete at a specific index
     *
     * Parameters:
     *      ndx: the index of the BU Athlete
     *
     * Output:
     *      return: BUAthlete
     *      reference parameters: none
     *      stream: none
     */
    BUAthlete operator[](int ndx);

    /**
     * toString
     *
     * converts an instance of a BUAthleteList into a string representation
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

/**
 * QuicksortForID
 *
 * Quicksort function for BUAthleteList in terms of ID
 *
 * Parameters:
 *     i: the low of the sort
 *     j: the high of the sort
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void QuicksortForID(BUAthlete *list, int i, int k);


/**
 * PartitionForID
 *
 * Partition function for BUAthleteList in terms of ID
 *
 * Parameters:
 *     i: the low of the partition
 *     j: the high of the partition
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
int PartitionForID (BUAthlete *list, int i, int k);

/**
 * QuicksortForEvaluation
 *
 * Quicksort function for BUAthleteList in terms of evaluation
 *
 * Parameters:
 *     i: the low of the sort
 *     j: the high of the sort
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
void QuicksortForEvaluation(BUAthlete *list, int i, int k);

/**
 * PartitionForEvaluation
 *
 * Partition function for BUAthleteList in terms of evaluation
 *
 * Parameters:
 *     i: the low of the partition
 *     j: the high of the partition
 *
 * Output:
 *      return: none
 *      reference parameters: none
 *      stream: none
 */
int PartitionForEvaluation(BUAthlete *list, int i, int k);

#endif //PROJECT_5___BU_ATHLETES_PROJ5_BUATHLETELIST_HPP
