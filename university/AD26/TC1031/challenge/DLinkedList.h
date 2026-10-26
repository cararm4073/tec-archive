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
		Node(const T& value): info(value), next(nullptr), prev(nullptr) {}
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
	bool addFront(const T& value);
	bool addBack(const T& value);
	bool addSorted(const T& value);		//for defeated monsters
	bool insertAt(int index, const T& value);
	
	//getter methods
	int getSize();
	bool isEmpty();
	
	//search methods
	T* getValue(int index);
	bool searchValue(const T& value) const; //shouldn't modify the list itself
	
	//printing methods
	void printList();
	void printReverse();
	
	//delete methods
	bool clearList();
	bool deleteElement(const T& value);
};

#include "DLinkedList.tpp"
