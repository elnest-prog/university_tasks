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
	cout << x << " " << y << endl;
	swap(x, y);
	cout << x << " " << y << endl;
	swap2(&x, &y);
	cout << x << " " << y << endl;
	swap3(x, y);
	cout << x << " " << y << endl;
	
	return 0;
}
