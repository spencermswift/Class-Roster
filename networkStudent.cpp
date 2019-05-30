#include <iostream>
#include "networkStudent.h"
using namespace std;

NetworkStudent::NetworkStudent() {
	setDegree(NETWORK);
}

NetworkStudent::NetworkStudent(string id, string fname, string lname, string eaddress, int a, int* num_days, Degree degree)
{
	setDegree(NETWORK);
}

Degree NetworkStudent::getDegree()
{
	return NETWORK;
}


void NetworkStudent::setDegree(Degree d)
{
	this->degree = NETWORK;
}



void NetworkStudent::print()
{
	this->Student::print();
	cout << "NETWORK" << "\n";
}

NetworkStudent::~NetworkStudent()
{
	Student::~Student();
	delete this;
}