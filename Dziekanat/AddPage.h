#pragma once
#include <string>
#include "Page.h"
#include "TextBox.h"

#include "ObjectList.h"

class AddPage : public Page
{
private:
	int currentStep;

protected:
	std::string strings[10];
	int numbers[10];
	ObjectList* objectList;

public:
	AddPage(Window* window);
	~AddPage();

	void init(ObjectList* objectList);

	int getCurrentStep();

	void setString(int id, std::string string);
	void setNumber(int id, int value);

	void resetValues();
	int increaseCurrentStep();

	void checkNumber(int number);
	void testString(std::string text, int id);
	void testNumber(std::string text, int id, int min, int max);

	void drawParagraph(std::string text);
	
	virtual void draw() = 0;
	virtual void service() = 0;
};

