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
	static int getCount(); // without this
};

// .cpp
int Counter::counter = 10000;

Counter::Counter() 
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

Counter z;

int main()
{
	cout << "Start!\n";
	
	cout << Counter::getCount() << endl;
//	cout << Counter::counter << endl;
	
	Counter a;
	cout << a.getCount() << endl;
	{
	Counter b;		
	cout << a.getCount() << endl;
	}
	cout << a.getCount() << endl;
	
	Counter *p = new Counter;
	cout << p->getCount() << endl;
	delete p;
	cout << p->getCount() << endl;

	p = new Counter[10];
	cout << Counter::getCount() << endl;
	delete[] p;
	cout << Counter::getCount() << endl;
	
	cout << "Finish!\n";
	return 0;
}
