#include <iostream>
#include <cmath>
#include <cstring>
#include "Student.h"

Student::Student(char * firstName, char * lastName, int id, double gpa) {
	std::strcpy(this->firstName, firstName);
	std::strcpy(this->lastName, lastName);
	this->id = id;
	this->gpa = gpa;
}

Student::~Student() { }

/*
 * First name getter
 */
char * Student::getFirstName() {
	return this->firstName;
}

/*
 * Last name getter
 */
char * Student::getLastName() {
	return this->lastName;
}

/*
 * ID getter
 */
int Student::getID() {
	return this->id;
}

/*
 * GPA getter
 */
double Student::getGPA() {
	return this->gpa;
}

/*
 * Prints student's name, ID, and GPA (to the 2nd decimal point)
 */
void Student::print() {
	std::cout << "Name: " << this->firstName << " " << this->lastName << std::endl;
	std::cout << "ID: " << this->id << std::endl;
	std::cout << "GPA: " << std::ceil(this->gpa * 100.0) / 100.0 << std::endl;
}
