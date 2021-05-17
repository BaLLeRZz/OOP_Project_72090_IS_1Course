#include "Command.h"
int main()
{
	/*Command a;
	std::cout << "Choose a command or type 'help' to see the command list." << std::endl;
	std::cout << "Please type all commands CORRECTLY!" << std::endl;
	a.chooseCommand();*/
	Student a;
	Specialty b("Bulgarski");
	String c = "Georgi";
	char d[12] = "D:\\test.txt";
	//std::ofstream e("D:\\test.txt");
	std::ifstream f("D:\\test.txt");
	a.enroll(1, b, 3, c);
	//a.save(e);
	a.load(f);
	std::cout << a << std::endl;
	
	
	return 0;
}