#pragma once
#include <string>

class Study
{
private:
	std::string field;
	std::string year;
	std::string type;

public:
	Study() {}
	Study(std::string field, std::string year, std::string type);

	std::string getField() const;
	std::string getYear() const;
	std::string getType() const;

	void setField(std::string field);
	void setYear(std::string year);
	void setType(std::string type);	
};

