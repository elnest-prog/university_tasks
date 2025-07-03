#include <iostream>

using namespace std;

int main()
{
	int a = 5, b = 3;
	int & ref = a > b ? a : b;
	
	cout << ref << endl;
	ref++;
	cout << ref << endl;
	cout << a << endl;
	cout << &ref << endl;
	cout << &a << endl;

	return 0;
}
