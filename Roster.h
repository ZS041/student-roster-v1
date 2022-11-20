#pragma once
#include <string>
#include "Student.h"
#include "Degree.H"
class Roster
{
public:

	int studentCount;
	Student** classRosterArray;
	int rosterSize = 5;

	Roster(int rosterSize);
	~Roster();
	void parseadd();

	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void printAll();
	void remove(std::string studentID);
	void printAverageDaysInCourse(std::string studentID);

	void printInvalidEmails();

	void printByDegreeProgram(DegreeProgram degreeProgram);
};