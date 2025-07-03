#include <iostream>
#include <cstring>

using namespace std;

// .h
class String
{
private:
	char *data;
public:
	String();
	String(const String & src);
	String(const char *src);
	~String();
//	void set(const char *src);
	const char *get() const;
	
	const String & operator = (const String & src);
	const String & operator += (const String & src);
	const String operator+ (const String & src) const;
	operator const char * () const;
	operator int () const;
//	friend void out(const String &s);
};

// .cpp
String::String() : data(nullptr)
{ cout << "String::String() : " << this << endl; }

String::~String()
{
	cout << "String::~String() : " << this << endl; 
	if (data)
		delete[] data;
}

String::String(const String & src) : data(nullptr)
{
	cout << "String::String(const String & src) : " << this << endl; 
	int n = src.data && *src.data ? strlen(src.data) : 0;
	if (n)
		data = new char[n+1];
	if (data)
		strcpy(data, src.data);
}

String::String(const char *src) : data(nullptr)
{
	cout << "String::String(const char *src) : " << this << endl; 
	int n = src && *src ? strlen(src) : 0;
	if (n)
		data = new char[n+1];
	if (data)
		strcpy(data, src);
}

const String & String::operator = (const String & src)
{
	if (data)
		delete[] data;
	data = nullptr;
	int n = src.data && *src.data ? strlen(src.data) : 0;
	if (n)
		data = new char[n+1];
	if (data)
		strcpy(data, src.data);
	return *this;
}

const String & String::operator += (const String & src)
{
	char * p = nullptr;
	int n = data && *data ? strlen(data) : 0;
	n += src.data && *src.data ? strlen(src.data) : 0;
	if (n)
		p = new char[n+1];
	if (p)
	{
		if (data)
			strcpy(p, data);
		if (src.data)
			strcat(p, src.data);
		delete[] data;
		data = p;
	}
	return *this;
}

const String String::operator+ (const String & src) const
{
	return String(*this) += src;
}

//void String::set(const char *src)
//{
//	if (data)
//		delete[] data;
//	int n = src && *src ? strlen(src) : 0;
//	data = n ? new char[n+1] : nullptr;
//	if (data)
//		strcpy(data, src);
//}

const char *String::get() const
{
	return data ? data : "";
}

String::operator const char * () const
{
	return data ? data : "";
}

String::operator int () const
{
	return data ? strlen(data) : 0;
}

void out(const String &q)
{
	cout << q.get() << endl; 
}


int main()
{
	cout << "Start!\n";
	
	String s("Hello!");
	char m[100] = "***";
	out(s);
	out(m);
	strcpy(m, s);
//	strcpy(m, &s); // ваще неправильно
//	m = s;
	out(s);
	out(m);
	cout << (int)s << endl;

	cout << "Finish!\n";
	return 0;
}
