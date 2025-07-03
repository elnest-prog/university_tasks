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
	~String();
	void set(const char *src);
	const char *get();
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
//	set(src.get());
	int n = src.data && *src.data ? strlen(src.data) : 0;
	if (n)
		data = new char[n+1];
	if (data)
		strcpy(data, src.data);
}

void String::set(const char *src)
{
	if (data)
		delete[] data;
	int n = src && *src ? strlen(src) : 0;
	data = n ? new char[n+1] : nullptr;
	if (data)
		strcpy(data, src);
}

const char *String::get()
{
	return data ? data : "";
}

void out(String s)
{
	cout << s.get() << endl;
}

void out2(String &s)
{
	cout << s.get() << endl;
}

int main()
{
	cout << "Start!\n";
	
	String s;
	
	cout << "\"" << s.get() << "\"\n";
	s.set("Hello!");
	cout << "\"" << s.get() << "\"\n";
	
	String k(s);
	cout << "\"" << k.get() << "\"\n";
	out(k);
	out2(k);
	
	String t = "World!";
	String r = 1425;
					
	cout << "Finish!\n";
	return 0;
}
