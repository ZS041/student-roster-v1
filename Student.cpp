#include "Student.h"

//constructors
Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram)
{
	SetStudentID(studentID);
	SetFirstName(firstName);
	SetLastName(lastName);
	SetEmailAddress(emailAddress);
	SetAge(age);
	SetDegreeProgram(degreeProgram);
	SetDaysToComplete(daysToComplete);
}
Student::~Student()
{
}

//Getters - Step D2A (ACCESSORS)

std::string Student::GetStudentID() {
	return studentID;
}
std::string Student::GetFirstName() {
	return firstName;
}
std::string Student::GetLastName() {
	return lastName;
}
std::string Student::GetEmailAddress() {
	return emailAddress;
}
int Student::GetAge() {
	return age;
}
int Student::GetDaysToComplete() {
	return *daysToComplete;
}
DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

//Setters - Step D2B (MUTATORS)

void Student::SetStudentID(std::string studentID)
{
	this->studentID = studentID;
}
void Student::SetFirstName(std::string firstName)
{
	this->firstName = firstName;
}
void Student::SetLastName(std::string lastName)
{
	this->lastName = lastName;
}
void Student::SetEmailAddress(std::string emailAddress)
{
	this->emailAddress = emailAddress;
}
void Student::SetAge(int age)
{
	this->age = age;
}
void Student::SetDaysToComplete(int daysToComplete[])
{
	for (int t = 0; t < MAX_DAYS; t++) {
		this->daysToComplete[t] = daysToComplete[t];
	}
}

void Student::SetDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

void Student::print()
{
	std::cout << "Student ID: " << GetStudentID() << '\t'
		<< "First Name: " << GetFirstName() << '\t'
		<< "Last Name: " << GetLastName() << '\t'
		<< "Email Address: " << GetEmailAddress() << '\t'
		<< "Age: " << GetAge() << '\t'
		<< "Days in Course: " << "{";
	for (int j = 0; j < MAX_DAYS; j++) {
		std::cout << daysToComplete[j];
		if (j != MAX_DAYS - 1) {
			std::cout << ", ";
		}
	}
	std::cout << "}" << '\t'
		<< "Degree Program: ";

	if (degreeProgram == SECURITY) {
		std::cout << "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		std::cout << "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		std::cout << "SOFTWARE";
	}
	else {
		std::cout << "INVALID DEGREE TYPE";
	}
	std::cout << "\n";
	return;
}