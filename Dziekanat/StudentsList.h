#pragma once
#include <vector>
#include <string>

#include "Student.h"

class StudentsList
{
private:
	std::vector <Student> students;
	int startIndex;
public:
	StudentsList();
	~StudentsList();
	
	int addStudent(Student *s);
	int removeStudent(int index);
	bool showAllStudents();
	bool showStudentbyIndex(int index);

	bool showStudentsByField(std::string field);
	bool showStudentsByType(std::string type);

	int getNumberOfStudents();
};

