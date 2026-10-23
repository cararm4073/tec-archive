#pragma once

template <typename T>
class DLinkedList{
private:
	class Node{
	public:
		T info;
		Node* next;
		Node* prev;
		
		//constructor
		Node(T& value): info(value), next(nullptr), prev(nullptr) {}
	};
	
	//still under private, for double linked list
	Node* head;
	Node* tail;
	int size;
	
public:
	//constructor and destructor
	DLinkedList();
	~DLinkedList();
	
	//disable copy of the data structure by overloading operator =
	DLinkedList (const DLinkedList&) = delete;
	DLinkedList& operator= (const DLinkedList&) = delete;
	
	//insertion methods
	bool addFront(T& value);
	bool addBack(T& value);
	bool addSorted(T& value);		//for defeated monsters
	
	//getter methods
	int getSize();
	bool isEmpty();
	
	//search methods
	T* getValue(int index);
	bool searchValue(T& value);
	
	//printing methods
	void printList();
	void printReverse();
	
	//delete methods
	bool clearList();
	bool deleteElement(T& value);
};

#include "double.tpp"
