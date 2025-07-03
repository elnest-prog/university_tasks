#include <iostream>

using namespace std;

class Complex
{
public:
	double re, im;
	
	void out() { cout << "( " << re << "; " << im << " )\n"; } // inline! потому что реализаци€ внутри описани€ класса
};


int main()
{
	Complex c;
//	cout << c.re << " " << c.im << endl;
//	out();    // неправильно, надо указать экземпл€р (конкретный существующий объект)
	c.out();
	
	c.re = 1;
	c.im = 0;
//	cout << c.re << " " << c.im << endl;
	c.out();
	
	Complex *p = new Complex;
//	cout << p->re << " " << p->im << endl;
	p->out();
	
	p->re = 22;
	p->im = -33;
//	cout << p->re << " " << p->im << endl;
	p->out();
	
	delete p;
			
	return 0;
}
