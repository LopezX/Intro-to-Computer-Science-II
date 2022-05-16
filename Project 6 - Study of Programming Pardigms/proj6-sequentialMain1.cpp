/**
 * file: proj6-sequentialMain1.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/26/2022
 *    - File was created
 *    - tested the proj6-sequentialMain1.cpp
 *
 * A simple program that ask a user for their name and age and
 * prints it back to the screen
 */

#include <iostream>

using namespace std;

int main() {
    string name;
    int age;

    cout << "What is your name? " << endl;
    getline( cin, name );

    cout << "How old are you? " << endl;
    cin >> age;

    cout << "Your name is: " << name << endl;
    cout << "You are " << age << " years old" << endl;

    return 0;
}