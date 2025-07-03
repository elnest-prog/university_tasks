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

class B
{
	private:
		int x;
	public:
		void out() { cout << "B::out() " << this << endl;	}
};

class C : public A
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

class E : public D, public C
{
	private:
		int x;
	public:
//		void out() { cout << "E::out() " << this << endl;	}
};


// .cpp


int main()
{
	E e;
	e.out();

	return 0;
}
