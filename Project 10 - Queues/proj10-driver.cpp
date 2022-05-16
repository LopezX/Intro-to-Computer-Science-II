/**
 * file: proj10-driver.cpp
 * author: Xavier Lopez
 * course: CSI 1440
 * assignment: Project 10 - Queues
 * due date: 5/2/2022
 *
 * date modified: 4/27/2022
 *      - file was created
 *
 * date modified: 5/1/2022
 *      - Tested Queue1
 *
 * date modified: 5/2/2022
 *      - Tested Queue2
 *      - Tested Queue3
 *
 * driver for Project 10
 */

#include <iostream>
#include <ctime>
#include "proj10-Queue1.h"
#include "proj10-Queue2.h"
#include "proj10-Queue3.h"

using namespace std;

int main() {
    //Testing Queue1
    cout << "Initializing Queue1..." << endl;
    Queue1<int> queue1Vec;
    int randNum, val, start, stop;
    srand(time(0));
    cout << "Enqueuing numbers into Queue1:" << endl;
    for (int i = 0; i < 100; i++) {
        randNum = rand();
        queue1Vec.enqueue(randNum);
        try {
            cout << queue1Vec.back() << " ";
        }
        catch (BADINDEX) {
            cout << "No value in the back" << endl;
        }
    }
    cout << endl << endl;

    start = clock();
    cout << "Dequeue all of Queue1:" << endl;
    for (int i = 0; i <= 100; i++) {
        try {
            queue1Vec.dequeue(val);
            cout << val << " ";
        }
        catch (BADINDEX) {
            cout << endl;
            cout << "No value left to dequeue." << endl;
        }
    }
    stop = clock();
    cout << "Queue1 time was " << stop - start << endl << endl;

    //Testing Queue2
    cout << "Initializing Queue2..." << endl;
    Queue2<int> queue2Vec;
    cout << "Enqueueing numbers into Queue2:" << endl;
    for (int i = 0; i < 100; i++) {
        randNum = rand();
        queue2Vec.enqueue(randNum);
        try {
            cout << queue2Vec.back() << " ";
        }
        catch (BADINDEX) {
            cout << "No value in the back" << endl;
        }
    }
    cout << endl << endl;

    start = clock();
    cout << "Dequeue all of Queue2:" << endl;
    for (int i = 0; i <= 100; i++) {
        try {
            queue2Vec.dequeue(val);
            cout << val << " ";
        }
        catch (BADINDEX) {
            cout << endl;
            cout << "No value left to dequeue." << endl;
        }
    }
    stop = clock();
    cout << "Queue2 time was " << stop - start << endl << endl;

    //Testing Queue3
    cout << "Initializing Queue3..." << endl;
    Queue3<int> queue3Vec;
    cout << "Enqueueing numbers into Queue3:" << endl;
    for (int i = 0; i < 100; i++) {
        randNum = rand();
        queue3Vec.enqueue(randNum);
        try {
            cout << queue3Vec.back() << " ";
        }
        catch (BADINDEX) {
            cout << "No value in the back" << endl;
        }

    }
    cout << endl << endl;

    start = clock();
    cout << "Dequeue all of Queue3:" << endl;
    for (int i = 0; i <= 100; i++) {
        try {
            queue3Vec.dequeue(val);
            cout << val << " ";
        }
        catch (BADINDEX) {
            cout << endl;
            cout << "No value left to dequeue." << endl;
        }
    }
    stop = clock();
    cout << "Queue3 time was " << stop - start << endl << endl;

    return 0;
}
