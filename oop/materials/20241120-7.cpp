#include <iostream>
#include <cmath>

using namespace std;

// .h

class A
{
	private:
		int x;
	public:
		A() : x(0) { }
		~A() { }
		virtual void out() { cout << "A::out() " << this << endl;	}
};

class B : public A
{
	private:
		int x;
	public:
		virtual void out() { cout << "B::out() " << this << endl;	}
};


// .cpp


int main()
{
	A *p = new B;
	
	p->out();

	return 0;
}
