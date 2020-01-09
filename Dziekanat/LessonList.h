#pragma once
#include "ObjectList.h"
#include "Lesson.h"

#include "Student.h";

class LessonList : public ObjectList
{
public:
	LessonList() {}

	Lesson* getByName(std::string name);

	void removeStaffMemberFromLessons(StaffMember* staffMember);
	void removeStudentFromLessons(Student* student);

	bool showByName(std::string name);
	bool showSpecificType(std::string type);
};

