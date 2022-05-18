#include <iostream>

using namespace std;

int main() {
	int x, *intPtr = &x;
	char ch, *chPtr = &ch;
	double dbl, *dblPtr = &dbl;

	cout << intPtr << " is the initial value of intPtr" << endl;
	cout << (int*)chPtr << " is the initial value of chPtr" << endl;
	cout << dblPtr << " is the initial value of dblPtr" << endl;

	intPtr++;
	chPtr++;
	dblPtr++;

	cout << intPtr << " is the new value of intPtr" << endl;
	cout << (int*)chPtr << " is the new value of chPtr" << endl;
	cout << dblPtr << " is the new value of dblPtr" << endl;

	return 0;
}