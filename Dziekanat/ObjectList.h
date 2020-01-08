#pragma once
#include <vector>
#include <string>

#include "Lesson.h"
#include "Student.h"
#include "StaffMember.h"

class ObjectList
{
private:
	int index;
	std::vector <Object> lessons;
public:
	LessonsList();
	~LessonsList();

	int addObject(Lesson* s);
	int removeLesson(int index);
	Lesson* getLessonByName(std::string name);

	void removeStaffMember(StaffMember* staffMember);
	void removeStudent(Student* student);

	bool showLessons();
	bool showLessonById(int index);
	bool showLessonByName(std::string name);
	bool showSpecificLessons(std::string type);

	int getNumberOfObjects();
};

