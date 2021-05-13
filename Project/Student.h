#pragma once
#include"Specialty.h"
class Student
{
private:
	String name;
	size_t facultyNumber;
	size_t course;
	Specialty specialty;
	size_t group;
	String status;
	Vector<Discipline> list;
public:
	Student();
	double avarage();
	void printList() const;
	bool passedAllExams() const;
	bool isDiscInList(const Discipline&);
	void replaceList(const Vector<Discipline>&); // prerazgledai
	void setSpecialty(const Specialty&);
	void setGroup(const size_t&);
	void setCourse(const size_t&);
	const String getName() const;
	size_t getFacultyNumber() const;
	size_t getCourse() const;
	const String getSpecialty() const;
	size_t getGroup() const;
	const String getStatus() const;
	size_t getListSize() const;

	void enroll(const size_t&, const Specialty&, const size_t&, const String&);
	void advance();
	void graduate();
	void interrupt();
	void resume();
	void print();
	void takeUpDiscipline(const Discipline&);
	void addMark(const Discipline&, const double&);
	void examsInfo();
	void protocol(const Discipline&);
};