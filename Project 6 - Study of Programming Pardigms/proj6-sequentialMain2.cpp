/**
 * file: proj6-sequentialMain2.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/26/2022
 *    - File was created
 *    - tested the proj6-sequentialMain2.cpp
 *    - Difference from sequential
 *
 * A simple program that ask a user for their name and age and
 * prints it back to the screen, but repeats as long as the user
 * says "yes"
 */

#include <iostream>

using namespace std;

int main() {
    string name;
    int age;

    string choice = "yes";

    while( choice != "no" ) {
        cout << "What is your name? " << endl;
        getline( cin, name );

        cout << "How old are you? " << endl;
                             cin >> age;

        cout << "Your name is: " << name << endl;
        cout << "You are " << age << " years old" << endl;

        cout << "Do you want to read in another person (yes/no)? " << endl;
        cin >> choice;
        cin.ignore(3, '\n');
    }

    return 0;
}
