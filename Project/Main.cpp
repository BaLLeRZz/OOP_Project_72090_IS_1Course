#include "Command.h"
int main()
{
	Command a;
	std::cout << "Choose a command or type 'help' to see the command list." << std::endl;
	std::cout << "Please type all commands CORRECTLY!" << std::endl;
	a.chooseCommand();
	return 0;
}