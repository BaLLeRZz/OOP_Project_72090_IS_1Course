#include "Command.h"
int main()
{
	Command app;
	std::cout << "Choose a command or type 'help' to see the command list." << std::endl;
	std::cout << "Please type all commands CORRECTLY!" << std::endl;
	app.chooseCommand();
	return 0;
}