#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "stack.h"
#include "linkedlist.h"
#include "classes.h"
#include "functions.h"

using namespace std;


int main() {
	// Readin data from the text file Members.txt into the member lists
	ifstream read_members;
	read_members.open("Members.txt");
   // Condition for when file fails to open
	if (read_members.fail()) {
		cerr << "Error file does not exist" << endl;
		exit(-1);
	}
	while (!read_members.eof()) {
		//int counter = 0;
		Member X;
		string line;
		// getting data on a line in th etext file
		while (getline(read_members, line)) {
			// Reading the data into their attributes
			stringstream ss(line);
			getline(ss, X.id, ',');
			getline(ss, X.firstname, ',');
			getline(ss, X.lastname, ',');
			getline(ss, X.username, ',');
			getline(ss, X.password, ',');
			// Adding member to the member list
			Members_list.push(X);
			break;
		}
	}
	// closing text file
	read_members.close();
	// Readin data from the text file Admins.txt into the Admins lists
	ifstream read_admins;
	read_admins.open("Admins.txt");
	// Condition for when file fails to open
	if (read_members.fail()) {
		cerr << "Error file does not exist" << endl;
		exit(-1);
	}
	while (!read_admins.eof()) {
		Admin X;
		string line;
		while (getline(read_admins, line)) {
			// getting data on a line in the text file
			stringstream ss(line);
			getline(ss, X.id, ',');
			getline(ss, X.firstname, ',');
			getline(ss, X.lastname, ',');
			getline(ss, X.username, ',');
			getline(ss, X.password, ',');
			// Adding member to the Admin list
			Admins_list.push(X);
			break;
		}
	}
	// closing text file
	read_admins.close();
	// Readin data from the text file FitnessClasses.txt into the FitnessClass_lists
	ifstream read_FitnessClass;
	read_FitnessClass.open("FitnessClasses.txt");
	// Condition for when file fails to open
	if (read_FitnessClass.fail()) {
		cerr << "Error file does not exist" << endl;
		exit(-1);
	}
	while (!read_FitnessClass.eof()) {
		// creating new fitness class 
		FitnessClass X;
		string line;
		string y, z;
		while (getline(read_FitnessClass, line)) {
			// getting data on a line in the text file
			stringstream ss(line);
			getline(ss, X.ClassID, ',');
			getline(ss, X.Class_Name, ',');
			getline(ss, X.Class_date, ',');
			getline(ss, X.Class_time, ',');
			getline(ss, X.Maximum_capacity, ',');
			getline(ss, X.Room_number, ',');
			getline(ss, y);
			for (int i = 1; i < y.size() - 1; ++i)
			{
				while (i < y.length() - 1 && y[i] != ',') {
					z += y[i];
					++i;
				}
				X.List_of_members.add(z);
				z = "";
			}
			// Adding fitness class to the FitnessClass_list
			FitnessClass_list.add(X);
			break;
		}
	}
	// Closing text file
	read_FitnessClass.close();

	while (true) {
		cout << "WELCOME TO THE FITNESS MANAGEMENT SYSTEM" << endl;
		cout << "Please Enter the category of your account before logging in [admin/member]" << endl;
		string identification;
		cin >> identification;
		bool loggedIn = false;
   // Condition For when a user enters a wrong option
		while (identification !="admin" && identification != "member")
		{
				cout << "Error:Please Enter the category of your account before logging in [admin/member]" << endl;
				cin >> identification;
		}

		if (identification == "admin")
		{ // Asking for User Credentials 
			string Username, password;
			cout << "Please Enter your Username" << endl;
			cin >> Username;
			cout << "Please Enter your password" << endl;
			cin >> password;
			string userid;
			// Condition For when a user enters a worng input
			while (!loggedIn)
			{
				if (login(Username, password, 0,userid)) {
					
					loggedIn = true;
				}
				else {
					cout << "Wrong login credentials: Re-enter logins" << endl;
					cout << "Please Enter your Username" << endl;
					cin >> Username;
					cout << "Please Enter your password" << endl;
					cin >> password;
				}
			}
			cout << "You are Logged in!" << endl << endl;
			// Opening Admin interface and options availble to him
			while (loggedIn) {
				cout << endl << endl;
				string option;
				// Displaying admin options 
				AdminOptions();
				cin >> option;
				cout << endl << endl;
				// Condition for logging out 
				if (option == "10")
				{
					loggedIn = false;
					cout << "Logged out successfully" << endl;
					cout << endl
						<< endl;
					
				}
				// Condition for quitting program
				else if (option == "11") {
					cout << "Goodbye!!! Program Ended " << endl << endl;
               // Reading the list of members before the programs end into the text file "Members.txt" 
					ofstream readinto;
					readinto.open("Members.txt");
					// condition for when the file does not exist
					if (readinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}
					Node<Member>* a = Members_list.getHead();
					Node<Member>* v = a->getNext();
					// Looping through the members list 
					while (v->getNext() != NULL) {
						Member* cls = v->getElem();
						// reading data from the members list into the text file
						readinto << cls->id + ',' << cls->firstname + ',' << cls->lastname + ',' << cls->username + ',' << cls->password << endl;
						v = v->getNext();
					}
					readinto.close();
					// Reading the list of admins before the programs end into the text file "Admins.txt" 
					ofstream redinto;
					redinto.open("Admins.txt");
					// condition for when the file does not exist
					if (redinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}
					Node<Admin>* b = Admins_list.getHead();
					Node<Admin>* m = b->getNext();
					// Looping through the admins list 
					while (m->getNext() != NULL) {
						Admin* cls = m->getElem();
						// reading data from the admins list into the text file
						redinto << cls->id + ',' << cls->firstname + ',' << cls->lastname + ',' << cls->username + ',' << cls->password << endl;

						m = m->getNext();
					}
					redinto.close();
					// Reading the list of fitness class with it's details before the programs end into the text file "FitnessClasses.txt" 
					ofstream rdinto;
					rdinto.open("FitnessClasses.txt");
					// condition for when the file does not exist
					if (rdinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}
					
					Node<FitnessClass>* c = FitnessClass_list.getHead();
					Node<FitnessClass>* q = c->getNext();
					// Looping through the FitnessClass_list 
					while (q->getNext() != NULL) {
						FitnessClass* cls = q->getElem();
						Node<string>* s = cls->List_of_members.getHead();
						Node <string>* w = s->getNext();
						// Reading FitnessClass details into the text file
						rdinto << cls->ClassID + ',' << cls->Class_Name + ',' << cls->Class_date + ',' << cls->Class_time + ',' << cls->Maximum_capacity + ',' << cls->Room_number + ',' + '[';
						string d,h;
						// Looping through the list of members in a class 
						while (w->getNext() != nullptr) {
							string* hold = w->getElem();
							//rdinto << *hold + ',';
							d += *hold + ',';
							w = w->getNext();
						}
						for (int i = 0;i < d.length()-1;++i) {
							h += d[i];
						}
						// reading the list of members in a class into the text file
						rdinto << h;
						rdinto << ']' << endl;
						q = q->getNext();
					}
						rdinto.close();
					exit(0);
				}
				// Condition for adding a fitness class
				else if (option == "3") {
					FitnessClass X = addFitnessClass();
					FitnessClass_list.add(X);
					cout <<"New Fitness Class added successfully" << endl;
				}
				// Condition for registering an admin
				else if (option == "1") {
					Admin X = registerAdmin();
					Admins_list.push(X);
					cout <<"New Admin added successfully" << endl;
				}
				// Condition for registering an member
				else if (option == "2") {
					Member X = registerMember();
					Members_list.push(X);
					cout <<"New Member added successfully" << endl;
				}
				// Condition for viewing member list
				else if (option == "7") {
					viewMemberList();
					cout << endl;
				}
				// Condition for deleting a fitness class
				else if (option == "4") {
					deleteFitnessClass();
				}
				// Condition for deleting a fitness class
				else if (option == "5") {
					updateFitnessClass();
					cout << "Fitness Class updated successfully" << endl;
				}
				// Conditon for changing the capacity of class
				else if (option == "8") {
					changeClassCapacity();
					cout << "Capacity of class changed successfully" << endl;
				}
				// Condition for displaying classes with vacancies
				else if (option == "6") {
					displayClassWithVacancies();
				}
				// Condition for spliting a class
				else if (option == "9") {
					Splitfitnessclass();
					cout << "Class splitted successfully" << endl;
				}
			}
		}
		else if (identification == "member") {
		// Asking for User Credentials 
			string Uname, pword;
			cout << "Please Enter your Username" << endl;
			cin >> Uname;
			cout << "Please Enter your password" << endl;
			cin >> pword;
			string userid;
			// Condition For when a user enters a worng input
			while (!loggedIn)
			{
				if (login(Uname, pword, 1, userid)) {
					loggedIn = true;
				}
				else {
					cout << "Wrong login credentials: Re-enter logins" << endl;
					cout << "Please Enter your Username" << endl;
					cin >> Uname;
					cout << "Please Enter your password" << endl;
					cin >> pword;
				}
			}
			cout << "You are Logged in !" << endl << endl;
			// Opening Member interface and options availble to him
			while (loggedIn) {
				cout << endl << endl;
				string opt;
				MemberOptions();
				cin >> opt;
				cout << endl << endl;
				// condition for logging out
				if (opt == "5")
				{
					loggedIn = false;
					cout << "Logged out successfully" << endl;
					cout << endl
						<< endl;
				}
				else if (opt == "6") {
					cout << "Goodbye!!! Program Ended " << endl << endl;
					// Reading the list of members before the programs end into the text file "Members.txt" 
					ofstream readinto;
					readinto.open("Members.txt");
					// condition for when the file does not exist
					if (readinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}
					Node<Member>* a = Members_list.getHead();
					Node<Member>* v = a->getNext();
					// Looping through the members list 
					while (v->getNext() != NULL) {
						Member* cls = v->getElem();
						// reading data from the members list into the text file
						readinto << cls->id + ',' << cls->firstname + ',' << cls->lastname + ',' << cls->username + ',' << cls->password << endl;
						v = v->getNext();
					}
					readinto.close();
					// Reading the list of admins before the programs end into the text file "Admins.txt" 
					ofstream redinto;
					redinto.open("Admins.txt");
					// condition for when the file does not exist
					if (redinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}
					Node<Admin>* b = Admins_list.getHead();
					Node<Admin>* m = b->getNext();
					// Looping through the admins list 
					while (m->getNext() != NULL) {
						Admin* cls = m->getElem();
						// reading data from the admins list into the text file
						redinto << cls->id + ',' << cls->firstname + ',' << cls->lastname + ',' << cls->username + ',' << cls->password << endl;

						m = m->getNext();
					}
					redinto.close();
					// Reading the list of fitness class with it's details before the programs end into the text file "FitnessClasses.txt" 
					ofstream rdinto;
					rdinto.open("FitnessClasses.txt");
					// condition for when the file does not exist
					if (rdinto.fail()) {
						cerr << "Error: File does not exist" << endl;
						exit(-1);
					}

					Node<FitnessClass>* c = FitnessClass_list.getHead();
					Node<FitnessClass>* q = c->getNext();
					// Looping through the FitnessClass_list 
					while (q->getNext() != NULL) {
						FitnessClass* cls = q->getElem();
						Node<string>* s = cls->List_of_members.getHead();
						Node <string>* w = s->getNext();
						// Reading FitnessClass details into the text file
						rdinto << cls->ClassID + ',' << cls->Class_Name + ',' << cls->Class_date + ',' << cls->Class_time + ',' << cls->Maximum_capacity + ',' << cls->Room_number + ',' + '[';
						string d, h;
						// Looping through the list of members in a class 
						while (w->getNext() != nullptr) {
							string* hold = w->getElem();
							//rdinto << *hold + ',';
							d += *hold + ',';
							w = w->getNext();
						}
						for (int i = 0;i < d.length() - 1;++i) {
							h += d[i];
						}
						// reading the list of members in a class into the text file
						rdinto << h;
						rdinto << ']' << endl;
						q = q->getNext();
					}
					rdinto.close();
					exit(0);
				}
				// Condtion for displaying the classes with vacancies
				else if (opt == "2") {
					displayClassWithVacancies();
				}
				// condition for booking a class
				else if (opt == "1") {
					BookAclass( userid);
				}
				//condition for cancelling a booking  
				else if (opt == "4") {
					Cancelbooking(userid);
				}
				// Condition for viewing booking list 
				else if (opt == "3") {
					Viewbookinglist(userid);
				}
			}
		}
	}

	//Destructor Doubly LinkedList
	while (!FitnessClass_list.empty()) {
		Node<FitnessClass>* cls = FitnessClass_list.getHead();
		FitnessClass* c = cls->getElem();

		while (!c->List_of_members.empty()) {
			c->List_of_members.removefront();
		}
		FitnessClass_list.removefront();
	}

}