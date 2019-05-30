#include <iostream>
#include <iomanip>
#include "student.h"
#include "degree.h"
using namespace std;
//default constructor
Student::Student()
{
	this->studentID = "student_id";
	this->firstName = "first_name";
	this->lastName = "last_name";
	this->emailAddress = "email_address";
	this->age = 0;
	this->num_days = new int[num_days_size];
	for (int i = 0; i < num_days_size; ++i) this->num_days[i] = 0;
	
}
//constructor
Student::Student(string id, string fname, string lname, string eaddress, int a, int num_days[], Degree degree)
{
	this->studentID = id;
	this->firstName = fname;
	this->lastName = lname; 
	this->emailAddress = eaddress;
	this->age = a;
	this->num_days = new int[num_days_size];
	for (int i = 0; i < 3; ++i) this->num_days[i] = num_days[i];

}

//accessors
string Student::getStudentID()
{
	return studentID;
}
string Student::getFirstName()
{
	return firstName;
}
string Student::getLastName()
{
	return lastName;
}
string Student::getEmailAddress()
{
	return emailAddress;
}
int    Student::getAge()
{
	return age;
}
int* Student::getNumDays()
{
	return num_days;
}

//mutators
void   Student::setStudentID    (string id)
{
	this->studentID = id;
}
void   Student::setFirstName    (string fname)
{
	this->firstName = fname;
}
void   Student::setLastName     (string lname)
{
	this->lastName = lname;
}
void   Student::setEmailAddress (string eaddress)
{
	this->emailAddress = eaddress;
}
void   Student::setAge          (int a)
{
	this->age = a;
}
void   Student::setNumDays      (int num_days[])
{
	if (this->num_days != nullptr) {
		delete[] this->num_days;
		this->num_days = nullptr;
	}
	this->num_days = new int[num_days_size];
	for (int i = 0; i < 3; ++i) {
		this->num_days[i] = num_days[i];
	}
}

void   Student::print()
{
	int* courseday = getNumDays();

	cout << studentID << endl;
	cout << "First name: " << firstName << "\t";
	cout << "Last name: " << lastName << "\t";
	cout << "Age: " << age << "\t";
	cout << "daysInCourse: {" << *courseday << " " << *(courseday + 1) << " " << *(courseday + 2) << "}" << "\t";

	
}

//destructor
Student::~Student()
{
	if (num_days != nullptr) {
		delete[] num_days;
		num_days = nullptr;
	}
}
