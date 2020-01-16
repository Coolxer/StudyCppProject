#include "ObjectList.h"

ObjectList::ObjectList()
{
	this->index = 0;
}

void ObjectList::setStartIndex(int startIndex)
{
	this->index = startIndex;
}

ObjectList::~ObjectList()
{
	for (int i = 0; i < (int)this->objects.size(); i++)
		delete this->objects[i];

	this->objects.clear();
}

int ObjectList::addObject(Object *object)
{
	this->objects.push_back(object);

	this->index++;
	this->objects.back()->setIndex(this->index);

	return this->index;
}

int ObjectList::removeObject(int index)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index)
		{
			this->objects.erase(this->objects.begin() + i);
			return index;
		}
	}

	return -1;
}

Object* ObjectList::getObjectByIndex(int index)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index)
			return this->objects[i];
	}

	return nullptr;
}

bool ObjectList::showAll()
{
	for (int i = 0; i < (int)this->objects.size(); i++)
		this->objects[i]->show();

	if (this->objects.size() != 0)
		return true;

	return false;
}

bool ObjectList::showByIndex(int index)
{
	for (int i = 0; i < (int)this->objects.size(); i++)
	{
		if (this->objects[i]->getIndex() == index)
		{
			this->objects[i]->show(true);
			return true;
		}
	}
	return false;
}

int ObjectList::getNumberOfObjects()
{
	return (int)this->objects.size();
}

