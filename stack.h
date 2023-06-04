#ifndef STACK_H
#define STACK_H

#include <string>
#include <iostream>
#include <fstream>
#include "linkedlist.h"
#include "classes.h"

using namespace std;

// Creating a template class Stack
template <typename T>class Stack {

public:
	Stack();
	~Stack();
	bool isEmpty();
	void push(T k);
	void pop();
	int size();
	void displayStack() const;
	const T& frontstack() const;
	Node<T>* getHead();

private:
	Node<T>* head;
	Node<T>* tail;

};
// Constrcutor for the stack class
template <typename T> Stack<T>::Stack() {
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	tail->prev = head;
}
// Destructor of stack
template <typename T> Stack<T>::~Stack() {
	while (!isEmpty())
		pop();
	delete head;
	delete tail;
}
// Getting head of stack
template <typename T>
Node<T>* Stack<T>::getHead() {
	return head;
}
// Member function that adds an element to the stack list
template <typename T> void Stack<T>::push(T k)
{
	Node<T>* v = new Node<T>;
	v->elem = k;
	v->next = head->next;
	v->prev = head;
	head->next->prev = v;
	head->next = v;
}
// Member function that removes an element to the stack list
template <typename T> void Stack<T>::pop() {
	Node<T>* v;
	v = head->next;
	Node<T>* u = v->prev;
	Node<T>* m = v->next;
	u->next = m;
	m->prev = u;
	delete v;
}
// Member function that checks if stack is empty
template <typename T> bool Stack<T>::isEmpty()
{
	return head->next == tail;
}
// Member function that checks the size of the stack list
template <typename T> int Stack<T>::size() {
	// Counter for elements in the stack class
	int count = 0;
	// Creating new node pointer that points to the front of the stacklist
	Node<T>* temp = head->next;
	if (temp == tail) {
		return count;
	}
	// Traversing through the stack list
	while (temp != tail) {
		count++;
		temp = temp->next;
	}
	return count;
}


// Member function that returns the front/top element from the stack list
template <typename T> const T& Stack<T>::frontstack() const
{
	return head->next->elem;
}

//============================================================


template <typename T> void Stack<T>::displayStack() const
{

	Node<T>* temp;
	// Assigning head to a newly created pointer
	temp = head;
	//looping through to the end of the linked list
	cout << "Currently Enrolled Members" << endl;
	cout << "+----------------------------+" << endl;
	while (temp != NULL)
	{
		T* nad = temp->getElem();
		cout << setw(5) << left << nad->id
			<< setw(15) << right << nad->firstname
			<< setw(15) << right << nad->lastname << endl;
		temp = temp->getNext();
	}
}



#endif