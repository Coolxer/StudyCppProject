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

	std::string firstName;
	std::string lastName;
	int age;

	std::string field;
	int level;
	int year;
	std::string type;

	int currentStep;

	Student* student;

	void resetValues();

public:
	AddStudentPage(Window* window, StudentsPage* studentsPage);
	~AddStudentPage();

	void draw();
	void service();
};

