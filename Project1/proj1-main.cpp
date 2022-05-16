/**
 * file:   proj1-main.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Project 1
 * due date: 1/26/2022
 *
 * date modified: 1/25/2022
 *     - modified the main
 *
 * This file:
 *     - will find a file named "people.dat"
 *     - Enter person names and age into Person array
 *     - Connect Person * array to Person array
 *     - Sort the Person * array by age
 *     - Display the first 5 people (if 5 exist)
 *     - Sort the Person * array by name
 *     - Display the first 5 people (if 5 exist)
 *     - Find and display a Person until “no more” is inputted by the user
 */

#include "proj1-person.hpp"
#include <sstream>
#include <fstream>

const int SIZE = 25;

int main() {
    ifstream inputFile;  //ifstream to get the data file
    Person thePeople[SIZE];  //Person array to store person objects
    Person *referenceToThePeople[SIZE];  //Person * array to point to the person array
    Person *aPerson;  //Person * object used in findAPerson
    stringstream inSS;  //stringstream to get data from data file
    string s;  //string to get name from user
    string data;  //string to get data from input file
    int personCount = 0;  //int to count number of person object recorded

    //Open data file "people.dat"
    inputFile.open("people.dat");

    //If file does not open...
    if (!inputFile) {
        //Print error message
        cout << "No input file was found." << endl;
    }
    //If file opens...
    else {
        //Read the person data out of the file
        while (!inputFile.eof() && personCount < 25) {
            //Clear string stream
            inSS.clear();

            //Gets a line from file and puts it in a stringstream
            getline(inputFile, data);
            if (data.size() > 1) {
                inSS << data;

                //Store data into the Person array
                getAPersonFromStream(inSS, &thePeople[personCount]);

                //Increments the person count
                personCount++;
            }
        }

        //Assign each Person object in Person array to a pointer in Person * array
        for (int i = 0; i < personCount; i++) {
            referenceToThePeople[i] = &thePeople[i];
        }

        //Sort Person * array by age and display first 5 persons (if there are 5)
        sortPersonArrayByAge(referenceToThePeople, personCount);
        cout << "List of people sorted by age:" << endl;
        if (personCount > 5) {
            for (int i = 0; i < 5; i++) {
                displayAPerson(cout, referenceToThePeople[i]);
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < personCount; i++) {
                displayAPerson(cout, referenceToThePeople[i]);
                cout << endl;
            }
        }
        cout << endl;

        //Sort Person * array by name and displays first 5 people (if there are 5)
        sortPersonArrayByName(referenceToThePeople, personCount);
        cout << "List of people sorted by name:" << endl;
        if (personCount > 5) {
            for (int i = 0; i < 5; i++) {
                displayAPerson(cout, referenceToThePeople[i]);
                cout << endl;
            }
        }
        else {
            for (int i = 0; i < personCount; i++) {
                displayAPerson(cout, referenceToThePeople[i]);
                cout << endl;
            }
        }
        cout << endl;

        //Allows user to find a person
        do {
            //Prompts user for a name and takes input
            cout << "Enter a name to find: ";
            getline(cin, s);

            //Looks for a person in the array
            aPerson = findAPerson(referenceToThePeople, personCount, s);

            //If person is not found...
            if (s != "no more") {
                if (aPerson == nullptr) {
                    //Prints a not found message
                    cout << "Person was not found." << endl;
                }
                    //If person is found...
                else {
                    //Prints person object data
                    displayAPerson(cout, aPerson);
                    cout << endl;
                }
            }
            cout << endl;
        } while (s != "no more");

        //End of program message
        cout << "Goodbye!" << endl;
    }

    return 0;
}