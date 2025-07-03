#include <iostream>
#include <cstring>

using namespace std;

// .h
class Starter
{
private:
public:
	Starter();
	~Starter();
};

// .cpp
Starter::Starter() 
{
	cout << "I'm here!\n";
}

Starter::~Starter()
{
	cout << "Bye!\n";	
}

static Starter z;

int main()
{
	cout << "Start!\n";
	

	cout << "Finish!\n";
	return 0;
}
