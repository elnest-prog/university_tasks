#include <iostream>

using namespace std;

int sum(int a, int b=0, int c=0, int d=0, int e=0);

double sum(double a, double b, double c) {	return a + b + c; }

int main()
{
	cout << sum(1) << endl;
	cout << sum(1, 2) << endl;
	cout << sum(1, 2, 3) << endl;
	cout << sum(1, 2, 3, 4) << endl;
	cout << sum(1.3, 2.2, 3.1) << endl;
	cout << sum(1.3, 2.2, 3.1, 4.0) << endl;
	
	return 0;
}


//int sum(int a, int b=0, int c=0, int d=0, int e=0) { return a + b + c + d + e; }
int sum(int a, int b, int c, int d, int e) { return a + b + c + d + e; }

