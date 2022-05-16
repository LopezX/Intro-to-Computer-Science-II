/**
 * file: proj6-sequentialMain3.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/27/2022
 *    - File was created
 *    - tested the proj6-sequentialMain3.cpp
 *    - Added ability to read input file and output file
 *
 * date modified: 3/28/2022
 *    - added comments
 *
 * Asks user whether they want to read from an input file,
 * and then outputs the data from the file (or the user, if
 * they did not want to use an input file) to and output file
 */

#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string name;
    int age;
    ifstream inFile;
    ofstream outFile;
    string choice;
    bool fileRead = false;

    //Prompts user for how to get data
    cout << "Would you like to read the data from a file? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    //If user wants data read from file
    if( choice == "yes") {
        fileRead = true;
        inFile.open("iperson.txt");
        if (!inFile ) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
    }

    outFile.open("operson.txt");

    //Gets data from file
    choice = "yes";
    if ( fileRead ) {
        getline( inFile, name );
        inFile >> age;
        inFile.ignore(3, '\n');
        if ( !inFile ) {
            choice = "no";
        }
    }

    //While the user's choice is no/ while data is read from file...
    while( choice != "no" ) {
        //If user is inputting file
        if ( !fileRead ) {
            cout << "Please enter your name followed by your age." << endl;
            getline( cin, name );
            cin >> age;
            cin.ignore(3, '\n');
        }

        //Outputs data to file
        outFile << name << endl;
        outFile << age << endl;

        //If user is inputting data, asks if wants to input more data
        if ( !fileRead ) {
            cout << "Do you want to read in another person (yes/no)? " << endl;
            cin >> choice;
            cin.ignore(3, '\n');
        }
        else {
            //Get more data from file
            getline(inFile, name);
            inFile >> age;
            inFile.ignore(3, '\n');
            if ( !inFile ) {
                //Output last data into file
                outFile << name << endl;
                outFile << age << endl;
                choice = "no";
            }
        }
    }

    //Close files
    if ( fileRead ) {
        inFile.close();
    }
    outFile.close();

    return 0;
}
