#include <iostream>
#include <cmath>

using namespace std;

// .h
class Complex
{
public:
	double re, im;
	
	void out()  { cout << "( " << re << "; " << im <<
		"abs=" << abs() << "\n"; } // inline!
	double abs() const;
	double phase() const;
	Complex(const Complex & src);
	Complex(double re_ = 0, double im_ = 0);
	~Complex();
};

// .cpp
Complex::Complex(const Complex & src): re(src.re), im(src.im)
{ cout << "Complex::Complex(const Complex & src) : " << this << "\n"; }

Complex::Complex(double re_, double im_) : re(re_), im(im_) 
{ cout << "Complex::Complex(double re_, double im_) : " << this << "\n"; }

Complex::~Complex() { cout << "Complex::~Complex() : " << this << "\n"; }


double Complex::abs() const
{
	return sqrt(re*re + im*im);
}

double Complex::phase() const
{
	return atan2(im, re);
}

int main()
{
	cout << "Start!\n";
	
	const Complex a(2, 3);
	a.out();
	Complex b(2.34);
	b.out();
	Complex c = b;
	c.out();
	Complex d;
	d.out();
	
//	a.re = 0;
	d.re = 0;
	
	Complex e[5];
					
	cout << "Finish!\n";
	return 0;
}
