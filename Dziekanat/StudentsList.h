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
	
	int addStudent(Student &s);
	void removeStudent();
	void showAllStudents();
	void showStudentbyIndex(int index);

	int getNumberOfStudents();
};

