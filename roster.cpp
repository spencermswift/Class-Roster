#include <iostream>
#include <string>
#include "student.h"
#include "softwareStudent.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "roster.h"
#include "degree.h"



using namespace std;




Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student*[capacity];
}

void Roster::add(string row)
{
	if (lastIndex < capacity) {
		lastIndex++;
		int numDaysArray[Student::num_days_size];
		
		
		if (row.substr(row.length()-8, 8) == "SOFTWARE") {
			this->classRosterArray[lastIndex] = new SoftwareStudent();
			classRosterArray[lastIndex]->setDegree(SOFTWARE);
		}
		
		else if (row.substr(row.length() - 7, 7) == "NETWORK") {
			this->classRosterArray[lastIndex] = new NetworkStudent();
			classRosterArray[lastIndex]->setDegree(NETWORK);
		}

		else if (row.substr(row.length() - 8, 8) == "SECURITY") {
			this->classRosterArray[lastIndex] = new SecurityStudent();
			classRosterArray[lastIndex]->setDegree(SECURITY);
		}
	
		//set id
		int rhs = studentData[lastIndex].find(",");
		classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

		//set fname
		int lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set lname
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set email
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

		//set age
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		classRosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

		//set days to complete courses
		//num_days[0]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numDaysArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//num_days[1]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numDaysArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		//num_days[2]
		lhs = rhs + 1;
		rhs = studentData[lastIndex].find(",", lhs);
		numDaysArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

		classRosterArray[lastIndex]->setNumDays(numDaysArray);
	}
}



void Roster::remove(string id)
{
	
	for (int i = 0; i <= lastIndex; ++i) {
		if (classRosterArray[i] == nullptr) {
			cout << "ERROR: Student with ID: " << id << " not found" << endl;
			break;
		}
		else if (id == classRosterArray[i]->getStudentID()) {
			classRosterArray[i] = nullptr;
			cout << "Student removed" << endl;
		}
	}

}

void Roster::printAll()
{
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printAverageDays(string id)
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getStudentID() == id) {
			found = true;
			int* days = classRosterArray[i]->getNumDays();
			cout << "Average number of days per course for student id: " << id << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; ++i) {
		string email = classRosterArray[i]->getEmailAddress();
		if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)) {
			cout << "The email for student: " << classRosterArray[i]->getFirstName() << " " << classRosterArray[i]->getLastName() << " is not valid: " << email << endl;
		}
	}
}

void Roster::printDegree(Degree d)
{
	cout << "Student Roster by Degree: " << degreeTypeString[d] << "\n";
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegree() == d) this->classRosterArray[i]->print();
	}
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++)
	{
		delete this->classRosterArray[i];
	}
	delete this;
}
	

int main()
{

	cout << "******************** COURSE TITLE ********************" << endl << endl;
	cout << "     SCRIPTING AND PROGRAMMING APPLICATIONS - C867" << endl << endl;
	cout << "**************** PROGRAMMING LANGUAGE****************" << endl << endl;
	cout << "                         C++ " << endl << endl;
	cout << "**************** STUDENT ID AND NAME *****************" << endl << endl;
	cout << "              #000957156 - SPENCER SWIFT" << endl << endl;

	Roster* classRoster = new Roster(numStudents);
	for (int i = 0; i < numStudents; ++i) {
		classRoster->add(studentData[i]);
	}

	
	cout << "Roster" << endl;
	classRoster->printAll();
	cout << endl;

	cout << "Invalid Emails" << endl;
	classRoster->printInvalidEmails();
	cout << endl;
	
	cout << "Average days per class for each student" << endl;
	for (int i = 0; i < numStudents; ++i) {
		classRoster->printAverageDays(classRoster->classRosterArray[i]->getStudentID());
	}
	cout << endl;

	
	classRoster->printDegree(SOFTWARE);
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	classRoster->remove("A3");
	cout << endl;
	
	
	
	system("pause");
	return 0;
}


