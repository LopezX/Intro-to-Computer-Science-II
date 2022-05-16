/**
 * file:   proj1-person.cpp
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Project 1
 * due date: 1/26/2022
 *
 * date modified: 1/25/2022
 *     - added definitions for functions:
 *         = istream &getAPersonFromStream(istream &, Person *)
 *         = sortPersonArrayByAge(Person **, int)
 *         = sortPersonArrayByName(Person **, int)
 *         = Person * findAPerson(Person *, int, string)
 *         = void displayAPerson(ostream &, const Person *)
 *
 * date modified: 1/26/2022
 *     -added function block comments
 *
 * This will define the functions in proj1-person.hpp
 */

#include "proj1-person.hpp"

/**
 * getAPersonFromStream
 *
 * This function gets data from an input stream to store the data into
 * the person object
 *
 * Parameters:
 *      str: the input stream to read the data out of
 *      p: person pointer where the data is stored
 *
 * Output:
 *      return:  the input stream
 *      reference parameters: none
 *      stream:  stringstream
 */
istream &getAPersonFromStream(istream &str, Person *p) {
    //Initialize string name and int age
    string name;
    int age;

    //Gets the name of the person and inserts in Person's name variable
    getline(str, name, ',');
    p->name = name;

    //Gets the age of the person and inserts in Person's age variable
    str.ignore();
    str >> age;
    p->age = age;

    return str;
}

/**
 * sortPersonArrayByAge
 *
 * This function sorts the Person * array by age
 *
 * Parameters:
 *      p: Person * array that is to be sorted
 *      x: the number of objects in person array
 *
 * Output:
 *      return:  void
 *      reference parameters: none
 *      stream:  none
 */
void sortPersonArrayByAge(Person **p, int x) {
    Person *temp;
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - 1 - i; j++) {
            if (p[j]->age > p[j+1]->age) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            else if (p[j]->age == p[j+1]->age) {
                if (p[j]->name > p[j+1]->name) {
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
}

/**
 * sortPersonArrayByName
 *
 * This function sorts the Person * array by names
 *
 * Parameters:
 *      p: Person * array that is sorted
 *      x: the number of objects in person array
 *
 * Output:
 *      return:  void
 *      reference parameters: none
 *      stream:  none
 */
void sortPersonArrayByName(Person **p, int x) {
    Person *temp;
    for (int i = 0; i < x - 1; i++) {
        for (int j = 0; j < x - 1 - i; j++) {
            if (p[j]->name > p[j+1]->name) {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
            else if (p[j]->name == p[j+1]->name) {
                if (p[j]->age > p[j+1]->age) {
                    temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
}

/**
 * findAPerson
 *
 * This function looks through the Person * array to find a Person object
 * with the same name as the user's input
 *
 * Parameters:
 *      p: Person ** that references a pointer to a Person object in the
 *         Person * array
 *      x: the number of objects in person array
 *      str: string of the name of the person to be found in the array
 *
 * Output:
 *      return:  Person *
 *      reference parameters: none
 *      stream:  none
 */
Person * findAPerson(Person **p, int x, string str) {
    Person *flag = nullptr;
    int i = 0;
    bool found = false;

    while (i < x && !found) {
        if (p[i]->name == str) {
            flag = p[i];
            found = true;
        }
        i++;
    }
    return flag;
}

/**
 * displayAPerson
 *
 * This function displays a Person object's data
 *
 * Parameters:
 *      o: output stream to display the data
 *      p: Person * to display the data
 *
 * Output:
 *      return:  void
 *      reference parameters: none
 *      stream:  cout
 */
void displayAPerson(ostream &o, const Person *p) {
    o << p->name << ", " << p->age;
}