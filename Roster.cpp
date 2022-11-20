#include "Roster.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

//Student Data table including my data
const std::string studentData[] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Zakary,Smith,zsmit75@wgu.edu,24,30,50,38,SOFTWARE"
};

Roster::Roster(int studentCount)
//Pointer Array
{
	this->studentCount = rosterSize;
	classRosterArray = new Student * [studentCount];
}

Roster::~Roster() {
	delete[] classRosterArray;
}
void Roster::parseadd()
{
	for (int i = 0; i < rosterSize; i++)
	{
		std::string data_hold = studentData[i];
		std::vector<std::string> data_result;
		std::stringstream s_stream(data_hold);
		while (s_stream.good())
		{
			std::string substr;
			getline(s_stream, substr, ',');
			data_result.push_back(substr);
		}

		int daysToComplete[3] = { std::stoi(data_result[5]), std::stoi(data_result[6]), std::stoi(data_result[7]) };
		int age = std::stoi(data_result[4]);
		
		DegreeProgram degreeProgram = INVALID; //not sure if this can cause problems in the future
		if (data_result[8].compare("SECURITY") == 0) {
			degreeProgram = SECURITY;
		}
		else if (data_result[8].compare("SOFTWARE") == 0) {
			degreeProgram = SOFTWARE;
		}
		else if (data_result[8].compare("NETWORK") == 0) {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = INVALID;
		}
		classRosterArray[i] = new Student(data_result[0], data_result[1], data_result[2], data_result[3], age, daysToComplete, degreeProgram);
	}
}

void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	int daysToComplete[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[studentCount] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
	studentCount++;
}

void Roster::printAll() {
	for (int i = 0; i < studentCount; ++i) {
		classRosterArray[i]->print();
		std::cout << "\t";
	}
}
void Roster::remove(std::string studentID)
{
	bool studentFound = false;
	if (studentFound != true) {
		for (int i = 0; i <= studentCount; i++) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				classRosterArray[i] = classRosterArray[studentCount - 1];
				--studentCount;
				studentFound = true;
			}
		}
		if (studentFound) {
			std::cout << "Student " << studentID << " found and deleted." << std::endl << std::endl;
		}
		else {
			std::cout << "Student " << studentID << " not found." << std::endl << std::endl;
		}
	}
}

void Roster::printAverageDaysInCourse(std::string studentID)
{
	bool studentFound = false;
	if (studentFound != true) {
		for (int i = 0; i <= studentCount; i++) {
			if (classRosterArray[i]->GetStudentID() == studentID) {
				studentFound = true;
				int* days = classRosterArray[i]->daysToComplete;
				std::cout << "Average number of days in course for student " << classRosterArray[i]->GetStudentID() << " is " << (days[0] + days[1] + days[2]) / 3 << "." << std::endl << std::endl;
				return;
			}
		}
	}
}

void Roster::printInvalidEmails()
{
	bool invalidfound = false;
	std::cout << "List of Invalid E-Mails:" << std::endl << std::endl;
	for (int i = 0; i < studentCount; ++i)
	{
		std::string tempMail = this->classRosterArray[i]->GetEmailAddress();
		if ((tempMail.find('.') == std::string::npos) || (tempMail.find('@') == std::string::npos) || !(tempMail.find(' ') == std::string::npos))
		{
			invalidfound = true;
			std::cout << classRosterArray[i]->GetEmailAddress();
		}
		if (!invalidfound) 
		{
			std::cout << "No e-mails were found to be invalid." << std::endl;
		}
		std::cout << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	std::cout << "Students by Degree Program:" << std::endl;
	for (int i = 0; i < studentCount; ++i) {
		if (classRosterArray[i]->GetDegreeProgram() == degreeProgram)
			classRosterArray[i]->print();
	}
	std::cout << std::endl;



}