#include <iostream>
#include "double.h"

doubleLinkedList::doubleLinkedList(){
	head = nullptr;
	tail = nullptr;
}

doubleLinkedList::~doubleLinkedList(){
	Node* temp = head;
	while(temp){
		Node* aux = temp->next;
		delete temp;
		temp = aux;
	}
	head = nullptr;
	tail = nullptr;
	
}

bool doubleLinkedList::addFront(int value){
    Node* newElement = new(std::nothrow) Node;

    if(!newElement){
        std::cerr << "Failed to create new element" << std::endl;
        return false;
    }

    newElement->data = value;
    newElement->prev = nullptr;
    newElement->next = head;

    if(head == nullptr){
        head = newElement;
        tail = newElement;
        return true;
    }

    head->prev = newElement;
    head = newElement;

    return true;
}

bool doubleLinkedList::addBack(int value){
    Node* newElement = new(std::nothrow) Node;

    if(!newElement){
        std::cerr << "Failed to create new element" << std::endl;
        return false;
    }

    newElement->data = value;
    newElement->next = nullptr;
    newElement->prev = tail;

    if(tail == nullptr){
        head = newElement;
        tail = newElement;
        return true;
    }

    tail->next = newElement;
    tail = newElement;

    return true;
}

void doubleLinkedList::print(){
    Node* temp = head;

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    std::cout << std::endl;
}

void doubleLinkedList::printReverse(){
    Node* temp = tail;

    while(temp != nullptr){
        std::cout << temp->data << " ";
        temp = temp->prev;
    }

    std::cout << std::endl;
}

bool doubleLinkedList::searchValue(int value){
    Node* temp = head;

    while(temp != nullptr){
        if(temp->data == value){
            return true;
        }

        temp = temp->next;
    }

    return false;
}

bool doubleLinkedList::deleteElement(int value){
    Node* temp = head;

    while(temp != nullptr && temp->data != value){
        temp = temp->next;
    }

    if(temp == nullptr){
        return false;
    }

    if(temp->prev == nullptr){
        head = temp->next;
    }
    else{
        temp->prev->next = temp->next;
    }

    if(temp->next == nullptr){
        tail = temp->prev;
    }
    else{
        temp->next->prev = temp->prev;
    }

    delete temp;

    return true;
}
