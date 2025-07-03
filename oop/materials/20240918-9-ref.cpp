#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int & ref = a;
	
	cout << ref << endl;
	ref++;
	cout << ref << endl;
	cout << a << endl;
	cout << &ref << endl;
	cout << &a << endl;

	return 0;
}
