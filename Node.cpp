
 #include <iostream>
 #include <cstring>
 #include "Student.h"
 #include "Node.h"
 using namespace std;

 Node::Node(Student* student1) {
   nextStu = student1;
 }

 Node* Node::getNext() {
    return next;
  }

 Student* Node::getStudent() {
    return nextStu;
 }

 void Node::setNext(Node* next1) {
   next = next1;
 }


 Node::~Node() {
   cout << "demolished!" << endl;
 }
   
  
