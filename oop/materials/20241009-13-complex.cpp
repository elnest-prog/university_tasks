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
	Complex(const Complex & src);
	Complex(double re_, double im_);
	~Complex();
};

// .cpp
Complex::Complex() : re(0), im(0)
{ cout << "Complex::Complex() : " << this << "\n"; }

Complex::Complex(const Complex & src): re(src.re), im(src.im)
{ cout << "Complex::Complex(const Complex & src) : " << this << "\n"; }

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

int main()
{
	cout << "Start!\n";
	
	Complex a(2, 3);
	Complex b(a);
	Complex c = b;
					
	cout << "Finish!\n";
	return 0;
}
