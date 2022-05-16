/**
 * file:  proj3-testMain.cpp
 * author:  Xavier Lopez
 * course: CSI 1440 02
 * assignment:  Project 3
 * due date:  2/14/2021
 *
 * date modified:  2/10/2022
 *      - proj3-MyString.cpp was created
 *
 * date modified:  2/13/2022
 *      - Tested functions in .h file:
 *            - MyString (const char*)
 *            - ~MyString
 *            - MyString (const MyString&)
 *            - operator =
 *            - operator ==
 *            - operator []
 *            - operator <<
 *
 * date modified:  2/14/2022
 *       - Tested functions in .h file:
 *            - operator +=
 *            - operator +
 *            - getline
 *
 * This file tests the function of the MyString class
 */

#include <iostream>
#include <sstream>
#include "proj3-MyString.h"

using namespace std;

int main() {
    //Initialize MyString with default and character string
    MyString a;
    MyString b("Hello World! My name is Carl! What is yours?");
    MyString c("427820497");
    MyString d("");

    //Print a default constructor MyString contents and length
    cout << "Initialized MyString a with default constructor." << endl;
    cout << "MyString a has: " << a << endl << endl;
    cout << "MyString a length is: " << a.length() << endl;

    //Print a character string constructor MyString contents and length
    cout << "Initialized MyString b, c and d with const char* parameter.";
    cout << endl;
    cout << "MyString b has: " << b << endl;
    cout << "MyString b length is: " << b.length() << endl;
    cout << "MyString c has: " << c << endl;
    cout << "MyString c length is: " << c.length() << endl;
    cout << "MyString d has: " << d << endl;
    cout << "MyString d length is: " << d.length() << endl;
    cout << endl;

    //Test the copy constructor
    cout << "Testing MyString copy constructor:" << endl;
    cout << "Initializing MyString e with contents a..." << endl;
    MyString e(a);
    cout << "MyString e has: " << e << endl;
    cout << "MyString e length is: " << e.length() << endl;

    cout << "Initializing MyString f with contents b..." << endl;
    MyString f(b);
    cout << "MyString f has: " << f << endl;
    cout << "MyString f length is: " << f.length() << endl;

    cout << "Initializing MyString g with contents c..." << endl;
    MyString g(c);
    cout << "MyString g has: " << g << endl;
    cout << "MyString g length is: " << g.length() << endl;

    cout << "Initializing MyString h with contents d..." << endl;
    MyString h(d);
    cout << "MyString h has: " << h << endl;
    cout << "MyString h length is: " << h.length() << endl;

    cout << "End of copy constructor test." << endl << endl;

    //Test the '=' operator
    cout << "Testing MyString = operator" << endl;
    cout << "Setting e = b..." << endl;
    e = b;
    cout << "MyString e has: " << e << endl;
    cout << "MyString e length is: " << e.length() << endl;

    cout << "Setting f = a..." << endl;
    f = a;
    cout << "MyString f has: " << f << endl;
    cout << "MyString f length is: " << f.length() << endl;

    cout << "Setting g = c..." << endl;
    g = c;
    cout << "MyString g has: " << g << endl;
    cout << "MyString g length is: " << g.length() << endl;

    cout << "Setting h = d..." << endl;
    h = d;
    cout << "MyString h has: " << h << endl;
    cout << "MyString h length is: " << h.length() << endl;
    cout << "End of \'=\' operator test." << endl << endl;

    //Test the "==" operator
    cout << "Testing == operator:" << endl;
    cout << "a == e?" << endl;
    if (a == e) {
        cout << "MyString a is the same as MyString e." << endl;
    }
    else {
        cout << "MyString a is not the same as MyString e." << endl;
    }

    cout << "b == e?" << endl;
    if (b == e) {
        cout << "MyString b is the same as MyString e." << endl;
    }
    else {
        cout << "MyString b is not the same as MyString e." << endl;
    }

    cout << "a == a?" << endl;
    if (a == a) {
        cout << "MyString a is the same as MyString a." << endl;
    }
    else {
        cout << "MyString a is not the same as MyString a." << endl;
    }

    cout << "a == h?" << endl;
    if (a == h) {
        cout << "MyString a is the same as MyString h." << endl;
    }
    else {
        cout << "MyString a is not the same as MyString h." << endl;
    }
    cout << "End of == operator." << endl << endl;

    //Test the [] operator
    cout << "Testing [] operator:" << endl;
    cout << "MyString a[0] should be: " << '\0' << endl;
    cout << "MyString a[0] is: " << a[0] << endl;
    cout << "MyString b[5] should be: " << ' ' << endl;
    cout << "MyString b[5] is: " << b[5] << endl;
    cout << "MyString e[43] should be: " << '?' << endl;
    cout << "MyString e[43] is: " << e[43] << endl;
    cout << "MyString c[3] should be: " << '8' << endl;
    cout << "MyString c[3] is: " << c[3] << endl;
    cout << "End of [] operator test." << endl << endl;

    //Test the += operator
    cout << "Testing += operator:" << endl;
    a += b;
    cout << "a += b is: " << a << endl;
    cout << "a length is: " << a.length() << endl;
    b += b;
    cout << "b += b is: " << b << endl;
    b += c;
    cout << "b += c is: " << b << endl;
    cout << "End of += operator test." << endl << endl;

    //Test the + operator
    cout << "Testing + operator:" << endl;
    d = d + c;
    cout << "d = d + c = " << d << endl;
    h = c + c;
    cout << "h = c + c = " << h << endl;
    f = b + c + b + c;
    cout << "f = b + c + b + c = " << f << endl;
    cout << "End of + operator test." << endl << endl;

    //Test the getline operator
    cout << "Testing getline function:" << endl;

    // Note: if getline was used with cin as input, then delimit would not
    // be overridden
    stringstream inSS;
    inSS.clear();
    inSS.str("Happy Days!\0");
    cout << "inSS has \"Happy Days!\" in it." << endl;
    cout << "Calling getline for MyString f..." << endl;
    f.getline(inSS, '\0');
    cout << "MyString f is: " << f << endl;

    inSS.clear();
    inSS.str("\0");
    cout << "inSS has \"\" in it." << endl;
    cout << "Calling getline for MyString h..." << endl;
    h.getline(inSS, '\0');
    cout << "MyString h is: " << h << endl;

    inSS.clear();
    inSS.str("428937498");
    cout << "inSS has \"428937498\" in it." << endl;
    cout << "Calling getline for MyString e..." << endl;
    e.getline(inSS, '\0');
    cout << "MyString e is: " << e << endl;

    inSS.clear();
    inSS.str("RUSH EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
    cout << "inSS has \"";
    cout << "RUSH EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE\"";
    cout << " in it." << endl;
    cout << "Calling getline for MyString e..." << endl;
    e.getline(inSS, '\0');
    cout << "MyString e is: " << e << endl;
    cout << "End of getline function test." << endl;

    return 0;
}
