#include <iostream>
#include <cmath>

using namespace std;

// .h

class Item
{
	private:
		Item *prev, *next;
	public:
		Item() { }
		~Item() { }
		void out() { cout << "Item::out() " << this << endl;	}
		Item * Prev() { return prev; }
		Item * Next() { return next; }
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
		Base * Prev() { return (Base*) Base::Prev(); }
		Base * Next() { return (Base*) Base::Next(); }
};


class Cat : public Base
{
	private:
		int x;
	public:
		Cat();
		void out() { cout << "I'm Cat: murr " << this << endl;	}
		void Print();
};

class Dog : public Base
{
	private:
		int x;
	public:
		Dog();
		void out() { cout << "I'm Dog: gav " << this << endl;	}
};

class SubjList //: public List
{
	public:
		Base * Head() { return (Base*) List::Head(); }
		void Do()
		{
			Base *p;
			for (p = Head(); p; p = p->Next())
			{
				p->out();
			}
		}
 } 

// .cpp

Cat::Cat() : Base(itCat) {}
Dog::Dog() : Base(itDog) {}

void Base::out()
{
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

void Cat::Print()
{
	cout << "I'm Cat:" << endl;
	Base::Print(); // унаследованные поля
	cout << "moi polya...\n";
}

void f(Base *p)
{
	p->out();
}

int main()
{
	Base *p;
	ItemType t;
	SubjList L;
	
	// add
	t = TypeMenu();
	p = Create(t);
	L.Add(p);
	
	// getitem
	p = (Base*) L.GetItem(n);
	p->Print();
	
	
	return 0;
}
