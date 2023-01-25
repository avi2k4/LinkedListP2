
 #include <iostream>
 #include <cstring>
 #include "Student.h"
 #pragma once

 using namespace std;

 class Node{
  public:
   Node(Student*); // Constructor
   Node* getNext(); // Returns the next node
   Student* getStudent(); // Returns the student
   void setNext(Node*); // Sets the next node
   ~Node(); // Destructor
   Student* nextStu;
   Node* next;

 };
 
