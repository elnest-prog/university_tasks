#include <iostream>

using namespace std;

int & min(int &a, int &b)
{
	return a < b ? a : b;
}

int main()
{
	int x = 5, y = 8;
	double z = 3.1415926535;
	cout << x << " " << y << endl;
	cout << min(x, y) << endl;
	min(x, y) = -111;
	cout << x << " " << y << endl;
	
	return 0;
}
