#include "ObjectList.h"

ObjectList::ObjectList()
{
	this->index = 0; // ustawienie indeksu potencjalnego pierwszego obiektu na 0
}

void ObjectList::setStartIndex(int startIndex)
{
	this->index = startIndex; // ustawienie indeksu potencjalnego pierwszego obiektu
}

ObjectList::~ObjectList()
{
	for (int i = 0; i < (int)this->objects.size(); i++)
		delete this->objects[i]; // usunieniecie obiektu

	this->objects.clear(); // wyczyszczenie tablicy dynamicznej
}

int ObjectList::addObject(Object *object)
{
	this->objects.push_back(object); // dodanie obiektu do listy

	this->index++; // zwiekszenie indeksu
	this->objects.back()->setIndex(this->index); // ustawienie indeksu nowo utworzonego obiektu

	return this->index; // zwrocenie aktualnego indeksu
}

int ObjectList::removeObject(int index)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
		{
			this->objects.erase(this->objects.begin() + i); // usuniecie obiektu o wskazanym indeksie
			return index;
		}
	}

	return -1; // jesli obiekt o podanym indeksie nie istnieje, zwroc -1
}

Object* ObjectList::getObjectByIndex(int index)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
			return this->objects[i]; // zwrocenie wskaznika na obiekt o podanym indeksie
	}

	return nullptr; // jesli obiekt o podanym indeksie nie istnieje, zwroc wskaznik pusty
}

void ObjectList::showAll()
{
	/* wyswietlenie obiektow z listy */
	for (int i = 0; i < (int)this->objects.size(); i++)
		this->objects[i]->show();

	if (this->objects.size() == 0) // jesli lista nie jest pusta to zwroc true
		std::cout << "Lista jest pusta" << std::endl;
}

void ObjectList::showByIndex(int index)
{
	bool exists = false;

	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
		{
			this->objects[i]->show(true); // wyswietlenie danych dot. obiektu
			exists = true;
		}
	}

	if (!exists) // jesli nie ma obiektu na liscie o podanym indeksie, to wyswietl komunikat
		std::cout << "Nie istnieje";
}

int ObjectList::getNumberOfObjects()
{
	return (int)this->objects.size();
}

