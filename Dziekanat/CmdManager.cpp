#include "CmdManager.h"

#include <iostream>

CmdManager::CmdManager()
{

}

CmdManager::~CmdManager()
{

}

int CmdManager::listen()
{
	int input;

	std::cin >> input; // pobranie danych od uzytkownika

	// sprawdzenie czy uzytkownik wpisal liczbe
	if (!std::cin.good()) {
		std::cout << "Wpisuj liczby z zakresu [ 0 - 9 ]" << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}
	// sprawdzenie czy wpisana liczba miesci sie w zakresie [0-9]
	else if (input < 0 || input > 9) {
		std::cout << "Nie ma takiej opcji" << std::endl;
	}
	else
		return input; // zwrocenie wpisanego numeru

	return -1; // zwrocenie bledu (-1)

}
