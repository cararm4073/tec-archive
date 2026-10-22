#pragma once

class doubleLinkedList{
public:
	class Node{
	public:
		int data;
		Node* next;
		Node* prev;
	};
	
	doubleLinkedList();
	~doubleLinkedList();
	
	bool addFront(int value);
	bool addBack(int value);
	void print();
	void printReverse();
	
	bool deleteElement(int value);
	const Node* searchValue(int value);
	const Node* searchMiddle();


private:	
	Node* head;
	Node* tail;
	
};
