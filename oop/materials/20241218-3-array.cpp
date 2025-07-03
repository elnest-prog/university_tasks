#include <iostream>
#include <cstring>

using namespace std;

// .h
class Array
{
private:
	double *data;
	int size;
public:
	Array(int size_);
	Array(const Array & src);
	~Array();
	
	const Array & operator = (const Array & src);
	double operator[] (int i) const;
	double & operator[] (int i);
};

// .cpp
Array::Array(int size_) : data(nullptr), size(0)
{
	data = new double[size_];
	if (data)
		size = size_; 
}

Array::~Array()
{
	if (data)
		delete[] data;
}

double Array::operator[] (int i) const
{
	return !data || i < 0 || i >= size ? 0 : data[i];
}

double & Array::operator[] (int i)
{
	static double temp;
	temp = 0;
	return !data || i < 0 || i >= size ? temp : data[i];
}


int main()
{
	cout << "Start!\n";
	
	const Array s(10);
	cout << s[1] << endl;
	s[1] = 1.234;
	cout << s[1] << endl;
	cout << s[10] << endl;
	s[10] = 33.33333;
	cout << s[10] << endl;

	cout << "Finish!\n";
	return 0;
}
