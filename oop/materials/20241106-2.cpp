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
		void set(double y_) { y = y_; }
};

// .cpp


int main()
{
	B b;
	b.out();
	b.set(2.34);
	
	A a;
	a.out();
	a.set(5.67);

	return 0;
}
