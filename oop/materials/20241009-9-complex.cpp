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
	~Complex();
};

// .cpp
Complex::Complex() : re(0), im(0)
{ cout << "Complex::Complex() : " << this << "\n"; }

Complex::Complex(double re_, double im_) : re(re_), im(im_) 
{ cout << "Complex::Complex(double re_, double im_) : " << this << "\n"; }

Complex::~Complex() { cout << "Complex::~Complex() : " << this << "\n"; }


double Complex::abs()
{
	return sqrt(re*re + im*im);
}

double Complex::phase()
{
	return atan2(im, re);
}

const Complex i(0, 1);

int main()
{
	cout << "Start!\n";
	
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
	
	double a = 3, b = 4;
	cout << Complex(a, b).abs() << endl;
				
	cout << "Finish!\n";
	return 0;
}
