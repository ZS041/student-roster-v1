#include <iostream>
#include "student.h"
#include <string>
#include "roster.h"

int main() {
	std::cout
		<< "C867 - Scripting and Programming Applications"
		<< std::endl
		<< "C++"
		<< std::endl
		<< "#001368298"
		<< std::endl
		<< "Zakary Smith"
		<< std::endl << std::endl;

	Roster* classRoster = new Roster(5);
	classRoster->parseadd();
	classRoster->printAll();

	classRoster->printInvalidEmails();

	for (int i = 0; i < classRoster->studentCount; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->classRosterArray[i]->GetStudentID());
	}
	std::cout << std::endl;

	classRoster->printByDegreeProgram(SECURITY);

	classRoster->remove("A3");

	classRoster->printAll();

	classRoster->remove("A3");
	return 0;
	
}