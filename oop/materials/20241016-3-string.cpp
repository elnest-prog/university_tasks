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
	~String();
	void set(const char *src);
	const char *get();
};

// .cpp
String::String() : data(nullptr) {}
String::~String()
{
	if (data)
		delete[] data;
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

int main()
{
	cout << "Start!\n";
	
	String s;
	
	cout << "\"" << s.get() << "\"\n";
	s.set("Hello!");
	cout << "\"" << s.get() << "\"\n";
					
	cout << "Finish!\n";
	return 0;
}
