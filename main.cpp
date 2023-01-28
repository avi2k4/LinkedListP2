/*
 * Sorted linked List add, print, insert, and average implementation in C++
 * Avighnash Kumar
 * January 27, 2023
 */

#include <iostream>
#include <cstring>
#include "Node.h"

void clearInput();
void add(Node * & head, Node * new_node);
void print(Node * head);
void delete_node(Node * & head, int id);
double average(Node * head, double cumulative = 0, int count = 0);

int main() {
	Node * head = NULL;

	std::cout << "\nWelcome to the student database!" << std::endl;
	std::cout << "Commands:" << std::endl;
	std::cout << "[ADD] To add a student" << std::endl;
	std::cout << "[DELETE] To delete a student by ID" << std::endl;
	std::cout << "[AVERAGE] To return the average of all students" << std::endl;
	std::cout << "[PRINT] To print out all students" << std::endl;
	std::cout << "[QUIT] To quit\n" << std::endl;

	while (true) {
		char input[50];
		std::cin >> input;
		clearInput();

		if (strcmp(input, "ADD") == 0) {
			std::cout << std::endl;
			std::cout << "Enter a first name:" << std::endl;

			char first_name[50];
			std::cin.get(first_name, sizeof(first_name));
			std::cin.get();

			std::cout << "Enter a last name:" << std::endl;

			char last_name[50];
			std::cin.get(last_name, sizeof(last_name));
			std::cin.get();

			std::cout << "Enter an ID number:" << std::endl;

			int id_num;
			std::cin >> id_num;
			clearInput();

			std::cout << "Enter a GPA:" << std::endl;

			double gpa;
			std::cin >> gpa;
			clearInput();

			Student * student = new Student(first_name, last_name, id_num, gpa);
			Node * node = new Node(student);

			add(head, node);
			std::cout << "\nAdded: " << first_name << " " << last_name << " to the database!" << std::endl;
		}
		else if (strcmp(input, "DELETE") == 0) {
			std::cout << "\nEnter the ID of the student you want to delete from the list:" << std::endl;
			int id_input;
			cin >> id_input;
			clearInput();

			delete_node(head, id_input);
			std::cout << "Delete student with ID: " << id_input << " from the database!" << std::endl; 
		}
		else if (strcmp(input, "AVERAGE") == 0) {
			std::cout << "\nAverage GPA of all students: " << average(head) << std::endl;
		}
		else if (strcmp(input, "PRINT") == 0) {
			if (head == NULL) {
				std::cout << "\nThere are no elements to print!\n" << std::endl;
			}
			else {
				print(head);
			}
		}
		else if (strcmp(input, "QUIT") == 0) {
			break;
		}
	}

	return 0;
}

void clearInput() {
	std::cin.ignore(25, '\n');
}

void add(Node * & head, Node * new_node) {
	if (head == NULL || head->getStudent()->getID() >= new_node->getStudent()->getID()) {
		new_node->setNext(head);
		head = new_node;
		return;
	}

	if (head->getNext() == NULL) {
		head->setNext(new_node);
		return;
	}

	// Find the node where its ID is less than the new nodes ID and the following nodes ID is greater than the current node, as that is where the new node will be fit in
	if (head->getStudent()->getID() < new_node->getStudent()->getID() && head->getNext()->getStudent()->getID() > new_node->getStudent()->getID()) {
		Node * temp = head->getNext();
		new_node->setNext(temp);
		head->setNext(new_node);
		return;
	}
	
	Node * temp = head->getNext();
	add(temp, new_node);
}

void print(Node * head) {
	// If the node isn't null, print out information
	if (head != NULL) {
		std::cout << std::endl;
		head->getStudent()->print();
		std::cout << "----------------" << std::endl;
		print(head->getNext());
	}
}

void delete_node(Node * & head, int id) {
	if (head == NULL) return;

	// Because ID is supposed to be unique, the first node with the ID is deleted and the function exits scope
	if (head->getStudent()->getID() == id) {
		Node * temp = head;
		head = head->getNext();
		free(temp);
		return;
	}

	Node * temp = head->getNext();
	delete_node(temp, id);
}

// If the head isn't null, call the function with the cumulative with the current nodes GPA and increment the count
// Accounts for case where head is NULL so count is zero, thus the average is zero
double average(Node * head, double cumulative, int count) {
	return (head != NULL) ? average(head->getNext(), cumulative + head->getStudent()->getGPA(), count + 1) : (count > 0) ? cumulative / count : 0;
}

