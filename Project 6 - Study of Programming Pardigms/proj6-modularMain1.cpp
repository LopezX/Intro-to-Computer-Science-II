/**
 * file: proj6-modularMain1.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/27/2022
 *    - File was created
 *    - tested proj6-modularMain1.cpp
 *
 * A simple program that ask a user for their name and age and
 * prints it back to the screen, using functions outside of the
 * main
 */

#include <iostream>

using namespace std;

void readPerson( istream &in, string &name, int &age ) {
    getline( in, name );
    in >> age;
}

void requestInfo( ostream &out ) {
    out << "Please enter your name followed by your age." << endl;
}

void displayPerson( ostream &out, string name, int age ) {
    out << "Your name is: " << name << endl;
    out << "You are " << age << " years old" << endl;
}

string readAgain( ostream &out, istream &in ) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

int main() {
    string name;
    int age;
    string choice = "yes";

    while( choice != "no" ) {
        requestInfo( cout );
        readPerson( cin, name, age );
        displayPerson( cout, name, age );
        choice = readAgain( cout, cin );
    }

    return 0;
}