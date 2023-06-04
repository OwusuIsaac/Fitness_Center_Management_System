#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <iostream>
#include <fstream>





void AdminOptions() {
	cout << "The List of available operation for Admins:" << endl
		<< "1 : Register A New Admin" << endl
		<< "2 : Register A New Member" << endl
		<< "3 : Add A Fitness Class" << endl
		<< "4 : Delete A Fitness Class" << endl
		<< "5 : Update The Details Of A Fitness Class" << endl
		<< "6 : Display The Class With Vacancies" << endl
		<< "7 : View the list of members" << endl
		<< "8 : Update the capacity of fitness class" << endl
		<< "9 : Split a fitness class into two classes" << endl
		<< "10 : Logout" << endl
		<< "11 : Quit Program" << endl;
}

void MemberOptions()
{
	cout << "You have Logged in successfully!" << endl;
	cout << "The List of available operation for Members:" << endl
		<< "1 : Book A Class" << endl
		<< "2 : Display The Class With Vacancies" << endl
		<< "3 : View Bookiing list" << endl
		<< "4 : Cancel Booking"<<endl
		<< "5 : logout" << endl
	    << "6 : Quit Program              " << endl;
}

// LISTS
DoublyLinkedList <FitnessClass> FitnessClass_list;
Stack <Admin> Admins_list;
Stack <Member> Members_list;

// login function 
bool login(string& username, string& password, int userType, string& userid) {
	if (userType == 0) {
		Node<Admin>* v = Admins_list.getHead();
		// Looping through the admin list
		while (v != nullptr)
		{
			Admin* ban = v->getElem();
			// Checking if the username and password matches one in the admin list
			if (ban->username == username && ban->password == password)
			{
				userid = ban->id;
				return true;
			}
			v = v->getNext();
		}
		return false;
	}
	else {
		Node<Member>* v = Members_list.getHead();
		// Looping through the member list
		while (v != nullptr)
		{
			Member* ban = v->getElem();
			// Checking if the username and password matches one in the member list
			if (ban->username == username && ban->password == password)
			{
				userid = ban->id;
				return true;
			}
			v = v->getNext();
		}
		return false;
	}
}
// Function for adding to the fitness class
FitnessClass addFitnessClass() {
	// Getting fitness class detalis
	string id, name, date, time, room;
	cout << "Create a new Fitness Class!" << endl;
	cout << "Enter the details of the class: " << endl;
	cout << "Class ID: ";
	cin >> id;
	cout << "Class name: ";
	cin >> name;
	cout << "Class date: ";
	cin >> date;
	cout << "Class time: ";
	cin >> time;
	cout << "Class room number: ";
	cin >> room;
	//creating fitness class
	FitnessClass X(id, name, date, time, room);
	return X;
}
// Function for adding an admin to the admin list
Admin registerAdmin() {
	// Getting Admin details
	string fname, lname;
	cout << "Register a new Admin!" << endl;
	cout << "Enter the details of the new admin: " << endl;
	cout << "User's first name: ";
	cin >> fname;
	cout << "User's last name: ";
	cin >> lname;
	// Creating an admin object
	Admin X(fname, lname);
	return X;
}

Member registerMember() {
	// Getting member details
	string fname, lname;
	cout << "Register a new Member!" << endl;
	cout << "Enter the details of the new Member: " << endl;
	cout << "User's first name: ";
	cin >> fname;
	cout << "User's last name: ";
	cin >> lname;
	// Creating an member object
	Member X(fname, lname);
	return X;
}
// Viewing member list 
void viewMemberList() {
	Members_list.displayStack();
}
// Function for deleting a fitness class
void deleteFitnessClass() {
	FitnessClass_list.display();
	// Receiving id of class to be removed
	string id;
	cout << "Enter the class ID: ";
	cin >> id;

	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping thropugh fitness class
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		if (cls->ClassID == id) {
			// Removing fitness class
			FitnessClass_list.remove(v);
			cout << "Fitness Class deleted successfully" << endl;
			return;
		}
		v = v->getNext();
	}
	cout << "Erro:There is no class with the id provided" << endl;
}
// Function for updating the fitness class details 
void updateFitnessClass() {
	FitnessClass_list.display();
	cout << "UPDATE FITNESS CLASS" << endl;
	cout << "+----------------------------+" << endl;
	string id;
	// Receiving id of class to be updated
	cout << "Enter the class ID: ";
	cin >> id;

	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping thropugh fitness class
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		// Condition for when a class is found
		if (cls->ClassID == id) {
			string option;
			cout << "Choose the attribute you want to change: \n"
				<< "1. ID\n"
				<< "2. Name\n"
				<< "3. Date\n"
				<< "4. Time\n"
				<< "5. Room number\n"
				<< ">>> ";
			cin >> option;
			//Do checks
			char opts = option[0];
			string input;
			switch (opts)
			{
			case '1':
				cout << "Enter new ID: ";
				cin >> input;
				cls->ClassID = input;
				return;
			case '2':
				cout << "Enter new name: ";
				cin >> input;
				cls->Class_Name = input;
				return;
			case '3':
				cout << "Enter new date: ";
				cin >> input;
				cls->Class_date = input;
				return;
			case '4':
				cout << "Enter new time: ";
				cin >> input;
				cls->Class_time = input;
				return;
			case '5':
				cout << "Enter new room number: ";
				cin >> input;
				cls->Room_number = input;
				return;
			default:
				cout << "Wrong input! No such attribute.";
				return;
			}
		}
		else {
			cout << "Error:There is no class with the id provided" << endl;
			return;
		}
		v = v->getNext();
	}
}

void changeClassCapacity() {
	FitnessClass_list.display();
	cout << "CHANGE CLASS CAPACITY" << endl;
	cout << "+----------------------------+" << endl;
	string id;
	// Receiving id of class to have it's capacity updated
	cout << "Enter the class ID: ";
	cin >> id;

	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping thropugh fitness class
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		// Condition for when the class is found
		if (cls->ClassID == id) {
			cout << "Current capacity of " << cls->Class_Name << " is: " << cls->Maximum_capacity << endl;
			string capacity;
			cout << ">> What is the new capacity?: ";
			cin >> capacity;
			while (capacity < "5" && capacity > "15")
			{
				cout << "Error: capacity should be between 5 and 15 " << endl;
				cin >> capacity;
			}

			cls->Maximum_capacity = capacity;
			Node<string>* s = cls->List_of_members.getHead();
			int count = 0;
			// Looping through the list of members in the found class to find number of members there
			while (s != nullptr) {
				string* hold = s->getElem();
				count++;
				s = s->getNext();
			}
			count -= 2;
			stringstream size(capacity);
			int l = 0;
			size >> l;
		   // condition for when list of members is greater than the new capacity 
			if (l < count) {
				int y = count - l;
				int i = 0;
				while (true) {
					++i;
					Node<string>* x = cls->List_of_members.getHead();
					Node<string>* z = x->getNext();
					Node<string>* u = x;
					int cont = 0;
					while (z->getNext() != nullptr) {
						cont++;
						if (cont > l && cont <= count) {
							u = z->getPrev();
							// removing excess members  
							cls->List_of_members.remove(z);
							z = u;
						}
						z = z->getNext();
					}
					break;
				}

			}

			else if (l > count) {
				cls->Maximum_capacity = capacity;
			}
		}
		else {
			cout << "Error:There is no class with the id provided" << endl;
			return;
		}
		v = v->getNext();
	}
	cout << "Class with class id " << id << " does not exist" << endl;
}

void displayClassWithVacancies() {

	cout << "CLASS WITH VACANCIES" << endl;
	cout << "+----------------------------+" << endl;

	Node<FitnessClass>* v = FitnessClass_list.getHead();
	int vacancies = 0;
	cout << setw(5) << right << "ID" << " |"
		<< setw(15) << right << "Class Name" << " |"
		<< setw(15) << right << "Class Time" << " |"
		<< setw(15) << right << "Class Date" << " |"
		<< setw(5) << right << "Room Number" << endl;
	// Looping through the fitness class list
	while (v != NULL)
	{
		FitnessClass* cls = v->getElem();
		stringstream size(cls->Maximum_capacity);
		int x = 0;
		size >> x;
		// Checking for available space in the class
		if (x - cls->curr_capacity > 0)
		{
			// Printing classes with vacancies
			cout << setw(5) << right << cls->ClassID << " |"
				<< setw(15) << right << cls->Class_Name << " |"
				<< setw(15) << right << cls->Class_time << " |"
				<< setw(15) << right << cls->Class_date << " |"
				<< setw(5) << right << cls->Room_number << endl;

			++vacancies;
		}
		v = v->getNext();
	}
	if (vacancies == 0)
		cout << "No class with vacancies" << endl;
}

// Function for booking a class
void BookAclass(const string userid) {
	// Asking for class Id
	string id;
	cout << "Enter the class ID: ";
	cin >> id;
	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping through the fitness class 
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		// condtion for id match
		if (cls->ClassID == id) {
			// Converting Maximum_capacity to integer
			stringstream cap(cls->Maximum_capacity);
			int x;
			cap >> x;
			if (cls->List_of_members.size() < x ) {
				cls->List_of_members.add(userid);
				cout << "Class booked successfully" << endl;
				Node<string>* s = cls->List_of_members.getHead();
				while (s != nullptr) {
					string* hold = s->getElem();
					s = s->getNext();
				}
				return;
			}
			// condition for when the class is full
			else {
				cout << "Class is full: Consider booking another class" << endl;
				return;
			}
		}
		v = v->getNext();
	}
	cout << "Class does not exist" << endl;
}
// Function for cancelling a booking
void Cancelbooking(const string userid) {
	// Asking for class Id
	string id;
	cout << "Enter the ID of the class you want to cancel the booking: ";
	cin >> id;
	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping through the fitness class list
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		// condtion for id match
		if (cls->ClassID == id) {
			Node<string>* s = cls->List_of_members.getHead();
			// Looping through the list of members
			while (s != nullptr) {
				string* hold = s->getElem();
				if (*hold == userid) {
				 cls->List_of_members.remove(s);
				 cout << "Booking cancelled sucessfully" << endl;
					return;
				}
				s = s->getNext();
			}
			cout << "You are not enrolled in this class" << endl;
			return;
		}
		v = v->getNext();
	}
	cout << "Class does not exist" << endl;

}
//Function for viewing booking list
void Viewbookinglist(const string userid) {
	Node<FitnessClass>* v = FitnessClass_list.getHead();
	cout <<"Your Booking List Is:" << endl;
	cout << setw(15) << right << "Class Name" << " |"
		<< setw(15) << right << "Class_time" << " |"
		<< setw(15) << right << "Class_date" << " |"
		<< setw(5) << right << "Room_number" << endl;
	// Looping through the FitnessClass_list 
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		Node<string>* s = cls->List_of_members.getHead();
		// Looping through the list of members in a class
		while (s != nullptr) {
			string* hold = s->getElem();
			if (userid == *hold) { 
					cout << setw(15) << right << cls->Class_Name << " |"
					<< setw(15) << right << cls->Class_time << " |"
					<< setw(15) << right << cls->Class_date << " |"
					<< setw(5) << right << cls->Room_number << endl;
			}
			s = s->getNext();
		}
		v = v->getNext();
	}
	
}

void Splitfitnessclass() {
	// Asking for class Id
	string id;
	cout << "Enter the ID of the class you want to split: ";
	cin >> id;
	Node<FitnessClass>* v = FitnessClass_list.getHead();
	// Looping through the fitness class list
	while (v != NULL) {
		FitnessClass* cls = v->getElem();
		// condtion for id match
		if (cls->ClassID == id) {
			string input;
			cout <<"Enter 1 to specify the capacities of the resulting classes" << endl;
			cout << "Enter 2 to set default resulting class sizes (capacity 10)" << endl;
			cin >> input;
			if (input == "1") {
				int old_class, new_class;
				cout << "Enter the capacity of the first class" << endl;
				cin >> old_class;
				cout << "Enter the capacity of the second class" << endl;
				cin >> new_class;
				// looping through the list of members in the class 
				Node<string>* s = cls->List_of_members.getHead();
				int count = 0;
				while (s != nullptr) {
					string* hold = s->getElem();
					count++;
					s = s->getNext();
				}
				// number ofmembers in the class
				count -= 2;
				// condition for when the number of members in the class is less than the new capacity of the old class
				if (old_class > count) {
					cls->Maximum_capacity= old_class;
					// Creating new class
					FitnessClass X;
					string e;
					cout << "Please Enter ID of new Class" << endl;
					cin >> e;
					X.ClassID = e;
					X.Class_Name = cls->Class_Name;
					X.Maximum_capacity = new_class;
					X.Class_Name = cls->Class_Name;
					string answer;
					cout << "Would you like to change the date and time [yes / no ]" << endl;
					cin >> answer;
					while (answer != "yes" && answer != "no")
					{
						cout << "Error:please enter yes or no" << endl;
						cin >> answer;
					}
					if (answer == "yes") {
						string date, time,room;
						cout << "Please Enter New date" << endl;
						cin >> date;
						cout << "Please Enter New Time" << endl;
						cin >> time;
						cout << "Please Enter New Room number " << endl;
						cin >> room;
						X.Room_number = room;
						X.Class_time = time;
						X.Class_date = date;

					}
					else if (answer == "no") {
						X.Class_time = cls->Class_time;
						X.Class_date = cls->Class_date;
						X.Room_number = cls->Room_number;
					}
					// Adding the class to the fitness class list
					FitnessClass_list.add(X);
				}
				// condition for when the number of members in the class is greater than the new capacity of the old class
				else if (old_class < count) {
					int y = count - old_class;
					int i = 0;
					// Creating new class
					FitnessClass X;
					string e;
					cout << "Enter ID of New class" << endl;
					cin >> e;
					X.ClassID = e;
					while (true) {
						++i;
						Node<string>* x = cls->List_of_members.getHead();
						Node<string>* z = x->getNext();
						Node<string>* u = x;
						int cont = 0;
						while (z->getNext() != nullptr) {
							cont++;
							cout << "Curr z: " << *(z->getElem()) << endl;
							if (cont > old_class && cont <= count) {
								string* hold = z->getElem();
								string d;
								d = *hold;

								cout << "memer to be moved " << *hold << endl;
								// Adding excess members to the new class
								X.List_of_members.add(d);
								cout << "added successfully" << endl;
								u = z->getPrev();
								// Removing the excess members from the old class
								cls->List_of_members.remove(z);
								z = u;
							}
							z = z->getNext();
						}
						break;
					}
					// Adding fitness class to fitness class list
					FitnessClass_list.add(X);
				}
			}
			else if (input == "2") {
				// creating new class
				FitnessClass X;
				string e;
				cout << "Please Enter ID of new Class" << endl;
				cin >> e;
				X.ClassID = e;
				X.Class_Name = cls->Class_Name;
				string answer;
				cout << "Would you like to change the date and time [yes / no ]" << endl;
				cin >> answer;
				while (answer != "yes" && answer != "no")
				{
					cout << "Error:please enter yes or no" << endl;
					cin >> answer;
				}
				if (answer == "yes") {
					string date,time,room ;
					cout<<"Please Enter New date" << endl;
					cin >> date;
					cout << "Please Enter New Time" << endl;
					cin >> time;
					cout << "Please Enter New Room number " << endl;
					cin >> room;
					X.Class_time = time;
					X.Class_date = date;
					X.Room_number = room;

				}
				else if (answer == "no") {
					X.Class_time = cls->Class_time;
					X.Class_date = cls->Class_date;
					X.Room_number = cls->Room_number;
				}
				// Adding new class to fitness class list
				FitnessClass_list.add(X);
			}
			return;
		}
		v = v->getNext();
	}

}


#endif