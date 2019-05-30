#include <iostream>
#include "softwareStudent.h"
using namespace std;

SoftwareStudent::SoftwareStudent() {
	setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string id, string fname, string lname, string eaddress, int a, int* num_days, Degree degree)
{
	setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree()
{
	return SOFTWARE;
}


void SoftwareStudent::setDegree(Degree d)
{
	this->degree = SOFTWARE;
}



void SoftwareStudent::print()
{
	this->Student::print();
	cout << "SOFTWARE" << "\n";
}

SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
	delete this;
}