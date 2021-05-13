#pragma once
#include<iostream>
#include<cstring>
class String
{
private:
	char* name;
	void copy(const String&);
	void erase();
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();
	
	void clear();
	size_t getLength() const;
	size_t convertFromString();
	void remove(const size_t&);
	String& operator=(const char*);
	bool operator==(const String&) const;
	bool operator==(const char*) const;
	bool operator!=(const String&) const;
	bool operator!=(const char*) const;
	char& operator[](const size_t&);
	String& operator+=(const char&);

	friend std::ostream& operator<<(std::ostream& out, const String& str)
	{
		out << str.name;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, String& str)
	{
		char symbol = ' ';
		while (symbol != '\n')
		{
			symbol = in.get();
			str += symbol;
		}
		str.name[str.getLength() - 1] = '\0';
		return in;
	}
};