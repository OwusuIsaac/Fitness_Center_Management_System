#ifndef CLASSES_H
#define CLASSES_H

#include <string>
#include <iostream>
#include <fstream>
#include "linkedlist.h"

using namespace std;

class FitnessClass {
private:


public:
	string Class_Name, Class_date, Class_time, ClassID, Maximum_capacity, Room_number;
	int curr_capacity;
	DoublyLinkedList<string> List_of_members;
	FitnessClass();
	FitnessClass(string id, string name, string date, string time, string room);
};

FitnessClass::FitnessClass() {
	this->Maximum_capacity = "10";
	this->curr_capacity = 0;
}

FitnessClass::FitnessClass(string id, string name, string date, string time, string room) {
	this->ClassID = id;
	this->Class_Name = name;
	this->Class_time = time;
	this->Room_number = room;
	this->Class_date = date;
	this->Maximum_capacity = "10";
	this->curr_capacity = 0;
}

class Member {
private:

public:
	string firstname, lastname, username, password, id;
	Member();
	Member(string fname, string lname);
};

Member::Member() {}

Member::Member(string fname, string lname) {
	this->firstname = fname;
	this->lastname = lname;

	srand(time(NULL));
	this->id = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
	this->username = firstname + string(id);
	this->password = lastname + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
}

class Admin {
private:


public:
	string firstname, lastname, username, password, id;
	Admin();
	~Admin() {}
	Admin(string fname, string lname);
	
};

Admin::Admin() {}

Admin::Admin(string fname, string lname) {
	this->firstname = fname;
	this->lastname = lname;

	srand(time(NULL));
	this->id = to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
	this->username = firstname + string(id);
	this->password = lastname + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10) + to_string(rand() % 10);
}


#endif