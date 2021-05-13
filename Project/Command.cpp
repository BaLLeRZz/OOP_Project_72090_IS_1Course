#include "Command.h"

Command::Command()
{
	Specialty IS("IS"), SI("SE"), MATH("Math");

	Discipline DS("DS", "Compulsory", 1);
	Discipline A("A", "Compulsory", 2);
	Discipline IP("IP", "Compulsory", 1);
	Discipline DIS("DIS", "Compulsory", 3);
	Discipline G("G", "Compulsory", 3);
	Discipline OOP("OOP", "Compulsory", 2);
	Discipline FP("FP", "Compulsory", 1);
	Discipline BIS("BIS", "Eligible", 1);
	Discipline Pract("Pract", "Eligible", 1);
	Discipline E("E", "Eligible", 2);
	Discipline DM("DM", "Compulsory", 4);
	Discipline IT("IT", "Compulsory", 2);
	Discipline SD("SD", "Compulsory", 3);
	Discipline HC("HC", "Eligible", 4);
	Discipline MT("MT", "Eligible", 4);

	this->disciplines.add(DS);
	this->disciplines.add(A);
	this->disciplines.add(IP);
	this->disciplines.add(DIS);
	this->disciplines.add(G);
	this->disciplines.add(OOP);
	this->disciplines.add(FP);
	this->disciplines.add(BIS);
	this->disciplines.add(Pract);
	this->disciplines.add(E);
	this->disciplines.add(DM);
	this->disciplines.add(IT);
	this->disciplines.add(SD);
	this->disciplines.add(HC);
	this->disciplines.add(MT);

	IS.addDiscipline(IP);
	IS.addDiscipline(OOP);
	IS.addDiscipline(FP);
	IS.addDiscipline(Pract);
	IS.addDiscipline(SD);

	SI.addDiscipline(BIS);
	SI.addDiscipline(E);
	SI.addDiscipline(IT);
	SI.addDiscipline(HC);
	SI.addDiscipline(MT);

	MATH.addDiscipline(DS);
	MATH.addDiscipline(A);
	MATH.addDiscipline(DIS);
	MATH.addDiscipline(G);
	MATH.addDiscipline(DM);

	this->specialties.add(IS);
	this->specialties.add(SI);
	this->specialties.add(MATH);
}

void Command::commandList() const
{
	std::cout << std::endl << std::endl << "-----------------------------------------------COMMANDS LIST----------------------------------------------" << std::endl << std::endl;
	std::cout << "- help -> Gives information about all available commands." << std::endl;
	std::cout << "- exit -> Exits the program." << std::endl;
	std::cout << "- save -> Saves all information." << std::endl;
	std::cout << "- open -> Opens the file to make changes." << std::endl;
	std::cout << "- enroll <fn> <spec> <group> <name> -> Registers a Student in 1 Course." << std::endl;
	std::cout << "- advance <fn> -> Transfers a Student in a next Course." << std::endl;
	std::cout << "- change <fn> <option> <value> -> Changes a Student from <option> to <value> (specialty/group/course)." << std::endl;
	std::cout << "- graduate <fn> -> Marks a Student as Graduated." << std::endl;
	std::cout << "- interrupt <fn> -> Marks a Student as Dropout." << std::endl;
	std::cout << "- resume <fn> -> Marks a Student as Registered." << std::endl;
	std::cout << "- print <fn> -> Prints information about a Student." << std::endl;
	std::cout << "- printAll <spec> <course> -> Prints information about all Students in a Specialty and Course." << std::endl;
	std::cout << "- enrollIn <fn> <disc> -> Registers a Student in a Discipline." << std::endl;
	std::cout << "- addGrade <fn> <disc> <grade> -> Adds a grade to a Discipline for a Student." << std::endl;
	std::cout << "- protocol <disc> -> Prints information about all Students, Registered in a Discipline." << std::endl;
	std::cout << "- report <fn> -> Academic information about all Exams of a Student." << std::endl;
	std::cout << "- discList -> Disciplines List." << std::endl;
	std::cout << "- specList -> Specialties List." << std::endl;
	std::cout << "- discInfo <disc> -> Prints information about a Discipline." << std::endl;
	std::cout << "- specInfo <spec> -> Prints infromation about a Specialty." << std::endl;
	std::cout << std::endl << "----------------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

void Command::chooseCommand()
{
	bool flag = true;
	do
	{
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "Command: ";
		std::cin >> this->command;

		String comm = this->takeCommand(this->command);
		size_t facultyNumber = this->takeFacultyNumber(this->command);

		if (comm == "help")
			this->commandList();
		else
			if (comm == "discList")
				this->printDisciplines();
			else
				if (comm == "specList")
					this->printSpecialties();
				else
					if (comm == "enroll")
					{
						String name = this->takeName(this->command);
						size_t group = this->takeNumber(this->command);
						Specialty specialty = this->takeSpecialty(this->command);
						this->enroll(facultyNumber, specialty, group, name);
					}
					else
						if (comm == "advance")
							this->advance(facultyNumber);
						else
							if (comm == "graduate")
								this->graduate(facultyNumber);
							else
								if (comm == "interrupt")
									this->interrupt(facultyNumber);
								else
									if (comm == "resume")
										this->resume(facultyNumber);
									else
										if (comm == "print")
											this->print(facultyNumber);
										else
											if (comm == "printAll")
											{
												size_t course = this->takeNumber(this->command);
												Specialty specialty = this->takeSpecialty(this->command);
												this->printAll(specialty, course);
											}
											else
												if (comm == "enrollIn")
												{
													String name = this->takeName(this->command);
													Discipline discipline;
													discipline.setName(name);
													this->enrollIn(facultyNumber, discipline);
												}
												else
													if (comm == "addGrade")
													{
														String name = this->takeName(this->command);
														Discipline discipline;
														discipline.setName(name);
														size_t grade = this->takeNumber(this->command);
														this->addGrade(facultyNumber, discipline, grade);
													}
													else
														if (comm == "protocol")
														{
															String name = this->takeName(this->command);
															Discipline discipline;
															discipline.setName(name);
															this->protocol(discipline);
														}
														else
															if (comm == "report")
																this->report(facultyNumber);
															else
																if (comm == "exit")
																{
																	std::cout << "Goodbye! :)";
																	flag = false;
																}
																else
																	if (comm == "discInfo")
																	{
																		String name = this->takeName(this->command);
																		Discipline discipline;
																		discipline.setName(name);
																		this->printDiscInfo(discipline);
																	}
																	else
																		if (comm == "specInfo")
																		{
																			Specialty specialty = this->takeSpecialty(this->command);
																			this->printSpecInfo(specialty);
																		}
																		else
																			if (comm == "change")
																				this->change(facultyNumber);
		            										else
		            											std::cout << "Invalid Command!" << std::endl;
		this->command.clear();
	} while (flag);
}

bool Command::checkFn(const size_t& facultyNumber) const
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (facultyNumber == this->students[i].getFacultyNumber())
			return true;
	
	return false;
	
}

bool Command::checkSpec(Specialty& specialty)
{
	size_t size = this->specialties.getSize();
	for (size_t i = 0; i < size; i++)
		if (specialty == this->specialties[i])
		{
			specialty = this->specialties[i];
			return true;
		}

	return false;
}

bool Command::checkDisc(Discipline& discipline)
{
	size_t size = this->disciplines.getSize();
	for (size_t i = 0; i < size; i++)
		if (discipline == this->disciplines[i])
		{
			discipline = this->disciplines[i];
			return true;
		}

	return false;
}

String Command::takeCommand(String _command)
{
	bool flag = false;
	size_t size = _command.getLength();
	for (size_t i = 0; i < size; i++)
	{
		if ((_command[i] >= 'a' && _command[i] <= 'z') || (_command[i] >= 'A' && _command[i] <= 'Z'))
			flag = true;

		if (_command[i] == ' ' && flag)
		{
			_command[i] = '\0';
			break;
		}
		if(!flag)
		{
			_command.remove(i);
			i--;
		}
	}
	return _command;
}

String Command::takeSpecialty(String _command)
{
	size_t size = _command.getLength();
	bool flag = false;
	for (size_t i = 0; i < size; i++)
	{
		while (_command[i] != ' ')
		{
			if (_command[i + 1] == ' ')
			{
				_command.remove(i);
				flag = true;
				break;
			}
			_command.remove(i);
		}
		if (flag)
			break;
	}
	
	size = _command.getLength();
	flag = false;
	for (size_t i = 0; i < size; i++)
	{
		if ((_command[i] >= 'a' && _command[i] <= 'z') || (_command[i] >= 'A' && _command[i] <= 'Z'))
			flag = true;

		if (_command[i] == ' ' && flag)
		{
			_command[i] = '\0';
			break;
		}
		
		if(!flag)
		{
			_command.remove(i);
			i--;
		}
	}
	
	return _command;
}

String Command::takeName(String _command)
{
	size_t position = 0, count = 0;
	size_t size = this->command.getLength();
	bool flag = false;
	for (size_t i = size - 1; i >= 0; i--)
	{
		if ((_command[i] >= 'a' && _command[i] <= 'z') || (_command[i] >= 'A' && _command[i] <= 'Z'))
		{
			count++;
			flag = true;
		}

		if (_command[i] != ' ' && _command[i - 1] == ' ' && flag)
		{
			position++;
			break;
		}
		position++;
	}

	for (size_t i = size - position, j = 0; j < count; i++, j++)
	{
		_command[j] = _command[i];
	}
	_command[count] = '\0';
	return _command;
}

size_t Command::takeFacultyNumber(String& _command)
{
	size_t count = 0;
	size_t size = _command.getLength();
	for (size_t i = 0; i < size; i++)
		if (_command[i] >= '0' && _command[i] <= '9')
		{
			if ((_command[i + 1] < '0' || _command[i + 1] > '9') && _command[i + 1] != ' ')
				return 0;

			if (_command[i + 1] < '0' || _command[i + 1] > '9')
			{
				count++;
				break;
			}
			else
				count++;
		}

	size_t position = pow(10, count - 1);
	size_t sum = 0;
	for (size_t i = 0; i < size; i++)
		if (_command[i] >= '0' && _command[i] <= '9')
		{
			sum += position * (_command[i] - 48);
			position /= 10;
		}

	return sum;
}

size_t Command::takeNumber(String _command)
{
	size_t position = 0, count = 0;
	size_t size = _command.getLength();
	bool flag = false;
	for (size_t i = size - 1; i >= 0; i--)
	{
		if (_command[i] >= '0' && _command[i] <= '9')
		{
			if ((_command[i + 1] < '0' || _command[i + 1] > '9') && _command[i + 1] != ' ')
				return 0;

			count++;
			flag = true;
		}

		if (_command[i] != ' ' && _command[i - 1] == ' ' && flag)
		{
			position++;
			break;
		}
		position++;
	}

	for (size_t i = size - position, j = 0; j < count; i++, j++)
	{
		_command[j] = _command[i];
	}
	_command[count] = '\0';

	return this->takeFacultyNumber(_command);
}

void Command::printDisciplines() const
{
	std::cout << "DS - Discrete Structures" << std::endl;
	std::cout << "A - Algebra" << std::endl;
	std::cout << "IP - Introduction to Programming" << std::endl;
	std::cout << "DIS - Differential and Integral Calculation" << std::endl;
	std::cout << "G - Geometry" << std::endl;
	std::cout << "OOP - Object Orientated Programming" << std::endl;
	std::cout << "FP - Functional Programming" << std::endl;
	std::cout << "BIS - Basics of IS" << std::endl;
	std::cout << "Pract - Practice" << std::endl;
	std::cout << "E - English" << std::endl;
	std::cout << "DM - Discrete Math" << std::endl;
	std::cout << "IT - Information Technology" << std::endl;
	std::cout << "SD - Structures of Data" << std::endl;
	std::cout << "HC - Hacking Courses" << std::endl;
	std::cout << "MT - Mind Training" << std::endl;
}

void Command::printSpecialties() const
{
	std::cout << "IS - Information Systems" << std::endl;
	std::cout << "SE - Software Engineering" << std::endl;
	std::cout << "Math - Mathematics" << std::endl;
}

void Command::printDiscInfo(Discipline& discipline)
{
	if (!this->checkDisc(discipline))
	{
		std::cout << "Discipline does not exist!" << std::endl;
		return;
	}

	std::cout << discipline << std::endl;
}

void Command::printSpecInfo(Specialty& specialty)
{
	if (!this->checkSpec(specialty))
	{
		std::cout << "Specialty does not exist!" << std::endl;
		return;
	}

	specialty.print();
}

void Command::enroll(const size_t& facultyNumber, Specialty& specialty, const size_t& group, const String& name)
{
	if (this->checkFn(facultyNumber))
	{
		std::cout << "Faculty number already exists!" << std::endl;
		return;
	}

	if (facultyNumber == 0)
	{
		std::cout << "Invalid Faculty Number input!" << std::endl;
		return;
	}

	if (!this->checkSpec(specialty))
	{
		std::cout << "Invalid Specialty input!" << std::endl;
		return;
	}

	if (group < 1 || group > 5)
	{
		std::cout << "Invalid Group input!" << std::endl;
		return;
	}

	if (name == specialty.getName())
	{
		std::cout << "Invalid Name input!" << std::endl;
		return;
	}
	
	this->checkSpec(specialty);
	Student st;
	st.enroll(facultyNumber, specialty, group, name);
	this->students.add(st);
	std::cout << "Student Registered Successfully!" << std::endl;
}

void Command::advance(const size_t& facultyNumber)
{
	size_t size = this->students.getSize();
	bool flag = true;
	for(size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].advance();
			if (this->students[i].getCourse() <= 4 && flag)
			{
				std::cout << "Student Advanced Successfully!" << std::endl;
				if (this->students[i].getCourse() == 4)
				    flag = false;
				return;
			}
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::change(const size_t& facultyNumber)
{
	String option = this->takeSpecialty(this->command);
	String value = this->takeName(this->command);
	size_t group = value.convertFromString();
	size_t size = this->students.getSize();

	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			if (option == "specialty")
			{
				Specialty specialty = value;
				if (!this->checkSpec(specialty))
				{
					std::cout << "Specialty does not exist!" << std::endl;
					return;
				}
				this->checkSpec(specialty);
				this->students[i].setSpecialty(specialty);
				std::cout << "Specialty changed successfully!" << std::endl;
				//this->students[i].clearList();
			}
			else
				if (option == "group")
				{
					std::cout << group;
					if (group < 1 || group > 5)
					{
						std::cout << "Invalid Group Input!" << std::endl;
						return;
					}
					this->students[i].setGroup(group);
					std::cout << "Group changed successfully!" << std::endl;
				}
				else
					if (option == "course")
					{
						std::cout << group;
						if (group < 1 || group > 4)
						{
							std::cout << "Invalid Course Input!" << std::endl;
							return;
						}
						this->students[i].setCourse(group);
						std::cout << "Course changed successfully!" << std::endl;
					}
					else
					{
						std::cout << "Invalid Input!" << std::endl;
						return;
					}
			return;
		}

	std::cout << "Faculty Number does not exist!" << std::endl;
}

void Command::graduate(const size_t& facultyNumber)
{
	size_t size = this->students.getSize();
	for(size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].graduate();
			std::cout << "Student Graduated Successfully!" << std::endl;
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::interrupt(const size_t& facultyNumber)
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].interrupt();
			std::cout << "Student Interrupted Successfully!" << std::endl;
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::resume(const size_t& facultyNumber)
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].resume();
			std::cout << "Student Resumed Successfully!" << std::endl;
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::print(const size_t& facultyNumber) const
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			std::cout << "Student's information: " << std::endl;
			this->students[i].print();
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::printAll(Specialty& specialty, const size_t& course)
{
	this->checkSpec(specialty);
	bool flag = false;
	size_t sizeSp = this->specialties.getSize();
	for (size_t i = 0; i < sizeSp; i++)
		if (this->specialties[i] == specialty)
		{
			flag = true;
			break;
		}

	if (!flag)
	{
		std::cout << "Specialty does not exist!" << std::endl;
		return;
	}

	if (course < 1 || course > 4)
	{
		std::cout << "Invalid Course input!" << std::endl;
		return;
	}
	
	std::cout << "Students' information: " << std::endl;
	size_t sizeSt = this->students.getSize();
	for (size_t i = 0; i < sizeSt; i++)
		if (this->students[i].getSpecialty() == specialty.getName() && this->students[i].getCourse() == course)
		{
			this->students[i].print();
			std::cout << std::endl << std::endl;
		}
}

void Command::enrollIn(const size_t& facultyNumber, Discipline& discipline)
{
	this->checkDisc(discipline);
	size_t sizeS = this->students.getSize();
	size_t sizeD = this->disciplines.getSize();
	for (size_t i = 0; i < sizeS; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			for (size_t j = 0; j < sizeD; j++)
				if (this->disciplines[j] == discipline)
				{
					Specialty spec = this->students[i].getSpecialty();
					this->checkSpec(spec);
					if (spec.isDisciplineInList(discipline))
					{
						this->students[i].takeUpDiscipline(discipline);
						std::cout << "Student Registered in Discipline Successfully!" << std::endl;
						return;
					}
					std::cout << "Discipline is not included in Student's Specialty!" << std::endl;
					return;
				}
			std::cout << "Discipline does not exist!" << std::endl;
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::addGrade(const size_t& facultyNumber, Discipline& discipline, const double& grade)
{
	this->checkDisc(discipline);
	size_t sizeS = this->students.getSize();
	size_t sizeD = this->disciplines.getSize();
	bool flag = false;
	for (size_t i = 0; i < sizeS; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			for(size_t j = 0; j < sizeD; j++)
				if (this->disciplines[j] == discipline)
				{
					if (this->students[i].isDiscInList(discipline))
					{
						this->students[i].addMark(discipline, grade);
						std::cout << "Student Graded Successfully!" << std::endl;
						return;
					}
					std::cout << "Student is not registered in this discipline!" << std::endl;
					return;
				}
			std::cout << "Discipline does not exist!" << std::endl;
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::protocol(Discipline& discipline)
{
	this->checkDisc(discipline);
	bool flag = false;
	size_t sizeS = this->students.getSize();
	size_t sizeD = this->disciplines.getSize();
	for (size_t j = 0; j < sizeD; j++)
		if (this->disciplines[j] == discipline)
		{
			flag = true;
			break;
		}

	if (flag == false)
	{
		std::cout << "Discipline does not exist!" << std::endl;
		return;
	}

	Student temp;
	for (size_t i = 0; i < sizeS; i++)
		for (size_t j = i; j < sizeS; j++)
			if (this->students[i].getFacultyNumber() > this->students[j].getFacultyNumber())
			{
				temp = this->students[i];
				this->students[i] = this->students[j];
				this->students[j] = temp;
			}

	std::cout << "Discipline's Registered Students: " << std::endl;
	for (size_t i = 0; i < sizeS; i++)
	{
		this->students[i].protocol(discipline);
	}
}

void Command::report(const size_t& facultyNumber) const
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			std::cout << "Student's exams information: " << std::endl;
			this->students[i].examsInfo();
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}