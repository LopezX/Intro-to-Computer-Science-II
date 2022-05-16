/**
 * file: proj6-modularMain3.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/27/2022
 *    - File was created
 *    - tested the proj6-sequentialMain3.cpp
 *    - Adapted the solution from proj6-oopMain2.cpp
 *
 * date modified: 3/28/2022
 *    - added comments
 *
 * Changed the solution from proj6-oopMain2.cpp into a modular
 * rather than a object oriented program solution
 */

#include <iostream>
#include <fstream>

using namespace std;

const int PLIST_SIZE = 10;

/**
 * readPerson
 *
 * Gets data for an input to put into a person's data
 *
 * Parameters:
 *     in:   input stream
 *     name: name of the person
 *     age:  age of the person
 *
 * Output:
 *      return: none
 *      reference parameters: in, name, age
 *      stream: none
 */
void readPerson( istream &in, string &name, int &age ) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
}

/**
 * writePerson
 *
 * Outputs data of a person to an output source
 *
 * Parameters:
 *     out:  output stream
 *     name: name of the person
 *     age:  age of the person
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void writePerson( ostream &out, string name, int age ) {
    out << name << endl;
    out << age << endl;
}

/**
 * requestInfo
 *
 * Prompts the user for what data to input
 *
 * Parameters:
 *     out:  output stream
 *     msg:  the message of what data to input
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void requestInfo( ostream &out, string msg ) {
    out << msg << endl;
}

/**
 * readAgain
 *
 * Asks user if they want to input more data
 *
 * Parameters:
 *     out:  output stream
 *     in:   input stream
 *
 * Output:
 *      return: string
 *      reference parameters: out, in
 *      stream: none
 */
string readAgain( ostream &out, istream &in ) {
    string choice;

    out << "Do you want to read in another person (yes/no)? " << endl;
    in >> choice;
    in.ignore(3, '\n');

    return choice;
}

/**
 * readCustomer
 *
 * Gets data from an input to put into a customer's data
 *
 * Parameters:
 *     in:   input stream
 *     name: name of the customer
 *     age:  age of the customer
 *     shippingRate: shipping rate of customer
 *
 * Output:
 *      return: none
 *      reference parameters: in, name, age, shippingRate
 *      stream: none
 */
void readCustomer( istream & in, string &name, int &age, double &shippingRate ) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
    in >> shippingRate;
    in.ignore(3, '\n');
}

/**
 * writeCustomer
 *
 * Outputs data of a customer to an output source
 *
 * Parameters:
 *     out:  output stream
 *     name: name of the customer
 *     age:  age of the customer
 *     shippingRate: shippingRate of the customer
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void writeCustomer( ostream & out, string name, int age, double shippingRate ) {
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

/**
 * findPerson
 *
 * Finds index of a person's name to see if their data
 * is valid
 *
 * Parameters:
 *     pList: list of person's names
 *     name:  the name to be found
 *
 * Output:
 *      return: int
 *      reference parameters: none
 *      stream: none
 */
int findPerson( string pList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( pList[index] == name ) {
            pos = index;
        }
        index++;
    }

    return pos;
}

/**
 * findCustomer
 *
 * Finds index of a customer's name to see if their data
 * is valid
 *
 * Parameters:
 *     cList: list of customer's names
 *     name:  the name to be found
 *
 * Output:
 *      return: int
 *      reference parameters: none
 *      stream: none
 */
int findCustomer( string pList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( pList[index] == name ) {
            pos = index;
        }
        index++;
    }

    return pos;
}

int main() {
    string names[PLIST_SIZE];
    int ages[PLIST_SIZE];
    double shippingRate[PLIST_SIZE];
    string choice, pTypeChoice;
    int index = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    //Asks user if they would like to get data from a file
    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    //If data is coming from a file...
    if (choice == "yes") {
        fileRead = true;
        pfile.open("iperson.txt");
        if (!pfile) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }

        pfile >> pTypeChoice;
        pfile.ignore(3, '\n');
    } else {    //If data is coming from user...
        cout << "What type of Person? (person/customer)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    //If the data is going to be persons...
    if( pTypeChoice == "person" ) {
        //Opens person output file
        opfile.open("operson.txt");
        choice = "yes";

        //Gets data from file
        if (fileRead) {
            readPerson(pfile, names[index], ages[index]);
            if (!pfile) {
                choice = "no";
            }
        }

        while (choice != "no" && index < PLIST_SIZE) {
            //Gets data from user
            if (!fileRead) {
                requestInfo(cout, "Please enter your name followed by your age.");
                readPerson(cin, names[index], ages[index]);
            }

            //Outputs data to output file
            writePerson(opfile, names[index], ages[index]);

            index++;

            //Checks to see if more data is to be inputted
            if (!fileRead) {
                choice = readAgain(cout, cin);
            } else {
                readPerson(pfile, names[index], ages[index]);
                if (!pfile) {
                    writePerson(opfile, names[index], ages[index]);
                    choice = "no";
                }
            }
        }

        //Close files
        if (fileRead) {
            pfile.close();
        }
        opfile.close();

        //Search for a person
        cout << "Which person are you looking for? " << endl;
        getline(cin, choice);

        if ((index = findPerson(names, choice)) != -1) {
            cout << "Found your person: " << endl;
            writePerson(cout, names[index], ages[index]);
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    } else {
        //Opens customer output file
        opfile.open("ocustomer.txt");
        choice = "yes";

        //Gets data from file
        if (fileRead) {
            readCustomer(pfile, names[index], ages[index], shippingRate[index]);
            if (!pfile) {
                choice = "no";
            }
        }

        while (choice != "no" && index < PLIST_SIZE) {
            //Gets data from user
            if (!fileRead) {
                requestInfo(cout, "Please enter your name followed by your age then shipping rate");
                readCustomer(cin, names[index], ages[index], shippingRate[index]);
            }

            //Outputs data to output file
            writeCustomer(opfile, names[index], ages[index], shippingRate[index]);

            index++;
            //Checks to see if more data is to be inputted
            if (!fileRead) {
                choice = readAgain(cout, cin);
            } else {
                readCustomer(pfile, names[index], ages[index], shippingRate[index]);
                if (!pfile) {
                    writeCustomer(opfile, names[index], ages[index], shippingRate[index]);
                    choice = "no";
                }
            }
        }

        //Close files
        if (fileRead) {
            pfile.close();
        }
        opfile.close();

        //Searches for a customer
        cout << "Which person are you looking for? " << endl;
        getline(cin, choice);

        if ((index = findCustomer(names, choice)) != -1) {
            cout << "Found your person: " << endl;
            writeCustomer(cout, names[index], ages[index], shippingRate[index]);
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }

    return 0;
}