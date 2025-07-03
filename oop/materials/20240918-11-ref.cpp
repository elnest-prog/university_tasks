#include <iostream>

using namespace std;

struct X
{
	int arr[1000];
	int count;
};

int main()
{
	X & ref = *(X*)malloc(sizeof(X));
	
	ref.count = 0;
	cout << ref.count << endl;
	cout << ref.arr[0] << endl;
	cout << sizeof(ref) << endl;

	free(&ref);
	
	return 0;
}
