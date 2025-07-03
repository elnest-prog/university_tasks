#include <iostream>
#include <cstring>

using namespace std;

// .h
class String;

class StringHandler
{
	public:
		void out1(const String &s);
//		void out2(const String &s);
};

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
//	const char *get();

	friend void out(const String &s);
	friend void StringHandler::out1(const String &s);
};

// .cpp

void StringHandler::out1(const String &s) { cout << s.data << endl; }
//void StringHandler::out2(const String &s) { cout << s.data << endl; } // Error
		
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

String::String(const char *src) : data(nullptr)
{
	cout << "String::String(const char *src) : " << this << endl; 
	int n = src && *src ? strlen(src) : 0;
	if (n)
		data = new char[n+1];
	if (data)
		strcpy(data, src);
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
//
//const char *String::get()
//{
//	return data ? data : "";
//}

void out(const String &s)
{
	cout << s.data << endl; 
}


int main()
{
	cout << "Start!\n";
	
	String s("Hello!");
	out(s);
//	cout << s.data << endl; // ERROR: data is private
		
	StringHandler h;
	h.out1(s);
//	h.out2(s);
	
	cout << "Finish!\n";
	return 0;
}
