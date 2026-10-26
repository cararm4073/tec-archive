#include <iostream>
#include "dungeon.h"

//----------------------constructor and destructor----------------------
Dungeon::Dungeon() {}

Dungeon::~Dungeon() {} //dlinkedlist handles the delete of nodes

//----------------------methods----------------------
bool Dungeon::createRoom(const Monster& monster){
    //copy independent to monster's catalog
    Room newRoom(monster);

    //add room to the back of the linked list
    rooms.addBack(newRoom);
    return true;
}

Room Dungeon::getRoom(int pos){
    Room* roomG = rooms.getValue(pos);
    if(!roomG){
        std::cerr << "Room at index " << pos << " is out of range.\n";
        return Room();
    }
    return *roomG;
}

void Dungeon::printRooms() {
    rooms.printList();
}

