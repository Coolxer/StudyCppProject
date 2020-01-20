
#include "Object.h"

Object::Object()
{

}

Object::~Object()
{

}

int Object::getIndex() const
{
	return this->index;
}

void Object::setIndex(int index)
{
	this->index = index;
}
