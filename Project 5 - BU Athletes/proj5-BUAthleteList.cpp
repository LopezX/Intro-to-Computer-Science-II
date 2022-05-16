/**
 * file: proj5-BUAthleteList.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 5 - BU Athletes
 * due date: 3/21/2022
 *
 * date modified: 3/9/2022
 *    - File was created
 *
 * date modified: 3/20/2022
 *    - Began to define functions:
 *        - BUAthleteList
 *        - BUAthleteList(copy constructor)
 *        - BUAthleteList(copy assignment constructor)
 *        - ~BUAthlete
 *        - resizeArray
 *        - addNCAAAthlete
 *        - setBUInfo
 *        - findBUId
 *        - toString
 *        - operator[]
 *        - sortById
 *        - sortByEvaluation
 *
 * date modified: 3/21/2022
 *    - Began to define functions:
 *        - QuicksortForID
 *        - QuicksortForEvaluation
 *        - PartitionForID
 *        - PartitionForEvaluation
 *        - sortByPosition
 *
 *
 * Defines the functions within the BUAthleteList class.
 */

#include "proj5-BUAthleteList.hpp"
#include <sstream>

BUAthleteList::BUAthleteList() {
    this->capacity = 2;
    this->size = 0;
    this->list = new BUAthlete [this->capacity];
}

BUAthleteList::~BUAthleteList() {
    delete [] list;
}

BUAthleteList::BUAthleteList(const BUAthleteList &otherList) {
    this->capacity = otherList.capacity;
    this->size = otherList.size;
    this->list = new BUAthlete [this->capacity];

    for (int i = 0; i < this->size; i++) {
        this->list[i].setID(otherList.list[i].getID());
        this->list[i].setName(otherList.list[i].getName());
        if (otherList.list[i].getLOI()) {
            this->list[i].setLOI("yes");
        }
        else {
            this->list[i].setLOI("no");
        }
        this->list[i].setSchool(otherList.list[i].getSchool());
        this->list[i].setEvaluation(otherList.list[i].getEvaluation());
        this->list[i].setPosition(otherList.list[i].getPosition());
    }
}

BUAthleteList& BUAthleteList::operator=(const BUAthleteList &otherList) {
    if (this != &otherList) {
        this->capacity = otherList.capacity;
        this->size = otherList.size;
        this->list = new BUAthlete[this->capacity];

        for (int i = 0; i < this->size; i++) {
            this->list[i] = otherList.list[i];
        }
    }

    return *this;
}

void BUAthleteList::resizeArray() {
    BUAthlete *oldList = new BUAthlete [this->capacity];
    for (int i = 0; i < this->size; i++ ) {
        oldList[i] = this->list[i];
    }
    delete [] this->list;
    this->capacity += 2;
    this->list = new BUAthlete [this->capacity];
    for (int i = 0; i < this->size; i++) {
        this->list[i] = oldList[i];
    }
}

void BUAthleteList::addNCAAAthlete(int id, string name, string loi, string school) {
    if (this->size + 1 > this->capacity) {
        resizeArray();
    }
    this->list[this->size].setID(id);
    this->list[this->size].setName(name);
    this->list[this->size].setLOI(loi);
    this->list[this->size].setSchool(school);
    this->size++;
}


void BUAthleteList::setBUInfo(int index, Position pos, int eval) {
    int loc = findBUId(index);

    if (loc >= 0) {
        this->list[loc].setPosition(pos);
        this->list[loc].setEvaluation(eval);
    }
}


int BUAthleteList::findBUId(int id) {
    int mid = 0;
    int low = 0;
    int high = this->size - 1;

    while (high >= low) {
        mid = ( high + low ) / 2;
        if (this->list[mid].getID() > id) {
            high = mid - 1;
        }
        else if (this->list[mid].getID() < id) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}


void BUAthleteList::sortById() {
    QuicksortForID(this->list, 0, this->size - 1);
}


void BUAthleteList::sortByPosition() {
    BUAthlete temp;
    for (int i = 0; i < this->size - 1; i++) {
        for (int j = 0; j < this->size - i - 1; j++) {
            if (this->list[j].getPosition() > this->list[j+1].getPosition()) {
                //Copy list[j] to temp
                temp.setID(list[j].getID());
                temp.setName(list[j].getName());
                if(list[j].getLOI()) {
                    temp.setLOI("yes");
                }
                else {
                    temp.setLOI("no");
                }
                temp.setSchool(list[j].getSchool());
                temp.setPosition(list[j].getPosition());
                temp.setEvaluation(list[j].getEvaluation());

                //Copy list[j+1] to list[j]
                list[j].setID(list[j+1].getID());
                list[j].setName(list[j+1].getName());
                if(list[j+1].getLOI()) {
                    list[j].setLOI("yes");
                }
                else {
                    list[j].setLOI("no");
                }
                list[j].setSchool(list[j+1].getSchool());
                list[j].setPosition(list[j+1].getPosition());
                list[j].setEvaluation(list[j+1].getEvaluation());

                //Copy temp to list[j+1]
                list[j+1].setID(temp.getID());
                list[j+1].setName(temp.getName());
                if(temp.getLOI()) {
                    list[j+1].setLOI("yes");
                }
                else {
                    list[j+1].setLOI("no");
                }
                list[j+1].setSchool(temp.getSchool());
                list[j+1].setPosition(temp.getPosition());
                list[j+1].setEvaluation(temp.getEvaluation());
            }
        }
    }
}


void BUAthleteList::sortByEvaluation() {
    QuicksortForEvaluation(this->list, 0, this->size - 1);
}


BUAthlete BUAthleteList::operator[](int ndx) {
    return this->list[ndx];
}


string BUAthleteList::toString() {
    ostringstream out;
    int j = 0;
    bool top2 = false;

    for (int i = 0; i < this->size; i++) {
        if (i == 0) {
            out << "[ " << i << " ]" << endl;
            out << this->list[i].toString();
        }
        else {
            if (this->list[i].getPosition() == this->list[i-1].getPosition()) {
                if (!top2) {
                    top2 = true;
                    out << "[ " << i-j << " ]" << endl;
                    out << this->list[i].toString();
                }
                else {
                    j++;
                }
            }
            else {
                top2 = false;
                out << "[ " << i-j << " ]" << endl;
                out << this->list[i].toString();
            }
        }
    }

    return out.str();
}


void QuicksortForID (BUAthlete *list, int i, int k) {
    int j;

    if (i >= k) {
        return;
    }

    j = PartitionForID(list, i, k);

    QuicksortForID(list, i, j);
    QuicksortForID(list, j + 1, k);
}

int PartitionForID (BUAthlete *list, int i, int k) {
    int l;
    int h;
    int midpoint;
    int pivot;
    BUAthlete temp;
    bool done;

    midpoint = i + (k - i) / 2;
    pivot = list[midpoint].getID();

    done = false;
    l = i;
    h = k;

    while (!done) {

        while (list[l].getID() < pivot) {
            ++l;
        }

        while (pivot < list[h].getID()) {
            --h;
        }

        if (l >= h) {
            done = true;
        }
        else {
            //Copy list[l] to temp
            temp.setID(list[l].getID());
            temp.setName(list[l].getName());
            if(list[l].getLOI()) {
                temp.setLOI("yes");
            }
            else {
                temp.setLOI("no");
            }
            temp.setSchool(list[l].getSchool());
            temp.setPosition(list[l].getPosition());
            temp.setEvaluation(list[l].getEvaluation());

            //Copy list[h] to list[l]
            list[l].setID(list[h].getID());
            list[l].setName(list[h].getName());
            if(list[h].getLOI()) {
                list[l].setLOI("yes");
            }
            else {
                list[l].setLOI("no");
            }
            list[l].setSchool(list[h].getSchool());
            list[l].setPosition(list[h].getPosition());
            list[l].setEvaluation(list[h].getEvaluation());

            //Copy temp to list[h]
            list[h].setID(temp.getID());
            list[h].setName(temp.getName());
            if(temp.getLOI()) {
                list[h].setLOI("yes");
            }
            else {
                list[h].setLOI("no");
            }
            list[h].setSchool(temp.getSchool());
            list[h].setPosition(temp.getPosition());
            list[h].setEvaluation(temp.getEvaluation());

            ++l;
            --h;
        }
    }

    return h;
}

void QuicksortForEvaluation (BUAthlete *list, int i, int k) {
    int j;

    if (i >= k) {
        return;
    }

    j = PartitionForEvaluation(list, i, k);

    QuicksortForEvaluation(list, i, j);
    QuicksortForEvaluation(list, j + 1, k);
}

int PartitionForEvaluation (BUAthlete *list, int i, int k) {
    int l;
    int h;
    int midpoint;
    int pivot;
    BUAthlete temp;
    bool done;

    midpoint = i + (k - i) / 2;
    pivot = list[midpoint].getEvaluation();

    done = false;
    l = i;
    h = k;

    while (!done) {

        while (list[l].getEvaluation() > pivot) {
            ++l;
        }

        while (pivot > list[h].getEvaluation()) {
            --h;
        }

        if (l >= h) {
            done = true;
        }
        else {
            //Copy list[l] to temp
            temp.setID(list[l].getID());
            temp.setName(list[l].getName());
            if(list[l].getLOI()) {
                temp.setLOI("yes");
            }
            else {
                temp.setLOI("no");
            }
            temp.setSchool(list[l].getSchool());
            temp.setPosition(list[l].getPosition());
            temp.setEvaluation(list[l].getEvaluation());

            //Copy list[h] to list[l]
            list[l].setID(list[h].getID());
            list[l].setName(list[h].getName());
            if(list[h].getLOI()) {
                list[l].setLOI("yes");
            }
            else {
                list[l].setLOI("no");
            }
            list[l].setSchool(list[h].getSchool());
            list[l].setPosition(list[h].getPosition());
            list[l].setEvaluation(list[h].getEvaluation());

            //Copy temp to list[h]
            list[h].setID(temp.getID());
            list[h].setName(temp.getName());
            if(temp.getLOI()) {
                list[h].setLOI("yes");
            }
            else {
                list[h].setLOI("no");
            }
            list[h].setSchool(temp.getSchool());
            list[h].setPosition(temp.getPosition());
            list[h].setEvaluation(temp.getEvaluation());

            ++l;
            --h;
        }
    }

    return h;
}