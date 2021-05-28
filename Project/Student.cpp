#include "Student.h"

Student::Student() : name("Empty"), facultyNumber(0), course(0), group(0), status("None") {};

double Student::avarage()
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return 0;
	}

	if (this->list.getSize() == 0)
		return 0;

	double sum = 0;
	size_t size = this->list.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (this->list[i].getMark() < 3)
			this->list[i].setMark(2);

		sum += this->list[i].getMark();
	}

	return ceil(100 * ((double)sum / this->list.getSize())) / 100;
}

bool Student::passedAllExams() const
{
	size_t size = this->list.getSize();
	if (size == 0)
	{
		std::cout << "Student did not take any exams!" << std::endl;
		return false;
	}

	for (size_t i = 0; i < size; i++)
		if (this->list[i].getMark() < 3)
		{
			std::cout << "Student did not pass all exams!" << std::endl;
			return false;
		}

	return true;
}

bool Student::isDiscInList(const Discipline& discipline)
{
	size_t size = this->list.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (this->list[i] == discipline)
			return true;
	}

	return false;
}

void Student::removeDisc(const size_t index)
{
	if (index >= this->list.getSize())
		return;

	this->list.remove(index);
}

void Student::clearList()
{
	this->list.clear();
}

void Student::setSpecialty(const Specialty& _specialty)
{
	this->specialty = _specialty;
}

void Student::setGroup(const size_t& _group)
{
	this->group = _group;
}

void Student::setCourse(const size_t& _course)
{
	this->course = _course;
}

const String Student::getName() const
{
	return this->name;
}

size_t Student::getFacultyNumber() const
{
	return this->facultyNumber;
}

size_t Student::getCourse() const
{
	return this->course;
}

const String Student::getSpecialty() const
{
	return this->specialty.getName();
}

const String Student::getStatus() const
{
	return this->status;
}

size_t Student::getListSize() const
{
	return this->list.getSize();
}

void Student::save(std::ofstream& saveData)
{
	saveData << this->name << std::endl;
	saveData << this->facultyNumber << std::endl;
	saveData << this->course << std::endl;
	saveData << this->specialty << std::endl;
	saveData << this->group << std::endl;
	saveData << this->status << std::endl;
	saveData << this->avarage() << std::endl;
}

void Student::load(std::ifstream& loadData)
{
	loadData >> this->name;
	if (this->name == "") // instead cin.ignore()
		loadData >> this->name;
	loadData >> this->facultyNumber;
	loadData >> this->course;
	loadData.get();
	loadData >> this->specialty;
	loadData >> this->group;
	loadData.get();
	loadData >> this->status;
}

void Student::enroll(const size_t& _facultyNumber, const Specialty& _specialty, const size_t& _group, const String& _name)
{
	this->name = _name;
	this->facultyNumber = _facultyNumber;
	this->course = 1;
	this->specialty = _specialty;
	this->group = _group;
	this->status = "Registered";
}

void Student::advance()
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	if (this->course == 4)
	{
		std::cout << "Student is currently in 4th course and cannot advance to next course!" << std::endl;
		return;
	}

	this->course++;
	std::cout << "Student Advanced Successfully!" << std::endl;
}

void Student::graduate()
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	if (this->course == 4 && this->passedAllExams() && this->status == "Registered")
	{
		this->status = "Graduated";
		std::cout << "Student Graduated Successfully!" << std::endl;
	}
	else
		std::cout << "Student does not meet the requirements to graduate!" << std::endl;
}

void Student::interrupt()
{
	if (this->status == "Registered")
	{
		this->status = "Dropout";
		std::cout << "Student Interrupted Successfully!" << std::endl;
	}
	else
		std::cout << "Student is not Registered and cannot interrupt!" << std::endl;
}

void Student::resume()
{
	if (this->status == "Dropout")
	{
		this->status = "Registered";
		std::cout << "Student Resumed Successfully!" << std::endl;
	}
	else
		std::cout << "Student is not a Dropout and cannot resume!" << std::endl;
}

void Student::print()
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	std::cout << "Student: " << this->name << std::endl;
	std::cout << "Faculty Number: " << this->facultyNumber << std::endl;
	std::cout << "Course: " << this->course << std::endl;
	std::cout << "Specialty: " << this->specialty << std::endl;
	std::cout << "Group: " << this->group << std::endl;
	std::cout << "Status: " << this->status << std::endl;
	std::cout << "Avarage: " << this->avarage() << std::endl;
}

void Student::takeUpDiscipline(const Discipline& discipline)
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	if (this->course != discipline.getCourse())
	{
		std::cout << "Discipline's course does not match the student's course!" << std::endl;
		return;
	}

	size_t size = this->list.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->list[i] == discipline)
		{
			std::cout << "The student is already registered in this discipline!" << std::endl;
			return;
		}

	this->list.add(discipline);
	std::cout << "Student Registered in Discipline Successfully!" << std::endl;
}

void Student::addMark(const Discipline& discipline, const double& mark)
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	if (mark < 2 || mark > 6)
	{
		std::cout << "Invalid grade!" << std::endl;
		return;
	}

	size_t size = this->list.getSize();
	for (size_t i = 0; i < size; i++)
		if (discipline == this->list[i])
		{
			int temp = floor(10 * mark);
			if (temp % 10 >= 5)
			{
				this->list[i].setMark(ceil(mark));
				std::cout << "Student Graded Successfully!" << std::endl;
				return;
			}
			else
			{
				this->list[i].setMark(floor(mark));
				std::cout << "Student Graded Successfully!" << std::endl;
				return;
			}
		}
}

void Student::examsInfo()
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	size_t size = this->list.getSize();
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
	std::cout << ">>>Passed exams<<<" << std::endl;
	std::cout << "******************" << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if (this->list[i].getMark() >= 3)
		{
			std::cout << this->list[i];
			std::cout << "|Grade: " << this->list[i].getMark() << std::endl << std::endl;
		}
	}
	std::cout << std::endl << std::endl;
	std::cout << ">>>Failed exams<<<" << std::endl;
	std::cout << "******************" << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		if (this->list[i].getMark() < 3)
		{
			this->list[i].setMark(2);
			std::cout << this->list[i];
			std::cout << "|Grade: " << this->list[i].getMark() << std::endl << std::endl;
		}
	}
	std::cout << "Avarage: " << this->avarage() << std::endl;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void Student::protocol(const Discipline& discipline)
{
	if (this->status != "Registered")
	{
		std::cout << "Student is not Registered!" << std::endl;
		return;
	}

	size_t size = this->list.getSize();
	for(size_t i = 0; i < size; i++)
		if (this->list[i] == discipline && this->course == discipline.getCourse())
		{
			this->print();
			return;
		}
	
}