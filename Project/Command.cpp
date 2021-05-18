#include "Command.h"

Command::Command()
{
	this->fileSize = 0;
	isOpen = false;

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
	std::cout << "- open <directory> -> Opens the file to make changes." << std::endl;
	std::cout << "- save -> Saves all information in the current opened file." << std::endl;
	std::cout << "- saveAs <directory> -> Saves all information from the current opened file in the Directory." << std::endl;
	std::cout << "- close -> Closes the file and prohibits the usage of commands until another file is opened." << std::endl;
	std::cout << "- exit -> Exits the program." << std::endl;
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
		{
			this->commandList();
			continue;
		}

		if (comm == "open" && !this->isOpen)
			this->load();

		else
		if (comm == "open" && this->isOpen)
			std::cout << "A file is already opened! Close it and try again!" << std::endl;

		else
		if (!isOpen)
			std::cout << "You must open a file to use commands!" << std::endl;

		if (isOpen)
		{
			if (comm == "save")
				this->save();

			/*else
			if (comm == "saveAs")
				this->saveAs();

			else
			if (comm == "close")
				this->close();*/

			else
			if (comm == "exit")
			{
				std::cout << "Goodbye! :)";
				flag = false;
			}

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
			if (comm == "change")
				this->change(facultyNumber);

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
			if (comm == "discList")
				this->printDisciplines();

			else
			if (comm == "specList")
				this->printSpecialties();

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
		}
		this->command.clear();
	}
	while (flag);
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

const char* Command::takeFileName(String& _command)
{
	size_t size = _command.getLength();
	char* fileN = new char[_command.getLength() + 1];
	for (size_t i = 0; i < _command.getLength(); i++)
		fileN[i] = _command[i];

	fileN[size] = '\0';
	bool flag = false;
	for (size_t i = 0; i < size; i++)
	{
		while (fileN[i] != ' ')
		{
			if (fileN[i + 1] == ' ')
			{
				fileN[i] = ' ';
				flag = true;
				break;
			}
			fileN[i] = ' ';
			i++;
		}
		if (flag)
			break;
	}

	flag = false;
	size_t count = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((fileN[i] >= 'a' && fileN[i] <= 'z') || (fileN[i] >= 'A' && fileN[i] <= 'Z'))
			flag = true;

		if (flag)
		{
			for (size_t j = 0; j < size; j++)
			{
				if (fileN[i] == ' ')
				{
					fileN[j] = '\0';
					break;
				}

				fileN[j] = fileN[i];
				i++;
			}
			break;
		}
	}

	return fileN;
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

void Command::save()
{
	if (this->students.getSize() == 0)
	{
		std::cout << "No Data to save!" << std::endl;
		return;
	}

	String temp = this->takeSpecialty(this->command);
	size_t sizeFileName = temp.getLength();
	char* fileN = new char[sizeFileName + 1];
	strcpy_s(fileN, sizeFileName + 1, this->takeFileName(this->command));

	std::ofstream saveData(fileN, std::ios::beg);
	if (saveData.is_open())
	{
		size_t size = this->students.getSize();
		saveData << size << std::endl;
		for (size_t i = 0; i < size; i++)
		{
			this->students[i].save(saveData);
			saveData << std::endl;
		}
	}
	else
		std::cout << "File did not open!" << std::endl;

	std::cout << "Data Saved successfully!" << std::endl;
}

void Command::load()
{
	String temp = this->takeSpecialty(this->command);
	size_t size = temp.getLength();
	char* fileN = new char[size + 1];
	strcpy_s(fileN, size + 1, this->takeFileName(this->command));

	if (fileN[0] != 'C' && fileN[0] != 'D')
	{
		std::cout << "Invalid file path input!" << std::endl;
		return;
	}

	if (fileN[1] != ':' || fileN[2] != '\\')
	{
		std::cout << "Invalid file path input!" << std::endl;
		return;
	}

	if (fileN[size - 1] != 't' || fileN[size - 2] != 'x' || fileN[size - 3] != 't' || fileN[size - 4] != '.')
	{
		std::cout << "Invalid file path input!" << std::endl;
		return;
	}

    std::ifstream loadData(fileN);
	if (loadData.is_open())
	{
		loadData >> this->fileSize;
		for (size_t i = 0; i < this->fileSize; i++)
			this->students[i].load(loadData); //<----
	}
	else
	{
		std::ofstream createFile(fileN);
		createFile << this->fileSize << std::endl;
	}

	this->isOpen = true;
	std::cout << "File opened successfully!" << std::endl;
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
	this->fileSize++;
	std::cout << "Student Registered Successfully!" << std::endl;
}

void Command::advance(const size_t& facultyNumber)
{
	size_t size = this->students.getSize();
	for(size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			this->students[i].advance();
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::change(const size_t& facultyNumber)
{
	String option = this->takeSpecialty(this->command);
	String value = this->takeName(this->command);
	size_t group = this->takeNumber(this->command);
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

				size_t count = this->students[i].getListSize();
				for (size_t j = 0; count > 0;)
				{
					this->students[i].removeDisc(j);
					count--;
				}

				this->checkSpec(specialty);
				this->students[i].setSpecialty(specialty);

				std::cout << "Specialty changed successfully!" << std::endl;
				return;
				
			}
			else
				if (option == "group")
				{
					if (group < 1 || group > 5)
					{
						std::cout << "Invalid Group Input!" << std::endl;
						return;
					}
					this->students[i].setGroup(group);
					std::cout << "Group changed successfully!" << std::endl;
					return;
				}
				else
					if (option == "course")
					{
						if (group < 1 || group > 4)
						{
							std::cout << "Invalid Course Input!" << std::endl;
							return;
						}
						this->students[i].setCourse(group);
						std::cout << "Course changed successfully!" << std::endl;
						return;
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
			std::cout << "Student's information: " << std::endl << std::endl;
			this->students[i].print();
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}

void Command::printAll(Specialty& specialty, const size_t& course)
{
	if (!this->checkSpec(specialty))
	{
		std::cout << "Specialty does not exist!" << std::endl;
		return;
	}

	if (course < 1 || course > 4)
	{
		std::cout << "Invalid Course input!" << std::endl;
		return;
	}
	
	std::cout << "Students' information: " << std::endl << std::endl;
	size_t size = this->students.getSize();
	this->checkSpec(specialty);
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getSpecialty() == specialty.getName() && this->students[i].getCourse() == course)
		{
			this->students[i].print();
			std::cout << std::endl << std::endl;
		}
}

void Command::enrollIn(const size_t& facultyNumber, Discipline& discipline)
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
				if (this->checkDisc(discipline))
				{
					Specialty spec = this->students[i].getSpecialty();
					this->checkSpec(spec);
					this->checkDisc(discipline);
					if (spec.isDisciplineInList(discipline))
					{
						this->students[i].takeUpDiscipline(discipline); // <----------------------
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
				if (this->checkDisc(discipline))
				{
					if (this->students[i].isDiscInList(discipline))
					{
						this->students[i].addMark(discipline, grade);
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
	size_t size = this->students.getSize();
	if (!this->checkDisc(discipline))
	{
		std::cout << "Discipline does not exist!" << std::endl;
		return;
	}

	Student temp;
	for (size_t i = 0; i < size; i++)
		for (size_t j = i; j < size; j++)
			if (this->students[i].getFacultyNumber() > this->students[j].getFacultyNumber())
			{
				temp = this->students[i];
				this->students[i] = this->students[j];
				this->students[j] = temp;
			}

	this->checkDisc(discipline);
	std::cout << "Discipline's Registered Students: " << std::endl << std::endl;
	for (size_t i = 0; i < size; i++)
	{
		this->students[i].protocol(discipline);
		std::cout << std::endl;
	}
}

void Command::report(const size_t& facultyNumber) const
{
	size_t size = this->students.getSize();
	for (size_t i = 0; i < size; i++)
		if (this->students[i].getFacultyNumber() == facultyNumber)
		{
			std::cout << "Student's exams information: " << std::endl << std::endl;
			this->students[i].examsInfo();
			return;
		}

	std::cout << "Faculty number does not exist!" << std::endl;
}