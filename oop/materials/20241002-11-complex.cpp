#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
	double re, im;
	
	void out() { cout << "( " << re << "; " << im << " )\n"; } // inline!
	double abs();
	double phase();
	Complex();       // конструктор - инициализация полей объекта
};

Complex::Complex()  // реализация конструктора - инициализация полей нулями
{
	re = 0; // так не очень хорошо! почему - на следующей лекции
	im = 0;
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
	Complex c;
	c.out();
	
	c.re = 1;
	c.im = 0;
	c.out();
	cout << c.abs() << endl << c.phase() << endl;
	
	Complex *p = new Complex;
	p->out();

	p->re = 22;
	p->im = -33;
	p->out();
	cout << p->abs() << endl << p->phase() << endl;

	delete p;
				
	return 0;
}
