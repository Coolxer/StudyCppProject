#pragma once
#include <string>

class Study
{
private:
	std::string field;
	int level;
	int year;
	std::string type;

public:
	Study() {}
	Study(std::string field, int level, int year, std::string type);

	std::string getField() const;
	int getLevel() const;
	int getYear() const;
	std::string getType() const;

	void setField(std::string field);
	void setLevel(int level);
	void setYear(int year);
	void setType(std::string type);	
};

