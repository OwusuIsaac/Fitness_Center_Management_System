#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// Creating a template class node
template <typename T> 
class Node
{
   private:
      T elem;
      Node<T>* next;
      Node<T>* prev;
      // Making DoublyLinkedList class access members of the node class
      template <typename U> friend class DoublyLinkedList;
      // Making Stack class access members of the node class
      template <typename U> friend class Stack;

   public:
      Node() : next(NULL), prev(NULL)
      {}
      Node(T elem) : elem(elem), next(NULL), prev(NULL)
      {}
      T* getElem();
      Node<T>* getNext();
      void setNext(Node<T>* elem);
      Node<T>* getPrev();
      void setPrev(Node<T>* elem);
};

template <typename T>
T* Node<T>::getElem() {
	return &elem;
}

template <typename T>
Node<T>* Node<T>::getNext() {
	return next;
}

template <typename T>
void Node<T>::setNext(Node<T>* elem) {
	this->next = elem;
}

template <typename T>
Node<T>* Node<T>::getPrev() {
	return prev;
}

template <typename T>
void Node<T>::setPrev(Node<T>* elem) {
	this->prev = elem;
}
 //===================================================================

 // Creating a template class DoublyLinkedList
template <typename T>
class DoublyLinkedList
{
private:
	Node<T>* head;
	Node<T>* tail;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool empty() const;
	void add(const T& elem);
	void remove(Node<T>* id);
	void removefront();
	void display() const;
	const T& front() const;
	int size();
	Node<T>* getHead() {
		return head;
	}
};
// Constrcutor for the DoublyLinkedList class
template <typename T> 
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = new Node<T>;
	tail = new Node<T>;
	head->next = tail;
	tail->prev = head;
}
// Deconstrcutor for the DoublyLinkedList class
template <typename T> 
DoublyLinkedList<T>::~DoublyLinkedList()
{
	// while (!empty()) removefront();
	// delete head;
	// delete tail;
}
// Member function that checks the size of the DoublyLinked List 
template <typename T> 
int DoublyLinkedList <T>::size() {
	int count = 0;
	Node<T>* temp = head->next;
	if (temp == tail) {
		return count;
	}
	while (temp != tail) {
		count++;
		temp = temp->next;
	}
	return count;
}
// condition for checking if doubly linked list is empty
template <typename T> 
bool DoublyLinkedList<T>::empty() const
{
	return head->next == tail;
}

// Member function that adds an element to the DoublyLinked list
template <typename T> 
void DoublyLinkedList<T> ::add(const T& e)
{
	Node<T>* v = new Node<T>;
	v->elem = e;
	v->next = head->next;
	v->prev = head;
	head->next->prev = v;
	head->next = v;
}
// Member function that removes an element to the DoublyLinked list
template <typename T> 
void DoublyLinkedList<T>::remove(Node<T>* userid)
{
	Node<T>* temp = head->next;
	while (temp != tail) {
		if (temp == userid) {
			Node<T>* v= temp;
			Node<T>* u = v->prev;
			Node<T>* m = v->next;
			u->next = m;
			m->prev = u;
			delete v;
			return;
		}
		temp = temp->next;
	}
	cout << "Search item does not exist" << endl;
}

template <typename T> 
void DoublyLinkedList<T>::removefront()
{
	Node<T>* v;
	v = head->next;
	Node<T>* u = v->prev;
	Node<T>* m = v->next;
	u->next = m;
	m->prev = u;
	delete v;
}

// Member function gets front of doubly linked list
template <typename T> 
const T& DoublyLinkedList<T>::front() const
{
	return head->next->elem;
}

template <typename T> 
void DoublyLinkedList<T>::display() const
{

	Node<T>* curr = head;
	while (curr != NULL)
	{
		cout << "+------";
		curr = curr->next;
	}
	cout << "+" << endl << "|";
	curr = head;
	while (curr != NULL)
	{
		if (curr == head) cout << " Head |";
		else if (curr == tail) cout << " Tail |";
		else cout << setw(5) << curr->elem.Class_Name << " |";

		curr = curr->next;
	}
	curr = head;
	cout << endl;
	while (curr != NULL)
	{
		cout << "+------";
		curr = curr->next;
	}
	cout << "+" << endl;
}

//===============================================================================
#endif