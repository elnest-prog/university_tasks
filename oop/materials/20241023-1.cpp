#include <iostream>
#include <cmath>

using namespace std;

// .h
class A
{
	int x;
public:
	A(int _x) : x(_x) { cout << "A::A(int)\n"; }
	A() : x(0) { cout << "A::A()\n"; }
};

class B
{
	double y;
public:
	B(double _y) : y(_y) { cout << "B::B(double)\n"; }
	B() : y(0) { cout << "B::B()\n"; }
};

class Complex
{
public:
	A a;
	B b;
		
	Complex();       // конструктор - инициализация полей объекта
//	Complex(const Complex & src);
//	Complex(double re_, double im_);
	~Complex();
};

// .cpp
Complex::Complex() : b(1.23), a(88)
{ cout << "Complex::Complex() : " << this << "\n"; }

//Complex::Complex(const Complex & src): re(src.re), im(src.im)
//{ cout << "Complex::Complex(const Complex & src) : " << this << "\n"; }

//Complex::Complex(double re_, double im_) : re(re_), im(im_) 
//{ cout << "Complex::Complex(double re_, double im_) : " << this << "\n"; }

Complex::~Complex() { cout << "Complex::~Complex() : " << this << "\n"; }


int main()
{
	cout << "Start!\n";
	
	Complex c;
					
	cout << "Finish!\n";
	return 0;
}
