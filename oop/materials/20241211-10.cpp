#include <iostream>
#include <cmath>

using namespace std;

// .h
class Sqr
{
public:
	double a, b, c;
	
	void out() const { cout << "( " << a << "; " << b << " ; " << c << " )\n"; } // inline!
	Sqr() : a(0), b(0), c(0) {}
	double operator () (double x) const;
};


// .cpp
double Sqr::operator () (double x) const
{
	return a * x*x + b * x + c;
}

int main()
{
	cout << "Start!\n";

	Sqr p;
	p.a = 2;
	p.b = 3;
	p.c = 4;
	
//	cout << p << endl;	
	p.out();
	cout << p(1) << endl;	
	cout << p(2) << endl;	
	cout << p(-1.35) << endl;	
					
	cout << "Finish!\n";
	return 0;
}
