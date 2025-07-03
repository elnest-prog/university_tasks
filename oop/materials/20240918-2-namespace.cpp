#include <iostream>

using namespace std;

namespace MySpace
{
	void Out()
	{
		cout << "I'm from MySpace!\n";
	}
}

namespace MySpace
{
	void Out2()
	{
		cout << "I'm Out2 from MySpace!\n";
	}
}

int main()
{
	cout << "Hello, World!" << endl;
	MySpace::Out();
	MySpace::Out2();
	
	system("pause");
	return 0;
}
