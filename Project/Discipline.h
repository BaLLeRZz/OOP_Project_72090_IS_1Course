#pragma once
#include "String.h"
class Discipline
{
private:
	String name;
	String type;
	size_t course;
	double mark;
public:
	Discipline() : name("Empty"), type("None"), course(0), mark(0) {};
	Discipline(const String _name, const String _type, size_t _course, double _mark = 0) : name(_name), type(_type), course(_course), mark(_mark) {};

	void setName(const String& _name)
	{
		this->name = _name;
	}

	void setMark(double _mark)
	{
		this->mark = _mark;
	}

	const String getName() const
	{
		return this->name;
	}

	size_t getCourse() const
	{
		return this->course;
	}

	double getMark() const
	{
		return this->mark;
	}

	Discipline& operator=(const Discipline& other)
	{
		if (this != &other)
		{
			this->name = other.name;
			this->type = other.type;
			this->course = other.course;
			this->mark = other.mark;
		}
		return *this;
	}

	bool operator==(const Discipline& other) const
	{
		if (this == &other)
			return true;

		if (this->name == other.name)
			return true;
		else
			return false;
	}

	bool operator!=(const Discipline& other) const
	{
		if (this == &other)
			return false;

		if (this->name == other.name)
			return false;
		else
			return true;
	}

	friend std::ostream& operator<<(std::ostream& out, const Discipline& disc)
	{
		out << "|Discipline: " << disc.name << std::endl;
		out << "|Type: " << disc.type << std::endl;
		out << "|Course: " << disc.course << std::endl;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Discipline& disc)
	{
		in >> disc.name;
		return in;
	}
};