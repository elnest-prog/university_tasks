#include <iostream>

using namespace std;

void swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
}

void swap2(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void swap3(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int main()
{
	int x = 5, y = 8;
	double z = 3.1415926535;
	cout << x << " " << y << endl;
	swap3(x, z); // Error
	cout << x << " " << y << endl;
	swap3(x, 15); // Error
	cout << x << " " << y << endl;
	
	return 0;
}
