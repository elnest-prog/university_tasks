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
	const Complex operator-() const;  // тот же унарный минус как метод, он константный - не изменяет объект
};

const Complex Complex::operator-() const
{
	return Complex(-re, -im);
}

// .cpp

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
	Complex b = -a;
	
	a.out();
	b.out();
	
//	-a = b;
					
	cout << "Finish!\n";
	return 0;
}
