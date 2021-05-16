#pragma once
#include "Discipline.h" 
#include "Vector.h"
class Specialty
{
private:
	String name;
	Vector<Discipline> list;
public:
	Specialty();
	Specialty(const String _name);

	const String getName() const;
	size_t getListSize() const;
	bool isDisciplineInList(const Discipline&) const;
	void addDiscipline(const Discipline&);
	void print() const;

	Specialty& operator=(const Specialty&);
	bool operator==(const Specialty&) const;
	bool operator!=(const Specialty&) const;

	friend std::ostream& operator<<(std::ostream& out, const Specialty& spec)
	{
		out << spec.name;
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Specialty& spec)
	{
		in >> spec.name;
		return in;
	}
};