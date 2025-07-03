#include <iostream>

using namespace std;

int & min(int &a, int &b)
{
	return a < b ? a : b;
}

int main()
{
	int x = 15, y = 8, t = 12, k = 22;
	min(min(x, y), min(t, k)) = -111;
	cout << x << " " << y << " " << t << " " << k << endl;
	
	return 0;
}
