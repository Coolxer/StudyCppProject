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

	std::string firstName;
	std::string lastName;
	int age;

	std::string academic_degrees;

	int currentStep;

	StaffMember* staffMember;

	void resetValues();

public:
	AddStaffMemberPage(Window* window, StaffPage* staffPage);
	~AddStaffMemberPage();

	void draw();
	void service();
};

