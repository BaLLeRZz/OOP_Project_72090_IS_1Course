#pragma once
#include "Student.h"
#include <fstream>
class Command
{
private:
	String command;
	Vector<Student> students;
	Vector<Specialty> specialties;
	Vector<Discipline> disciplines;
public:
	Command();
	void commandList() const;
	void chooseCommand();
	bool checkFn(const size_t&) const;
	bool checkSpec(Specialty&);
	bool checkDisc(Discipline&);
	String takeCommand(String);
	String takeSpecialty(String);
	String takeName(String);
	size_t takeFacultyNumber(String&);
	size_t takeNumber(String);
	void printDisciplines() const;
	void printSpecialties() const;
	void printDiscInfo(Discipline&);
	void printSpecInfo(Specialty&);

	void enroll(const size_t&, Specialty&, const size_t&, const String&);
	void advance(const size_t&);
	void change(const size_t&);
	void graduate(const size_t&);
	void interrupt(const size_t&);
	void resume(const size_t&);
	void print(const size_t&) const;
	void printAll(Specialty&, const size_t&);
	void enrollIn(const size_t&, Discipline&);
	void addGrade(const size_t&, Discipline&, const double&);
	void protocol(Discipline&);
	void report(const size_t&) const;
	void save(std::ofstream&) const;
	void open(std::ifstream&);
};