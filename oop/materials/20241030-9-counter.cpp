#include <iostream>
#include <cstring>

using namespace std;

// .h
class Counter
{
private:
	static int counter;
public:
	Counter();
	~Counter();
	int getCount();
};

// .cpp

Counter::Counter() : counter()
{
	counter++;
}

Counter::~Counter()
{
	counter--;	
}

int Counter::getCount()
{
	return counter;
}

int main()
{
	cout << "Start!\n";
	
	Counter a;
	cout << a.getCount() << endl;
	Counter b;		
	cout << b.getCount() << endl;
	
	cout << "Finish!\n";
	return 0;
}
