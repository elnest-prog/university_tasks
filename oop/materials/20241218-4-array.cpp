#include <iostream>
#include <cstring>

using namespace std;

// .h
class Proxy
{
	private:
		double *data;
		int m;
	public:
		Proxy(double *data_, int m_) : data(data_), m(m_) {}
		double & operator[] (int j);
};

class Array2D
{
private:
	double *data;
	int n, m;
public:
	Array2D(int n_, int m_);
	Array2D(const Array2D & src);
	~Array2D();
	
	const Array2D & operator = (const Array2D & src);
//	double operator[] (int i) const;
	Proxy operator[] (int i);
};

// .cpp
Array2D::Array2D(int n_, int m_) : data(nullptr), n(0), m(0)
{
	data = new double[n_ * m_];
	if (data)
		n = n_, m = m_; 
}

Array2D::~Array2D()
{
	if (data)
		delete[] data;
}

Proxy Array2D::operator[] (int i) 
{
	return !data || i < 0 || i >= n ? Proxy(nullptr, 0) : Proxy(data + i*m, m);
}

double & Proxy::operator[] (int j)
{
	static double temp;
	temp = 0;
	return !data || j < 0 || j >= m ? temp : data[j];
}


int main()
{
	cout << "Start!\n";
	
	Array2D s(3, 5);
	cout << s[1][2] << endl;
	s[1][2] = 1.234;
	cout << s[1][2] << endl;
	cout << s[10][2] << endl;
	s[10][2] = 1.234;
	cout << s[10][2] << endl;
	cout << s[1][20] << endl;
	s[1][20] = 1.234;
	cout << s[1][20] << endl;
//	cout << s[10] << endl;
//	s[10] = 33.33333;
//	cout << s[10] << endl;

	cout << "Finish!\n";
	return 0;
}
