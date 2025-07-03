#include <iostream>
#include <cmath>

using namespace std;

// .h
class String
{
private:
	char *data;
public:
	String();
	~String();
};

// .cpp
String::String() : data(nullptr) {}
String::~String()
{
	if (data)
		delete[] data;
}


int main()
{
	cout << "Start!\n";
	
	String s;
					
	cout << "Finish!\n";
	return 0;
}
