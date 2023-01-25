#pragma once

#include <iostream>
#include <cstring>

class Student {
	public:
		Student(char * firstName, char * lastName, int id, double gpa);
		~Student();

		char * getFirstName();
		char * getLastName();
		int getID();
		double getGPA();
		void print();

	private:
		char firstName[50];
		char lastName[50];
		int id;
		double gpa;
};
