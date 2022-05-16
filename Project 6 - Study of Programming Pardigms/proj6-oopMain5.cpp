/**
 * file: proj6-oopMain5.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 6 - Study of Programming Pardigms
 * due date: 3/28/2022
 *
 * date modified: 3/27/2022
 *    - File was created
 *    - tested the proj6-sequentialMain3.cpp
 *    - Adapted the solution from proj6-oopMain4.cpp
 *
 * date modified: 3/27/2022
 *    - added comments
 *
 * Changed the solution from proj6-oopMain5.cpp into a program
 * without inheritance and polymorphism
 */

#include <iostream>
#include <fstream>

using namespace std;

const int PLIST_SIZE = 10;

class Person {
protected:
    string name;  //Name of the person
    int age;      //Age of the person

public:
    string getPersonName() { return name; }
    void readPerson( istream & );
    void writePerson( ostream & );
};

/**
 * readPerson
 *
 * Gets data from an input to put into a person's data
 *
 * Parameters:
 *     in:   input stream
 *
 * Output:
 *      return: none
 *      reference parameters: in
 *      stream: none
 */
void Person::readPerson( istream &in ) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
}

/**
 * writePerson
 *
 * Outputs the data of a person
 *
 * Parameters:
 *     out:  output stream
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void Person::writePerson( ostream &out ) {
    out << name << endl;
    out << age << endl;
}

class Customer {
protected:
    string name;
    int age;
    double shippingRate;

public:
    string getCustomerName() { return name; };
    double getCustomerShippingRate() { return shippingRate; };
    void readCustomer( istream & );
    void writeCustomer( ostream & );
};

/**
 * readCustomer
 *
 * Gets data from an input to put into a customer's data
 *
 * Parameters:
 *     in:   input stream
 *
 * Output:
 *      return: none
 *      reference parameters: in
 *      stream: none
 */
void Customer::readCustomer( istream &in ) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
    in >> shippingRate;
    in.ignore(3, '\n');
}

/**
 * writeCustomer
 *
 * Outputs the data of a customer
 *
 * Parameters:
 *     out:  output stream
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void Customer::writeCustomer( ostream &out ) {
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
}

class MegaCustomer {
protected:
    string name;
    int age;
    double shippingRate;

public:
    MegaCustomer();
    string getMegaName() { return name; };
    double getMegaShippingRate() { return shippingRate; };
    void readMegaCustomer( istream & );
    void writeMegaCustomer( ostream & );
};

MegaCustomer::MegaCustomer() {
    shippingRate = 0;
}

/**
 * readMegaCustomer
 *
 * Gets data from an input to put into a mega customer's data
 *
 * Parameters:
 *     in:   input stream
 *
 * Output:
 *      return: none
 *      reference parameters: in
 *      stream: none
 */
void MegaCustomer::readMegaCustomer( istream &in ) {
    getline( in, name );
    in >> age;
    in.ignore(3, '\n');
}

/**
 * writeMegaCustomer
 *
 * Outputs the data of a mega customer
 *
 * Parameters:
 *     out:  output stream
 *
 * Output:
 *      return: none
 *      reference parameters: out
 *      stream: none
 */
void MegaCustomer::writeMegaCustomer( ostream &out ) {
    out << name << endl;
    out << age << endl;
    out << shippingRate << endl;
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
int findPerson( Person pList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( pList[index].getPersonName() == name ) {
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
int findCustomer( Customer cList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( cList[index].getCustomerName() == name ) {
            pos = index;
        }
        index++;
    }

    return pos;
}

/**
 * findMegaCustomer
 *
 * Finds index of a mega customer's name to see if their data
 * is valid
 *
 * Parameters:
 *     mList: list of mega customer's names
 *     name:  the name to be found
 *
 * Output:
 *      return: int
 *      reference parameters: none
 *      stream: none
 */
int findMegaCustomer( MegaCustomer mList[], string name ) {
    int pos = -1, index = 0;

    while( pos == -1 && index < PLIST_SIZE ) {
        if( mList[index].getMegaName() == name ) {
            pos = index;
        }
        index++;
    }

    return pos;
}

int main() {
    Person *pList = new Person [PLIST_SIZE];
    Customer *cList = new Customer [PLIST_SIZE];
    MegaCustomer *mList = new MegaCustomer [PLIST_SIZE];
    string choice, pTypeChoice, msg = "Please enter your name followed by your age.";
    int index = 0;
    bool fileRead = false;
    ifstream pfile;
    ofstream opfile;

    //Asks user where the data is coming from
    cout << "Would you like to read the data from a file (yes/no)? " << endl;
    cin >> choice;
    cin.ignore(3, '\n');

    //If data is coming from a file...
    if( choice == "yes" ) {
        fileRead = true;
        pfile.open("iperson.txt");
        if( !pfile ) {
            cerr << "Can't open person.txt for read." << endl;
            return 1;
        }
        pfile >> pTypeChoice;
        pfile.ignore(3, '\n');
    }
    else {      //If data is coming from user...
        cout << "What type of Person? (person/customer/mega)" << endl;
        cin >> pTypeChoice;
        cin.ignore(3, '\n');
    }

    opfile.open("operson.txt");

    choice = "yes";
    //If person type is person...
    if (pTypeChoice == "person") {
        //Checks for an empty file
        if( fileRead ) {
            if( !pfile ) {
                choice = "no";
            }
        }

        while( choice != "no" && index < PLIST_SIZE ) {
            //Asks user for data
            if( !fileRead ) {
                requestInfo( cout, msg );
                pList[index].readPerson( cin );
            }
            else {
                //Gets data from file
                pList[index].readPerson( pfile );
            }

            //Outputs data to output file
            pList[index].writePerson( opfile );

            index++;
            //Checks to see if more data is to be inputted
            if( !fileRead ) {
                choice = readAgain( cout, cin );
            } else {
                if( !pfile ) {
                    choice = "no";
                }
            }
        }

        //Close files
        if( fileRead ) {
            pfile.close();
        }
        opfile.close();

        //Searches for person
        cout << "Which person are you looking for? " << endl;
        getline( cin, choice );

        if( (index = findPerson( pList, choice )) != -1 ) {
            cout << "Found your person: " << endl;
            pList[index].writePerson( cout );
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }
    else if (pTypeChoice == "customer") {       //If person type is a customer
        msg = "Please enter your name followed by your age then shipping rate.";
        //Checks for empty file
        if( fileRead ) {
            if( !pfile ) {
                choice = "no";
            }
        }

        while( choice != "no" && index < PLIST_SIZE ) {
            //Gets data from user
            if( !fileRead ) {
                requestInfo( cout, msg );
                cList[index].readCustomer( cin );
            }
            //Gets data from file
            else {
                cList[index].readCustomer( pfile );
            }

            //Outputs data to output file
            cList[index].writeCustomer( opfile );

            index++;
            //Checks to see if more data is to be inputted
            if( !fileRead ) {
                choice = readAgain( cout, cin );
            } else {
                if( !pfile ) {
                    choice = "no";
                }
            }
        }

        //Close files
        if( fileRead ) {
            pfile.close();
        }
        opfile.close();

        //Searches for customer
        cout << "Which person are you looking for? " << endl;
        getline( cin, choice );

        if( (index = findCustomer( cList, choice )) != -1 ) {
            cout << "Found your person: " << endl;
            cList[index].writeCustomer( cout );
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }
    else {
        //Checks for empty file
        if( fileRead ) {
            if( !pfile ) {
                choice = "no";
            }
        }

        while( choice != "no" && index < PLIST_SIZE ) {
            //Gets data from user
            if( !fileRead ) {
                requestInfo( cout, msg );
                mList[index].readMegaCustomer( cin );
            }
            //Or gets data from file
            else {
                mList[index].readMegaCustomer( pfile );
            }

            //Outputs data to an output file
            mList[index].writeMegaCustomer( opfile );

            index++;
            //Checks to see if more data is to be inputted
            if( !fileRead ) {
                choice = readAgain( cout, cin );
            } else {
                if( !pfile ) {
                    choice = "no";
                }
            }
        }

        //Close files
        if( fileRead ) {
            pfile.close();
        }
        opfile.close();

        //Searches for a mega customer
        cout << "Which person are you looking for? " << endl;
        getline( cin, choice );

        if( (index = findMegaCustomer( mList, choice )) != -1 ) {
            cout << "Found your person: " << endl;
            mList[index].writeMegaCustomer( cout );
        } else {
            cout << "Couldn't find your person: " << choice << endl;
        }
    }

    delete [] pList;
    delete [] cList;
    delete [] mList;

    return 0;
}