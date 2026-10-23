#pragma once

class DLinkedList{
private:
	class Node{
	public:
		int info;
		Node* next;
		Node* prev;
		
		//constructor
		Node(int value): info(value), next(nullptr), prev(nullptr) {}
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
	bool addFront(int value);
	bool addBack(int value);
	bool addSorted(int value);		//for defeated monsters
	
	//getter methods
	int getSize();
	bool isEmpty();
	
	//search methods
	int* getValue(int index);
	bool searchValue(int value);
	
	//printing methods
	void printList();
	void printReverse();
	
	//delete methods
	bool clearList();
	bool deleteElement(int value);
};
