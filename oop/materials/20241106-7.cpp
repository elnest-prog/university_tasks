#include <iostream>
#include <cmath>

using namespace std;

// .h
class Z
{
	private:
		int x;
	public:
		Z() : x(0) { cout << "Z::Z() " << this << endl; }
		~Z() { cout << "Z::~Z() " << this << endl; }
		void out() { cout << x << endl;	}
};

class Y
{
	private:
		int x;
	public:
		Y() : x(0) { cout << "Y::Y() " << this << endl; }
		~Y() { cout << "Y::~Y() " << this << endl; }
};

class A
{
	private:
		int x;
	public:
		A() : x(0) { cout << "A::A() " << this << endl; }
		~A() { cout << "A::~A() " << this << endl; }
		void out() { cout << x << endl;	}
};

class B : public Y
{
	private:
		Z z;
		double y;
	public:
		B() : y(0.0), z(), Y() { cout << "B::B() " << this << endl; }
		~B() { cout << "B::~B() " << this << endl; }
		void set(double y_) { y = y_; }
};

class C : private A, public B
{
	private:
		double z;
	public:
		C() : B(), A(), z(0.0) { cout << "C::C() " << this << endl; }
		~C() { cout << "C::~C() " << this << endl; }
		void set(double z_) { z = z_; }
		void print() { out(); }
};

// .cpp


int main()
{
	C c;

	return 0;
}
