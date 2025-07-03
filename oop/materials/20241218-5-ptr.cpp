#include <iostream>
#include <cstring>

using namespace std;

// .h
class Large
{
	private:
		int m;
		// и много-много других полей
	public:
		Large(int m_) : m(m_) {}
		~Large() {}
		void out() { cout << "Large: " << m << " (" << this << ")\n"; }
};

class Ptr
{
private:
	Large *obj;
public:
	Ptr(int m_) : obj(new Large(m_)) {}
	~Ptr() { delete obj; }
	Large * operator-> () { return obj;	}
	void out() { cout << "Ptr: " << obj << " (" << this << ")\n"; }
};

// .cpp

int main()
{
	cout << "Start!\n";
	
	Ptr p(8);
	p->out();
	p.out();
	
	cout << "Finish!\n";
	return 0;
}
