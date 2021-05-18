#pragma once
#include "Student.h"
class Command
{
private:
	String command;
	Vector<Student> students;
	Vector<Specialty> specialties;
	Vector<Discipline> disciplines;
	size_t fileSize;
	bool isOpen;
public:
	Command();
	void commandList() const;
	void chooseCommand();

	bool checkFn(const size_t&) const;
	bool checkSpec(Specialty&);
	bool checkDisc(Discipline&);

	String takeCommand(String);
	size_t takeFacultyNumber(String&);
	String takeSpecialty(String);
	size_t takeNumber(String);
	String takeName(String);
	const char* takeFileName(String&);

	void printDisciplines() const;
	void printSpecialties() const;
	void printDiscInfo(Discipline&);
	void printSpecInfo(Specialty&);

	void save();
	void load();

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
};