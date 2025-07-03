#include <iostream>

using namespace std;

class Complex
{
	double re, im;  // по умолчанию поля частные (private)
};


int main()
{
	Complex c;
	c.re = 1;     // ошибка: нет доступа
	c.im = 0;
			
	return 0;
}
