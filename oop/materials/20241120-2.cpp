#include <iostream>
#include <cmath>

using namespace std;

// .h

class Item
{
	private:
		int x;
	public:
		Item() : x(0) { }
		~Item() { }
		void out() { cout << "Item::out() " << this << endl;	}
};

enum ItemType { itNone, itCat, itDog };

class Base : public Item
{
	private:
		ItemType type;
	protected:
		Base(ItemType t) : type(t) {}
	public:
		void out();
		ItemType getType() { return type; }
};


class Cat : public Base
{
	private:
		int x;
	public:
		Cat();
		void out() { cout << "I'm Cat: murr " << this << endl;	}
};

class Dog : public Base
{
	private:
		int x;
	public:
		Dog();
		void out() { cout << "I'm Dog: gav " << this << endl;	}
};



// .cpp

Cat::Cat() : Base(itCat) {}
Dog::Dog() : Base(itDog) {}

void Base::out()
{
	cout << "Base::out() called\n";
	switch (getType())
	{
		case itCat:
			((Cat*)this)->out();
			break;
		case itDog:
			((Dog*)this)->out();
			break;
		default:
			cout << "I'm nothing " << this << endl;
			break;
	}
}


void f(Base *p)
{
	p->out();
}

int main()
{
	Cat c;
	Base *d = new Dog;
	
	c.out();
	d->out();
	
	f(&c);
	f(d);

	return 0;
}
