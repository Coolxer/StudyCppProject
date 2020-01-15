#pragma once
#include "Window.h"

/* Klasa glowna programu */

class Program
{
private:
	Window window; // obiekt klasy Window

public:
	Program(); // konstruktor domyslny
	void run(); // metoda uruchamiajaca program
};

