#pragma once
#include <vector>
#include "Student.h"

class StudentsList
{
private:
	std::vector <Student> students;
	int startIndex;
public:
	StudentsList();
	
	int addStudent(Student *s);
	int removeStudent(int index);
	bool showAllStudents();
	bool showStudentbyIndex(int index);

	int getNumberOfStudents();
};

