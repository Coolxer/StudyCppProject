#include "CmdManager.h"

#include <iostream>

CmdManager::CmdManager()
{

}

int CmdManager::listen()
{
	int input;

	std::cin >> input;

	if (!std::cin.good()) {
		std::cout << "Wpisuj liczby lelasie" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	else if (input < 1 || input > 5) {
		std::cout << "Nie ma takiej opcji" << std::endl;
	}
	else
		return input;

	return -1;

}
