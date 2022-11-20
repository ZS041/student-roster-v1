#pragma once
#include <iostream>
#include <string>
#include "Degree.h"

class Student
{
	static const int MAX_DAYS = 3;
public:
	//constructor including all variables used for Student
	Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[], DegreeProgram degreeProgram);
	~Student();

	//Getters - Step D2A (ACCESSORS)
	std::string GetStudentID();
	std::string GetFirstName();
	std::string GetLastName();
	std::string GetEmailAddress();
	int GetAge();
	int GetDaysToComplete();
	DegreeProgram GetDegreeProgram();

	//Setters - Step D2B (MUTATORS)
	void SetStudentID(std::string studentID);
	void SetFirstName(std::string firstName);
	void SetLastName(std::string lastName);
	void SetEmailAddress(std::string emailAddress);
	void SetAge(int age);
	void SetDaysToComplete(int daysToComplete[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	//print function for Student
	void print();

	//initialize variables for internal use
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	int age;
	int daysToComplete[MAX_DAYS];
	DegreeProgram degreeProgram;
};
