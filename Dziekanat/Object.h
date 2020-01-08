#pragma once
#include <string>

class Object
{
private:
	int index;

public:
	Object() {}

	int getIndex() const;
	void setIndex(int index);
};

