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
	explicit Complex(double re_=0, double im_=0) : re(re_), im(im_) {}
	const Complex operator-() const;
	bool operator!() const;
	const Complex operator+ (const Complex &b) const;
	const Complex operator+ (double b) const;
	friend const Complex operator+ (double a, const Complex &b);
	const Complex & operator= (double x);
	const Complex & operator+= (double x);  // перегрузка присваивания с действием
	const Complex & operator++ ();
};


// .cpp
const Complex & Complex::operator= (double x)
{
	re = x;
	im = 0;
	return *this;
}

const Complex & Complex::operator+= (double x)
{
	re += x;       // реализация стала проще, все внутри одного объекта
	return *this;  // возвращаем сам измененный объект
}

const Complex Complex::operator+ (const Complex &b) const
{
	return Complex(re + b.re, im + b.im);
}

const Complex Complex::operator+ (double b) const
{
//	return Complex(re + b, im);
	return Complex(*this) += b;  // используем соответствующий присваивание с действием, нет дублирования
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

const Complex & Complex::operator++ ()
{
	re++;
	return *this;
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
		
	a.out();
	++a;
	a++;
	a.out();
					
	cout << "Finish!\n";
	return 0;
}
