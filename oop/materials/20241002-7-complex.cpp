#include <iostream>

using namespace std;

class Complex
{
public:
	double re, im;
};


int main()
{
	Complex c;
	cout << c.re << " " << c.im << endl;
	
	c.re = 1;
	c.im = 0;
	cout << c.re << " " << c.im << endl;
	
	Complex *p = new Complex;
	cout << p->re << " " << p->im << endl;
	
	p->re = 22;
	p->im = -33;
	cout << p->re << " " << p->im << endl;
	
	delete p;
			
	return 0;
}
