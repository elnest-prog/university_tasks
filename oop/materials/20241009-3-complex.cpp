#include <iostream>
#include <cmath>

using namespace std;

// .h
class Complex
{
public:
	double re, im;
	
	void out() const { cout << "( " << re << "; " << im << " )\n"; } // inline!
	double abs();
	double phase();
	Complex();       // конструктор - инициализация полей объекта
	Complex(double re_, double im_);
};

// .cpp
Complex::Complex() : re(0), im(0) {}

Complex::Complex(double re_, double im_) : re(re_), im(im_) {}

double Complex::abs()
{
	return sqrt(re*re + im*im);
}

double Complex::phase()
{
	return atan2(im, re);
}

int main()
{
	const Complex i(0, 1);
	i.out();
	i.re = 1;
	
	Complex c(2, -3);
	c.out();
	
	c.re = 1;
	c.im = 0;
	c.out();
	cout << c.abs() << endl << c.phase() << endl;
	
	Complex *p = new Complex(-5, -8);
	p->out();

	p->re = 22;
	p->im = -33;
	p->out();
	cout << p->abs() << endl << p->phase() << endl;

	delete p;
				
	return 0;
}
