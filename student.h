#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

class Student
{

protected:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int    age;
	int*   num_days; // array of daysremaining in course
	Degree degree;
	

public:
	const static int num_days_size = 3;
	//constructors
	Student();
	Student(string id, string fname, string lname, string eaddress, int a, int num_days[], Degree degree);

	//accessors
	
	string          getStudentID();
	string          getFirstName();
	string          getLastName();
	string          getEmailAddress();
	int             getAge();
	int*            getNumDays();
	virtual Degree  getDegree() = 0;

	//mutators
	void         setStudentID    (string id);
	void         setFirstName    (string fname);
	void         setLastName     (string lname);
	void         setEmailAddress (string eaddress);
	void         setAge          (int a);
	void         setNumDays      (int num_days[]);
	virtual void setDegree       (Degree d) = 0;
	virtual void print() = 0;
	
	//destructor
	~Student();


	
	
	

};




#endif