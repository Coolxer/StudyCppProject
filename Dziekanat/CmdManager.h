#pragma once

/* Klasa odpowiedzialna za odczytywanie i weryfikacje zadan nawigacyjnych uzytkownika*/

class CmdManager
{
public:
	CmdManager(); // konstruktor domyslny
	~CmdManager(); // destruktor
	static int listen(); // metoda statyczna sluzaca do nadsluchiwania zadan uzytkownika
						 // wywolywana jako CmdManager::listen()
};

