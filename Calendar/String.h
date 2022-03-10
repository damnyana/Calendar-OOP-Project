#ifndef STRING_H
#define STRING_H
#pragma once
#include <iostream>
#include "Vector.h"

class String
{
private:
	char* data;

	void erase();
	void copy(const String& other);

public:
	String();
	String(const char* s);
	String(char s);
	String(const String& other);
	~String();

	void print()const;
	size_t length()const;

	void clear();
	Vector<String> split(char toSplitBy);

	String& operator=(const String& other);
	String& operator=(const char* other);
	String& operator=(char s);

	String operator+(char s);
	String operator+(const char* s);
	String operator+(const String& other);

	char& operator[] (size_t i);

	bool contains(String member);
	bool operator ==(const String& other);
	bool operator !=(const String& other);
	bool operator<(const String& other);
	bool operator>(const String& other);
	bool operator<=(const String& other);
	bool operator>=(const String& other);

	const char* c_str() const;

	int to_int() const;
	int count() const;

	friend std::ostream& operator<<(std::ostream& out, const String& s);
	friend std::istream& operator>>(std::istream& in, String& s);
};


String operator+ (char c, String s);

String toUpper(String s);
String toLower(String s);
String toString(size_t x);

#endif