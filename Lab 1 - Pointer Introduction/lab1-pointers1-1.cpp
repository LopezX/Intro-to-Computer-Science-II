#include <iostream>

using namespace std;

int main() {
	int x;
	int *intPtr;

	x = 10;
	intPtr = &x;

	cout << "x’s value is " << x << endl;
	cout << "intPtr’s value is " << intPtr << endl;
  
	cout << "x’s address is " << &x << endl;
  
	cout << "The size of x is " << sizeof(x) << endl;
	cout << "The size of intPtr is " << sizeof(intPtr) << endl;

	return 0;
}