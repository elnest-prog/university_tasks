#include <iostream>
#include <cmath>

using namespace std;

// .h

class A
{
	private:
		int x;
	public:
		A() : x(0) { cout << "A::A() " << this << endl; }
		~A() { cout << "A::~A() " << this << endl; }
		virtual void out() = 0; // abstract //{ cout << "A::out() " << this << endl;	}
};

class B : public A
{
	private:
		int x;
	public:
		void out() override { cout << "B::out() " << this << endl;	}
		B() { cout << "B::B() " << this << endl; }
		~B() { cout << "B::~B() " << this << endl; }
};

class C : public A
{
};

// .cpp


int main()
{
	A *p = new B;
	p->out();
	
	delete p;

	return 0;
}
