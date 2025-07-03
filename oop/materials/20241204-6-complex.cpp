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
	Complex(double re_=0, double im_=0) : re(re_), im(im_) {}
	const Complex operator-() const;
	bool operator!() const;
	const Complex operator+ (const Complex &b) const;             // можно как метод
	const Complex operator+ (double b) const;                     // можно как метод
	friend const Complex operator+ (double a, const Complex &b);  // только как функция
};

// .cpp

const Complex Complex::operator+ (const Complex &b) const
{
	return Complex(re + b.re, im + b.im);
}

const Complex Complex::operator+ (double b) const
{
	return Complex(re + b, im);
}

const Complex operator+ (double a, const Complex &b)
{
	return Complex(a + b.re, b.im);
}

const Complex Complex::operator-() const
{
	return Complex(-re, -im);
}

bool Complex::operator!() const
{
	return !re && !im;
}

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
	Complex b(5, -4.7);
	Complex c;
	double d = 3.45;
	
	a.out();
	b.out();

	c = a + b;
	c.out();
					
	c = -a + b;
	c.out();
					
	c = a + d;
	c.out();
	c = d + a;
	c.out();
	
	a = b.operator+(c);
	a.out();
					
	cout << "Finish!\n";
	return 0;
}
