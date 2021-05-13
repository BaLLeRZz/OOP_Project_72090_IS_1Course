#pragma once
#include "Discipline.h" 
#include "Vector.h"
class Specialty
{
private:
	String name;
	Vector<Discipline> list;
public:
	Specialty() : name("None") {};
	Specialty(const String _name) : name(_name) {};

	const String getName() const
	{
		return this->name;
	}

	size_t getListSize() const
	{
		return this->list.getSize();
	}

	bool isDisciplineInList(const Discipline& discipline) const
	{
		size_t size = this->list.getSize();
		for (size_t i = 0; i < size; i++)
			if (discipline == this->list[i])
				return true;

		return false;
	}

	void addDiscipline(const Discipline& discipline)
	{
		size_t size = this->list.getSize();
		for (size_t i = 0; i < size; i++)
			if (this->isDisciplineInList(discipline))
			{
				std::cout << "Discipline is already in this specialty!" << std::endl;
				return;
			}

		this->list.add(discipline);
	}

	void print() const
	{
		std::cout << "Specialty: " << this->name << std::endl;
		std::cout << "Disciplines: " << this->list.getSize() << std::endl << std::endl;
		this->list.print();
	}

	Specialty& operator=(const Specialty& other)
	{
		if (this != &other)
		{
			this->name = other.name;
			this->list = other.list;
		}
		return *this;
	}

	bool operator==(const Specialty& other) const
	{
		if (this == &other)
			return true;

		if (this->name == other.name)
			return true;

		return false;
	}

	bool operator!=(const Specialty& other) const
	{
		if (this == &other)
			return false;

		if (this->name == other.name)
			return false;

		return true;
	}

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