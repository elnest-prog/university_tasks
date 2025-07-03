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
		void out() { cout << "A::out() " << this << endl;	}
};

class B : public A
{
	private:
		int x;
	public:
		void out() { cout << "B::out() " << this << endl;	}
};

class C : public B
{
	private:
		int x;
	public:
		void out() { cout << "C::out() " << this << endl;	}
};

class D : public B
{
	private:
		int x;
	public:
		void out() { cout << "D::out() " << this << endl;	}
};

class E : public D
{
	private:
		int x;
	public:
		void out() { cout << "E::out() " << this << endl;	}
		void print() { D::out(); }
};


// .cpp


int main()
{
	E e;
	e.out();
//	e.print();

	B *p = new E;
	// ...........
	p->out();
	delete p;

	return 0;
}
