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
	Discipline();
	Discipline(const String, const String, size_t);

	void setName(const String&);
	void setMark(const double);
	const String getName() const;
	size_t getCourse() const;
	double getMark() const;

	Discipline& operator=(const Discipline&);
	bool operator==(const Discipline&) const;
	bool operator!=(const Discipline&) const;

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