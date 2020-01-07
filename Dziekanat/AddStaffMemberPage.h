#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "StaffPage.h"

class AddStaffMemberPage : public Page
{
private:
	TextBox header;
	TextBox info;

	StaffList* staffList;
	StaffMember* staffMember;

	std::string firstName;
	std::string lastName;
	int age;
	std::string academic_degrees;

	int currentStep;

	void resetValues();
	void testString(std::string text, std::string* pointer);
	void testNumber(std::string text, int* pointer, int min, int max);
public:
	AddStaffMemberPage(Window* window, StaffPage* staffPage);
	~AddStaffMemberPage();

	void draw();
	void service();
};

