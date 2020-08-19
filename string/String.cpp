#include "String.h"
String::String(const char* str)
{
	length = strlen(str);
	this->str = new char[length + 1];
	strcpy_s(this->str, length + 1, str);
}
String::String(const String& other)
{
	length = other.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, other.str);
}
String::~String()
{
	delete[] str;
}
void String::Print() const
{
	cout << str << endl;
}
void String::operator+=(const String& str)
{
	length = this->length + str.length;
	char* newStr = new char[length + 1];
	strcpy_s(newStr, length + 1, this->str);
	strcat_s(newStr, length + 1, str.str);
	delete[] this->str;
	this->str = newStr;
}
String String::operator+(const String& str) const
{
	String res(*this);
	res += str;
	return res;
}
void String::Append(const char* str)
{
	length = this->length + strlen(str);
	char* newStr = new char[length + 1];

	strcpy_s(newStr, length + 1, this->str);
	strcat_s(newStr, length + 1, str);

	delete[] this->str;
	this->str = newStr;
}
String String::operator*(const String& tmp) const
{
	char temp[30] = {};
	int a = 0;
	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < tmp.length; j++)
		{
			if (str[i] == tmp.str[j])
			{
				temp[a] = str[i];
				a++;
			}
		}
	}
	return temp;
}
bool String::operator<(const String& tmp)
{
	return (strcmp(this->str, tmp.str) < 0);
}
bool String::operator>(const String& tmp)
{
	return (strcmp(this->str, tmp.str) > 0);
}
bool String::operator!=(const String& tmp) const
{
	return(strcmp(this->str, tmp.str)) != 0;
}
bool String::operator==(const String& tmp) const
{
	return(strcmp(this->str, tmp.str)) == 0;
}