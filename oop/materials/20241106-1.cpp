#include <iostream>
#include <cmath>

using namespace std;

// .h
class A
{
	private:
		int x;
	public:
		A() : x(0) {}
		void out() { cout << x << endl;	}
};

class B : public A
{
	private:
		double y;
	public:
		B() : y(0.0) {}
		
};

// .cpp


int main()
{
	B b;
	b.out();

	return 0;
}
