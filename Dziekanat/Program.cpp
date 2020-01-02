#include "Program.h"

#include <iostream>

Program::Program()
{

}

void Program::run()
{
	int number;

	do{
		number = cmdManager.listen();
		this->window.refresh();
		if (number != -1 && number != 9) {
			switch (number) {
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
			
	} while (number != 9);
}
