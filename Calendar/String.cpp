#include "String.h"
#include <string>

void String::erase()
{
	delete[] this->data;
}

void String::copy(const String& other)
{
	this->data = new char[strlen(other.data) + 1];
	strcpy_s(this->data, strlen(other.data) + 1, other.data);
}

String::String()
{
	this->data = new char[1];
	data[0] = '\0';
}

String::String(const char* s)
{
	this->data = new char[strlen(s) + 1];
	strcpy_s(this->data, strlen(s) + 1, s);
}

String::String(char s)
{
	this->data = new char[2];
	this->data[0] = s;
	this->data[1] = 0;
}

String::String(const String& other)
{
	copy(other);
}

String::~String()
{
	erase();
}

void String::print() const
{
	std::cout << this->data;
}

size_t String::length() const
{
	return strlen(this->data);
}

void String::clear()
{
	delete[] data;
	copy("");
}

Vector<String> String::split(char toSplitBy)
{
	Vector<String> result;
	char str[64];

	for (size_t i = 0, k = 0; i < length(); i++, k++) {
		if (data[i] == toSplitBy || data[i + 1] == '\0') {
			if (data[i + 1] == '\0') {
				str[k] = data[i];
				str[k + 1] = '\0';
			}
			else str[k] = '\0';
			k = -1;
			result.push_back(str);
		}
		else str[k] = data[i];
	}
	return result;
}

String& String::operator=(const String& other)
{
	if (this != &other)
	{
		this->erase();
		copy(other);
	}
	return *this;
}

String& String::operator=(const char* other)
{
	this->erase();
	this->data = new char[strlen(other) + 1];
	strcpy_s(this->data, strlen(other) + 1, other);
	return *this;
}

String& String::operator=(char s)
{
	erase();
	this->data = new char[2];
	this->data[0] = s;
	this->data[1] = 0;
	return *this;
}

String String::operator+(char s)
{
	String result;
	result.data = new char[this->length() + 1 + 1];
	strcpy_s(result.data, this->length() + 1, this->data);
	result.data[this->length()] = s;
	result.data[this->length() + 1] = 0;
	return result;
}

String String::operator+(const char* s)
{
	String result;
	result.data = new char[this->length() + strlen(s) + 1];
	strcpy_s(result.data, this->length() + 1, this->data);
	strcat_s(result.data, this->length() + strlen(s) + 1, s);
	return result;
}

String String::operator+(const String& other)
{
	String result;
	result.data = new char[this->length() + other.length() + 1];
	strcpy_s(result.data, this->length() + 1, this->data);
	strcat_s(result.data, this->length() + other.length() + 1, other.data);

	return result;
}

char& String::operator[](size_t i)
{
	return this->data[i];
}

bool String::contains(String member)
{
	bool result = false;
	for (int i = 0; i < length(); i++)
	{
		if (data[i] == member[i]) 
		{
			for (int j = i; j < member.length() + i; j++) 
			{
				if (data[j] != member[j - i]) break;

				if (member.length() - 1 == j - i) 
				{
					result = true;
					break;
				}
			}

		}
	}
	return result;
}

bool String::operator==(const String& other)
{
	if (strcmp(this->data, other.data) != 0) return true;
	return false;
}

bool String::operator!=(const String& other)
{
	if (*this == other) return false;
	return true;
}

bool String::operator<(const String& other)
{
	if (strcmp(this->data, other.data) == -1)return true;
	return false;
}

bool String::operator>(const String& other)
{
	if (strcmp(this->data, other.data) == 1)return true;
	return false;
}

bool String::operator<=(const String& other)
{
	if (strcmp(this->data, other.data) == -1 || strcmp(this->data, other.data) == 0)return true;
	return false;
}

bool String::operator>=(const String& other)
{
	if (strcmp(this->data, other.data) == 1 || strcmp(this->data, other.data) == 0) return true;
	return false;
}

const char* String::c_str() const
{
	return data;
}

int String::to_int() const
{
	char* s = new char[this->length()];
	//String s = "";
	int k = 0;
	for (int i = 0; i < length(); i++) {
		if (data[i] >= '0' && data[i] <= '9') {
			s[k] = data[i];
			k++;
		}
	}
	s[k] = '\0';
	return atoi(s);
}

int String::count() const {
	int result = 1;
	for (int i = 0; i < length(); i++) {
		if (data[i] == ' ') result++;
	}
	return result;
}

std::ostream& operator<<(std::ostream& out, const String& s)
{
	out << s.data;
	return out;
}

std::istream& operator>>(std::istream& in, String& s)
{
	char c;
	do
	{
		c = in.get();
		if (c != '\n')
		{
			s = s + c;
		}
	} while (c != '\n');

	return in;
}

String operator+(char c, String s)
{
	String result;

	result = c;
	result = result + s;
	return result;

}

String toUpper(String s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 32;
	}
	return s;
}

String toLower(String s)
{
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] + 32;
	}
	return s;
}

String toString(size_t x)
{
	String result = "";
	while (x)
	{
		if (x < 10)
		{
			result = ('0' + x) + result;
			break;
		}
		result = ('0' + (x % 10)) + result;
		x = x / 10;
		
	}
	return result;
}