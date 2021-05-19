#include "Specialty.h"

Specialty::Specialty()
{
	this->name = "Empty";
}

Specialty::Specialty(const String _name)
{
	this->name = _name;
}

const String Specialty::getName() const
{
	return this->name;
}

size_t Specialty::getListSize() const
{
	return this->list.getSize();
}

bool Specialty::isDisciplineInList(const Discipline& discipline) const
{
	size_t size = this->list.getSize();
	for (size_t i = 0; i < size; i++)
		if (discipline == this->list[i])
			return true;

	return false;
}

void Specialty::addDiscipline(const Discipline& discipline)
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

void Specialty::print() const
{
	std::cout << "Specialty: " << this->name << std::endl;
	std::cout << "Disciplines: " << this->list.getSize() << std::endl << std::endl;
	this->list.print();
}

Specialty& Specialty::operator=(const Specialty& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->list = other.list;
	}
	return *this;
}

bool Specialty::operator==(const Specialty& other) const
{
	if (this == &other)
		return true;

	if (this->name == other.name)
		return true;

	return false;
}

bool Specialty::operator==(const char* other) const
{
	return this->name == other;
}

bool Specialty::operator!=(const Specialty& other) const
{
	if (this == &other)
		return false;

	if (this->name == other.name)
		return false;

	return true;
}