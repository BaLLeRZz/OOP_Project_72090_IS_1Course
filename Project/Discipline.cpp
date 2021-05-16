#include "Discipline.h"

Discipline::Discipline()
{
	this->name = "Empty";
	this->type = "None";
	this->course = 0;
	this->mark = 0;
}

Discipline::Discipline(const String _name, const String _type, size_t _course)
{
	this->name = _name;
	this->type = _type;
	this->course = _course;
	this->mark = 0;
}

void Discipline::setName(const String& _name)
{
	this->name = _name;
}

void Discipline::setMark(const double _mark)
{
	this->mark = _mark;
}

const String Discipline::getName() const
{
	return this->name;
}

size_t Discipline::getCourse() const
{
	return this->course;
}

double Discipline::getMark() const
{
	return this->mark;
}

Discipline& Discipline::operator=(const Discipline& other)
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

bool Discipline::operator==(const Discipline& other) const
{
	if (this == &other)
		return true;

	if (this->name == other.name)
		return true;
	else
		return false;
}

bool Discipline::operator!=(const Discipline& other) const
{
	if (this == &other)
		return false;

	if (this->name == other.name)
		return false;
	else
		return true;
}