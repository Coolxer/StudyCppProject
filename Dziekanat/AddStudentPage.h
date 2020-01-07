#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "StudentsPage.h"

class AddStudentPage : public Page
{
private:
	TextBox header;
	TextBox info;

	StudentsList* studentsList;
	Student* student;

	std::string firstName;
	std::string lastName;
	int age;
	std::string field;
	int level;
	int year;
	std::string type;

	int currentStep;

	void resetValues();

	void testString(std::string text, std::string* pointer);
	void testNumber(std::string text, int* pointer, int min, int max);
public:
	AddStudentPage(Window* window, StudentsPage* studentsPage);
	~AddStudentPage();

	void draw();
	void service();
};

