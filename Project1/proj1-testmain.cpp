/**
 * file:   proj1-testmain.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Project 1
 * due date: 1/26/2022
 *
 * date modified: 1/25/2022
 *     - Tested for:
 *         = getAPersonFromStream function
 *         = displayAPerson function w/ Person array
 *         = displayAPerson function w/ Person pointer array
 *         = sortPersonArrayByAge function
 *         = sortPersonArrayByName function
 *         = findAPerson function
 *
 * This will test the functions in proj1-person.hpp
 */

#include "proj1-person.hpp"
#include <sstream>

const int SIZE = 25;

int main() {
    Person thePeople[SIZE];  //Person array to store Person objects
    Person *referenceToThePeople[SIZE];  //Person * array to point to Person array
    Person *aPersonFound;  //Person * object for findAPerson
    stringstream str;  //stringstream to represent getting a person data
    string s;  //string to get name from user
    int personCount = 0;  //int to count the number of person records recorded

    //Test for getAPersonFromStream function
    cout << "Testing getAPersonFromStream function..." << endl;
    cout << "Adding \"Jacob Armstrong, 25\" to stringstream str..." << endl;
    str.clear();
    str << "Jacob Armstrong, 25";
    getAPersonFromStream(str, &thePeople[0]);
    personCount++;

    cout << "Result should be: Jacob Armstrong 25" << endl;
    cout << "Result is:        " << thePeople[0].name << " " << thePeople[0].age << endl;
    cout << endl;

    //Test for displayAPerson function
    cout << "Testing displayAFunction..." << endl;
    cout << "Result should be: Jacob Armstrong, 25" << endl;
    cout << "Result is:        ";
    displayAPerson(cout, &thePeople[0]);
    cout << endl;

    //Points the person pointer array to the person array
    for (int i = 0; i < SIZE; i++) {
        referenceToThePeople[i] = &thePeople[i];
    }

    //Test for sortPersonArrayByAge function
    cout << "Adding \"Jerry Mouse, 69\" to thePeople[1]..." << endl;
    str.clear();
    str << "Jerry Mouse, 69";
    getAPersonFromStream(str, &thePeople[1]);
    personCount++;
    cout << "thePeople[1] has: ";
    displayAPerson(cout, referenceToThePeople[1]);
    cout << endl;

    cout << "Adding \"Adam Sandler, 25\" to thePeople[2]..." << endl;
    str.clear();
    str << "Adam Sandler, 25";
    getAPersonFromStream(str, &thePeople[2]);
    personCount++;
    cout << "thePeople[2] has: ";
    displayAPerson(cout, referenceToThePeople[2]);
    cout << endl;

    cout << "Adding \"Jacob Rodriguez, 21\" to thePeople[3]..." << endl;
    str.clear();
    str << "Jacob Rodriguez, 21";
    getAPersonFromStream(str, &thePeople[3]);
    personCount++;
    cout << "thePeople[3] has: ";
    displayAPerson(cout, referenceToThePeople[3]);
    cout << endl;

    cout << "Adding \"Zed, 10\" to thePeople[4]..." << endl;
    str.clear();
    str << "Zed, 10";
    getAPersonFromStream(str, &thePeople[4]);
    personCount++;
    cout << "thePeople[4] has: ";
    displayAPerson(cout, referenceToThePeople[4]);
    cout << endl << endl;

    cout << "Before the array is sorted by age:" << endl;
    for (int i = 0; i < personCount; i++) {
        displayAPerson(cout, referenceToThePeople[i]);
        cout << endl;
    }
    cout << "Number of people in the array: " << personCount << endl;
    cout << endl;

    cout << "Array should be:" << endl;
    cout << "Zed, 10" << endl;
    cout << "Jacob Rodriguez, 21" << endl;
    cout << "Adam Sandler, 25" << endl;
    cout << "Jacob Armstrong, 25" << endl;
    cout << "Jerry Mouse, 69" << endl;
    cout << endl;

    cout << "Sorting array..." << endl << endl;

    sortPersonArrayByAge(referenceToThePeople, personCount);

    cout << "After the array is sorted:" << endl;
    for (int i = 0; i < personCount; i++) {
        displayAPerson(cout, referenceToThePeople[i]);
        cout << endl;
    }
    cout << endl;

    //Testing for sortPersonArrayByAge
    cout << "Before the array is sorted by name:" << endl;
    for (int i = 0; i < personCount; i++) {
        displayAPerson(cout, referenceToThePeople[i]);
        cout << endl;
    }
    cout << endl;

    cout << "What the array should be after sorting:" << endl;
    cout << "Adam Sandler, 25" << endl;
    cout << "Jacob Armstrong, 25" << endl;
    cout << "Jacob Rodriguez, 21" << endl;
    cout << "Jerry Mouse, 69" << endl;
    cout << "Zed, 10" << endl << endl;

    cout << "Sorting array..." << endl << endl;
    sortPersonArrayByName(referenceToThePeople, personCount);

    cout << "After the array is sorted:" << endl;
    for (int i = 0; i < personCount; i++) {
        displayAPerson(cout, referenceToThePeople[i]);
        cout << endl;
    }
    cout << endl;

    //Testing for findAPerson function
    cout << "Testing findAPerson function:" << endl;
    cout << "Searching for \"Hannah Montana\":" << endl;
    cout << "Expected result:";
    cout << "No person was found." << endl;
    cout << "Result:";
    s = "Hannah Montana";
    aPersonFound = findAPerson(referenceToThePeople, personCount, s);
    if (aPersonFound == nullptr) {
        cout << "No person was found." << endl;
    }
    else {
        cout << "Person found: ";
        displayAPerson(cout, aPersonFound);
    }

    cout << "Searching for \"Jacob Armstrong\":" << endl;
    cout << "Expected result: ";
    cout << "Jacob Armstrong, 25" << endl;
    cout << "Result:";
    s = "Jacob Armstrong";
    aPersonFound = findAPerson(referenceToThePeople, personCount, s);
    if (aPersonFound == nullptr) {
        cout << "No person was found." << endl;
    }
    else {
        cout << "Person found: ";
        displayAPerson(cout, aPersonFound);
    }

    return 0;
}