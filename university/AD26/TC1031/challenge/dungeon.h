#pragma once
#include "room.h"
#include "DLinkedList.h"

class Dungeon{
private: 
    DLinkedList<Room> rooms;

public:
    Dungeon();
    ~Dungeon();
    
    bool createRoom(const Monster& monster);
    Room getRoom(int pos);
    void printRooms();
    //int getRoomCount() const;

};