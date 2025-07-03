#include <iostream>

using namespace std;

int main()
{
	int a = 5;
	int & ref = a;
	
	cout << ref << endl;
	
	return 0;
}
