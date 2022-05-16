/**
 * file: pointers2-4.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Lab 2 - Pointers 2
 * Due Date: 1/28/2022
 *
 * Date Modified: 1/24/2022
 *     - Typed the code under Creating and Accessing Dynamic Objects
 *
 * Creating and Accessing Dynamic Objects
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string *str = new string("Hello World!");

    // using the indirection operator to access the public interface of string
    cout << (*str).length() << endl;

    // using the structure pointer operator to access the public interface of string
    cout << str->length() << endl;

    delete str;

    return 0;
}