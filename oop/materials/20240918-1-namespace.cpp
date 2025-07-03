#include <iostream>

using namespace std;

namespace MySpace
{
	void Out()
	{
		cout << "I'm from MySpace!\n";
	}
}

int main()
{
	cout << "Hello, World!" << endl;
	MySpace::Out();
	
	system("pause");
	return 0;
}
