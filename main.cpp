#include <iostream>
#include "Node.h"

void add(Node * & head);
void print(Node * node);
void delete_node(Node * & head, int id);
double average(Node * node, double cumulative = 0, int count = 0);

int main() {
	Student * student = new Student("Hello", "ERear", 21424, 4.00);

	Node * head = new Node(student);

	Student * student2 = new Student("bruh", "moment", 10231, 3.00);

	Node * second = new Node(student2);

	head->setNext(second);

	print(head);
	delete_node(head, 10231);
	print(head);
	//std::cout << average(head) << std::endl;

	return 0;
}

void add(Node * & head) {

}

void print(Node * node) {
	if (node != NULL) {
		node->getStudent()->print();
		print(node->getNext());
	}
}

void delete_node(Node * & head, int id) {
	if (head == NULL) return;

	if (head->getStudent()->getID() == id) {
		Node * temp = head;
		head = head->getNext();
		free(temp);
		return;
	}
	else {
		delete_node((& head)->getNext(), id);
	}
}

double average(Node * node, double cumulative, int count) {
	return (node != NULL) ? average(node->getNext(), cumulative + node->getStudent()->getGPA(), count + 1) : (count > 0) ? cumulative / count : 0;
}

