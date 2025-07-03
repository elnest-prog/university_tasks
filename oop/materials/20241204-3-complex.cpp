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

// .cpp

const Complex Complex::operator-() const  // проверка на 0
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
	Complex b = -a;
	Complex c;
	
	a.out();
	b.out();
	c.out();
	
//	-a = b;

	cout << !a << endl;
	cout << !c << endl;
	
	c = a.operator-();  // вызов как метода
	c.out();

					
	cout << "Finish!\n";
	return 0;
}
