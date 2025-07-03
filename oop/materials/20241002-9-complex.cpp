#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
	double re, im;
	
	void out() { cout << "( " << re << "; " << im << " )\n"; } // inline!
	double abs();    // прототипы методов, реализация будет ниже - значит не inline
	double phase();
};

double abs()          // забыли Complex:: и как следствие...
{
	return sqrt(re*re + im*im);   // ошибка: re и im не определены
}

int main()
{
	Complex c;
	c.out();
	
	c.re = 1;
	c.im = 0;
	c.out();
	
	Complex *p = new Complex;
	p->out();
	
	p->re = 22;
	p->im = -33;
	p->out();
	
	delete p;
			
	return 0;
}
