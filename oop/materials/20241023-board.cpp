

const int n = 20;

&n - const int *

int *p;
const int *p;
int * const p;
const int * const p;

f(const int* p)
{
	p = ...; // OK
	*p = ...; // ERROR
}

ff(const Complex &c)
{
	c - неизменяемый
	c.abs() // ERROR
	c.out() // OK
}

List:
		Add		(Item *p)
		Delete	
		Remove
		Remove  (Item *p)
		Insert	(Item *p)
		GetIndex(const Item *p)	const
		GetItem					const
		Count					const
		Clear
		

