#include "Lesson.h"

#include <iostream>
#include "windows.h"

Lesson::Lesson(std::string type, std::string name, int startTime, int duration, int maxPlaces)
{
	this->type = type;
	this->name = name;
	this->startTime = startTime;
	this->duration = duration;

	this->maxPlaces = maxPlaces;

	this->staffMember = nullptr; // przypisanie wartosci nullptr do wskaznika, aby wskazywal na wartosc pusta
	
	this->studentsCount = 0;
	this->students = nullptr;
}

Lesson::Lesson(const Lesson& model)
{
	this->type = model.type;
	this->name = model.name;
	this->startTime = model.startTime;
	this->duration = model.duration;
	this->maxPlaces = model.maxPlaces;
	
	this->staffMember = model.staffMember;

	this->studentsCount = model.studentsCount;
	this->students = model.students;
}

Lesson& Lesson::operator = (const Lesson& model)
{
	delete[] this->students;
	
	this->type = model.type;
	this->name = model.name;
	this->startTime = model.startTime;
	this->duration = model.duration;
	this->maxPlaces = model.maxPlaces;

	this->staffMember = model.staffMember;

	this->studentsCount = model.studentsCount;
	this->students = model.students;

	return *this;
}

bool Lesson::isEqual(Object* model)
{
	Lesson* lesson = (Lesson*)model;

	if (this->type == lesson->type && this->name == lesson->name && this->startTime == lesson->startTime && this->duration == lesson->duration
		&& this->maxPlaces == lesson->maxPlaces && this->staffMember == lesson->staffMember && this->studentsCount == lesson->studentsCount
		&& this->students == lesson->students)
		return true;

	return false;
}

Lesson::~Lesson()
{
	delete[] this->students;
}

std::string Lesson::getType() const
{
	return this->type;
}

std::string Lesson::getName() const
{
	return this->name;
}

int Lesson::getStartTime() const
{
	return this->startTime;
}

int Lesson::getDuration() const
{
	return this->duration;
}

int Lesson::getMaxPlaces() const
{
	return this->maxPlaces;
}

int Lesson::getNumberOfStudents() const
{
	return this->studentsCount;
}

StaffMember* Lesson::getStaffMember() const
{
	return this->staffMember;
}

int Lesson::consistsStudent(Student* student)
{
	for (int i = 0; i < this->studentsCount; i++)
	{
		if (this->students[i] == student) // sprawdzenie czy aktualny student w iteracji jest rowny podanemu poprzez wskaznik studentowi -> wykorzystanie przeciazenia operatora porownania
			return i;					   // jesli tak to zwraca numer tego studenta na liscie                     
	}

	return -1; // jesli studenta nie ma na liscie to zwraca -1
}

void Lesson::removeStudent(Student* student, int id)
{
	Student** tmp = new Student * [this->studentsCount - 1];
	std::copy(this->students, this->students + id, tmp);
	std::copy(this->students + id + 1, this->students + this->studentsCount, tmp + id);

	delete[] this->students;

	this->students = tmp;

	this->studentsCount--; // zmniejszenie liczby studentow zapisanych na zajecia
}

void Lesson::removeStaffMember()
{
	//delete this->staffMember;
	this->staffMember->decreaseLessons();
	this->staffMember = nullptr; // zwolnienie prowadzacego z zajec
}

bool Lesson::addStudent(Student* student)
{
	if (this->studentsCount < this->maxPlaces) // sprawdzenie czy sa jeszcze wolne miejsce
	{
		if (this->consistsStudent(student) != -1) // jesli student jest juz wpisany na liste to zwroc false
			return false;
	
		Student** tmp = new Student * [this->studentsCount + 1];

		std::copy(this->students, this->students + this->studentsCount, tmp);

		this->studentsCount++;

		delete[] this->students;

		this->students = tmp;

		this->students[this->studentsCount - 1] = student;

		return true;
	}

	return false; // jesli nie ma wolnych miejsc to zwraca false
}

bool Lesson::setStaffMember(StaffMember* staffMember)
{
	if (this->staffMember) // sprawdzenie czy zajecia nie maja juz przypisanego prowadzacego, jesli tak to zwraca false
		return false;

	this->staffMember = staffMember; // przypisanie pracownika do zajec

	return true;
}

void Lesson::showStudents()
{
	//Student::showHeader();

	for (int i = 0; i < this->studentsCount; i++)
		this->students[i]->show(); // wyswietlenie danych wszystkich studentow zapisanych na zajecia

	if (this->studentsCount == 0) // sprawdzenie czy do zajec sa przypisani jacys studenci, jesli nie to wyswietl komunikat
		std::cout << "Lista studentow dla tych zajec jest pusta" << std::endl;
}

void Lesson::showHeader()
{
	if (this->staffMember)
		std::cout << std::endl << " ID | " << "Typ | " << " Nazwa | " << "Godzina rozpoczecia | " << "Czas trwania | " << "zajete / max | " << "Prowadzacy | " << std::endl;
	else
		std::cout << std::endl << "ID | " << "Typ | " << "Nazwa | " << "Godzina rozpoczecia | " << "Czas trwania | " << "zajete / max |" << std::endl;
}

void Lesson::show(bool withHeader)
{
	if (withHeader) // parametr withHeader jest opcjonalny
		this->showHeader();

	std::cout << "-----------------------------------------------------------------------------------------" << std::endl;
	
	if (this->staffMember)
		std::cout << this->getIndex() << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << " | " << this->studentsCount << "/" << this->maxPlaces << " | " << this->staffMember->getAcademicDegree() << " " << this->staffMember->getFirstName() << " " << this->staffMember->getLastName() << std::endl;
	else
		std::cout << this->getIndex() << " | " << this->type << " | " << this->name << " | " << this->startTime << " | " << this->duration << " | " << this->studentsCount << "/" << this->maxPlaces << std::endl;
}
