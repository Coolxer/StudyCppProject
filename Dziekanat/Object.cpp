
#include "Object.h"

Object::Object()
{

}

Object::Object(const Object& model)
{
	this->index = model.index;
}

Object& Object::operator = (const Object& model)
{
	this->index = model.index;

	return *this;
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
