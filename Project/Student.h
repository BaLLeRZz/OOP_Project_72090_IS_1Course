#pragma once
#include"Specialty.h"
#include <fstream>
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
	void save(std::ofstream&);
	void load(std::ifstream&);
	void removeDisc(const size_t);

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

	friend std::ostream& operator<<(std::ostream& out, Student& st)
	{
		out << "Student: " << st.name << std::endl;
		out << "Faculty Number: " << st.facultyNumber << std::endl;
		out << "Course: " << st.course << std::endl;
		out << "Specialty: " << st.specialty << std::endl;
		out << "Group: " << st.group << std::endl;
		out << "Status: " << st.status << std::endl;
		out << "Avarage: " << st.avarage();
		return out;
	}

	friend std::istream& operator>>(std::istream& in, Student& st)
	{
		in >> st.name;
		in >> st.facultyNumber;
		in >> st.course;
		in >> st.specialty;
		in >> st.group;
		in >> st.status;
		return in;
	}
};