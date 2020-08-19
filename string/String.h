#pragma once
#include <iostream>
using namespace std;

class String
{
	char* str;
	int length;

public:
	String() : length(0), str(nullptr)
	{	}
	String(int count, char symb) : length(count)
	{
		str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			str[i] = symb;
		}
		str[length] = 0;
	}
	String(const char* str);
	String(const String& other);
	~String();
	void Print() const;
	void Append(const char* str);
	void operator+=(const String& str);
	String operator+(const String& str) const;
	String operator*(const String& str) const;
	bool operator<(const String& tmp);
	bool operator>(const String& tmp);
	bool operator!=(const String& tmp) const;
	bool operator==(const String& tmp) const;
};