#include <iostream>
#include "DLinkedList.h"

//constructor for double linked list
template <typename T>
DLinkedList<T>::DLinkedList() : head(nullptr), tail(nullptr), size(0) {}

//destructor for double linked list
template <typename T>
DLinkedList<T>::~DLinkedList() {
	clearList();
}

template <typename T>
bool DLinkedList<T>::addFront(const T& value){
	Node* newElement = new(std::nothrow) Node(value);
	if(!newElement){
		std::cerr << "Failed to create new element.\n";
		return false;
	}
	//to-do: the std::cerr can be moved into main, as the function returns a bool anyways
	
	newElement->info = value;
	newElement->prev = nullptr;
	newElement->next = head;
	size++;
	
	//can also use !head, or call isEmpty() when implemented. so far, this is how I have implemented it before
	if(head == nullptr){
		head = newElement;
		tail = newElement;
		return true;
	}
	
	head->prev = newElement;
	head = newElement;
	return true;
}

template <typename T>
bool DLinkedList<T>::addBack(const T& value){
	Node* newElement = new(std::nothrow) Node(value);
	if(!newElement){
		std::cerr << "Failed to create new element.\n";
		return false;
	}
	
	newElement->info = value;
	newElement->prev = tail;
	newElement->next = nullptr;
	size++;
	
	if(tail == nullptr){
		head = newElement;
		tail = newElement;
		return true;
	}
	
	tail->next = newElement;
	tail = newElement;
	return true;
}

template <typename T>
bool DLinkedList<T>::addSorted(const T& value){
	//base case: if list is empty, or value is less or equal than first element. add to head
	if (!head or value <= (head->info)) {
		return addFront(value); 	//addFront is also a bool, so we return the overall output of it with this function
	}
	
	//base case: if value is greater or equal than last element, add directly to the back or tail
	if (!tail or value >= (tail->info)) {
		return addBack(value);
	}
	
	Node* newElement = new(std::nothrow) Node(value);
	if(!newElement){
		std::cerr << "Failed to create new element.\n";
		return false;
	}
	
	Node* current = head;
	//loop to go through the list
	while ((current != nullptr) and (current->info < value)){
		current = current->next;
	}
	
	//connect new node
	newElement->next = current;
	newElement->prev = current->prev;
	//neighbor nodes point to the new node
	current->prev->next = newElement;
	current->prev = newElement;
	
	size++;
	return true;
}

template <typename T>
void DLinkedList<T>::printList(){
	Node* temp = head;
	
	while(temp != nullptr){
		std::cout << temp->info << " ";
		temp = temp->next;
	}
	std::cout << "\n";
}

template <typename T>
void DLinkedList<T>::printReverse(){
	Node* temp = tail;
	while(temp != nullptr){
		std::cout << temp->info << " ";
		temp = temp->prev;
	}
	std::cout << "\n";
}

template <typename T>
bool DLinkedList<T>::searchValue(const T& value) const{
	if(!head){
		std::cout << "List is empty.\n";
		return false;
	}
	
	Node* temp = head;
	while(temp != nullptr){
		if(temp->info == value){
			return true;		//if value was found, returns true, otherwise moves to next element
		}
		temp = temp->next;
	}
	
	//if after running through all the list, the value was not found, the code will never go into return true, therefore:
	return false;
}

template <typename T>
bool DLinkedList<T>::clearList(){
	if(!head) return false;		//this line could be deleted, as deleting an empty list is already successful
	
	Node* temp = head;
	while(temp){
		Node* aux = temp->next;
		delete temp;
		temp = aux;
	}
	size = 0;
	//we could not do this, yet I find it as a good, probably redundant
	head = nullptr;
	tail = nullptr;
	return true;
}

template <typename T>
bool DLinkedList<T>::deleteElement(const T& value){
	//again, cerr could be moved by comparing true or false in main. could also call isEmpty()
	if(!head){
		std::cout << "There is no list to delete value from.\n";
		return false;
	}
	
	Node* temp = head;
	// while we are not at the end of the list, and the current node's data is not 
	// the value we are looking for, move to next node
	while((temp != nullptr) and (temp->info != value)){
		temp = temp->next;
	}
	
	// or cerr and cout could be in here as they actually tell the user what went wrong
	// in main there is no specific way to know what went wrong, as we only get bool
	// maybe a return int with different value could work to put this logic of saying what went wrong or not in main
	if(temp == nullptr){
		std::cout << "Value not found";
		return false;
	}
	
	//connect nodes in front
	if(temp->prev == nullptr){
		//if temp doesn't have any previous node, it is the head
		//new head is current temp's next node
		head = temp->next;
	} else {
		//previous node should point to temp's next node
		temp->prev->next = temp->next;
	}
	
	//connect nodes from back, tail
	if(temp->next == nullptr){
		//if temp doesn't have a next, we are at the tail
		//tail is the previous node, not the current (temp) one
		tail = temp->prev;
	} else {
		//next node should point to temp's previous node
		temp->next->prev = temp->prev;
	}
	
	delete temp;
	size--;
	return true;
}

template <typename T>
int DLinkedList<T>::getSize() {
    return size;
}

template <typename T>
bool DLinkedList<T>::isEmpty() {
    if(head == nullptr) return true;
	return false;
}

template <typename T>
T* DLinkedList<T>::getValue(int index) {
    if(!head){
		std::cerr << "There is no list.\n";
		return nullptr;
	}
    
    //check if range is valid
    if(index < 0 or index >= size){
		std::cerr << "Given index is out of range.\n";
		return nullptr;
	}
	
	Node* temp = nullptr;
	//bidirectional search in double linked list
	if(index < size / 2){
		//if index is in first half, we move from head onwards
		temp = head;
		for(int i=0; i < index; i++){
			temp = temp->next;
		}
	} else {
		//if index is on the second half, we move from tail backwards
		temp = tail;
		for(int i=size-1; i > index; i--){
			temp = temp->prev;
		}
	}
	//return memory address rather than an int value
	return &(temp->info); 
}
