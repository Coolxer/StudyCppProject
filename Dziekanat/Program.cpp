#include "Program.h"

#include <iostream>

Program::Program()
{

}

void Program::run()
{
	int option;

	do{
		option = cmdManager.listen();

		if (option == 9)
			break;
		else if (option == -1)
			continue;
		else
		{
			switch (option) {
			case 1:
				std::cout << '1';
				break;
			case 2:
				std::cout << '2';
				break;
			case 3:
				std::cout << '3';
				break;
			}
		}	
	} while (true);
}
