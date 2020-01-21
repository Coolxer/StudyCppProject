#include "ObjectList.h"

ObjectList::ObjectList()
{
	this->index = 0; // ustawienie indeksu potencjalnego pierwszego obiektu na 0
	
	this->size = 0;
	this->objects = nullptr;
}

ObjectList::ObjectList(const ObjectList& model)
{
	this->index = model.index;
	this->size = model.size;

	this->objects = model.objects;
}

ObjectList& ObjectList::operator = (const ObjectList& model)
{
	delete[] this->objects;

	this->index = model.index;
	this->size = model.size;

	this->objects = model.objects;

	return *this;
}

ObjectList::~ObjectList()
{
	delete[] this->objects;
}

void ObjectList::setStartIndex(int startIndex)
{
	this->index = startIndex; // ustawienie indeksu potencjalnego pierwszego obiektu
}

int ObjectList::addObject(Object *object)
{
	if (this->objectExists(object) != -1) // jesli obiekt jest juz wpisany na liste to zwroc -1
		return -1;

	Object** tmp = new Object * [this->size + 1];

	std::copy(this->objects, this->objects + this->size, tmp);

	this->size++;

	delete[] this->objects;

	this->objects = tmp;

	this->objects[this->size - 1] = object;
	
	this->objects[this->size - 1]->setIndex(++this->index);

	return this->index; // zwrocenie aktualnego indeksu
}

int ObjectList::removeObject(int index)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
		{
			Object** tmp = new Object * [this->size - 1];
			std::copy(this->objects, this->objects + i, tmp);
			std::copy(this->objects + i + 1, this->objects + this->size, tmp + i);

			delete[] this->objects;

			this->objects = tmp;

			this->size--;
			return index;
		}
	}

	return -1; // jesli obiekt o podanym indeksie nie istnieje, zwroc -1
}

int ObjectList::objectExists(Object* object)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->objects[i] == object) // sprawdzenie czy aktualny obiekt w iteracji jest rowny podanemu poprzez wskaznik obiektowi -> wykorzystanie przeciazenia operatora porownania
			return i;					// jesli tak to zwraca numer tego obiektu na liscie                     
	}

	return -1; // jesli obiektu nie ma na liscie to zwraca -1
}

Object* ObjectList::getObjectByIndex(int index)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
			return this->objects[i]; // zwrocenie wskaznika na obiekt o podanym indeksie
	}

	return nullptr; // jesli obiekt o podanym indeksie nie istnieje, zwroc wskaznik pusty
}

Object* ObjectList::getObjectByRealIndex(int index)
{
	if (this->objects[index])
		return this->objects[index];

	return nullptr;
}

void ObjectList::showAll()
{
	/* wyswietlenie obiektow z listy */
	for (int i = 0; i < this->size; i++)
		this->objects[i]->show();

	if (this->size == 0) // jesli lista nie jest pusta to zwroc true
		std::cout << "Lista jest pusta" << std::endl;
}

void ObjectList::showByIndex(int index)
{
	bool exists = false;

	for (int i = 0; i < this->size; i++)
	{
		if (this->objects[i]->getIndex() == index) // sprawdzenie czy aktualny obiekt w iteracji ma index rowny podanemu jako argument
		{
			this->objects[i]->show(true); // wyswietlenie danych dot. obiektu
			exists = true;
			break;
		}
	}

	if (!exists) // jesli nie ma obiektu na liscie o podanym indeksie, to wyswietl komunikat
		std::cout << "Nie istnieje";
}

int ObjectList::getNumberOfObjects()
{
	return this->size;
}

