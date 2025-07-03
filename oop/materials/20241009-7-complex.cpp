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
Complex::Complex() : re(0), im(0) { cout << "Complex::Complex()\n"; }

Complex::Complex(double re_, double im_) : re(re_), im(im_) 
{ cout << "Complex::Complex(double re_, double im_)\n"; }

Complex::~Complex() { cout << "Complex::~Complex()\n"; }

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
	
	Complex *p = new Complex[10];
	delete[] p;
//	delete p;	// Error!
	
	cout << "Finish!\n";
	return 0;
}
