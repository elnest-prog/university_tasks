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
		void out() { cout << "E::out() " << this << endl; x = 222;	}
		void print() { D::out(); }
};


// .cpp

void f(B &r)
{
	cout << "f() : ";
	r.out();
}

int main()
{
	E e;
	e.out();
//	e.print();
	f(e);

	B *p = new E;  // повышающее - автоматически, безопасно
	// ...........
	p->out();
	D *q = (D*)p;  // понижающее - к потомку, опасно, только явно
	q->out();
	((E*)q)->out();  // понижающее - к потомку, опасно, только явно
	f(*q);
	
	A *t = new C;
	t->out();
	((C*)t)->out();
	((E*)t)->out();  // неправильно, объект C не является объектом E
//	f(*t);   // неявно понижающее - нельзя
	f(*(C*)t);   // неявно понижающее - нельзя
		
	delete p;
	delete t;

	return 0;
}
