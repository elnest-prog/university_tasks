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
};

const Complex operator+ (const Complex &a, const Complex &b);  // бинарная как функция

// .cpp

const Complex operator+ (const Complex &a, const Complex &b)
{
	return Complex(a.re + b.re, a.im + b.im);
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
	
	a.out();
	b.out();

	c = a + b;
	c.out();
					
	c = -a + b;
	c.out();
					
	cout << "Finish!\n";
	return 0;
}
