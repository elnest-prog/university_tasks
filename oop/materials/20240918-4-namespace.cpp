#include <iostream>

using namespace std;

namespace OtherSpace
{
	void OtherOut()
	{
		cout << "I'm OtherOut from OtherSpace!\n";
	}
	void Out()
	{
		cout << "I'm Out from OtherSpace!\n";
	}

}

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
	using namespace MySpace;
	using namespace OtherSpace;
	
	cout << "Hello, World!" << endl;
	MySpace::Out();
	MySpace::Out2();
	OtherSpace::OtherOut();
	OtherSpace::Out();
	
	system("pause");
	return 0;
}
