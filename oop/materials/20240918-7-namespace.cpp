#include <iostream>

using namespace std;

namespace OtherSpace
{
	void OtherOut()
	{
		cout << "I'm OtherOut from OtherSpace!\n";
	}
//	void Out()
//	{
//		cout << "I'm Out from OtherSpace!\n";
//	}

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
	using namespace OtherSpace;

	void Out2()
	{
		cout << "I'm Out2 from MySpace!\n";
	}
}

int main()
{
	using namespace MySpace;
	
	cout << "Hello, World!" << endl;
	Out(); 
	Out2();
	OtherOut();
	
	
	system("pause");
	return 0;
}
