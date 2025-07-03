#include <iostream>
#include <cstring>

using namespace std;

// .h


// .cpp

static class ConsoleHelper
{
private:
public:
	ConsoleHelper() { system("chcp 1251"); }
	~ConsoleHelper() { system("pause"); }
}_;

void f()
{
	exit(1);
}

int main()
{
	cout << "Start!\n";
	
	f();
	
	cout << "Finish!\n";
	return 0;
}
