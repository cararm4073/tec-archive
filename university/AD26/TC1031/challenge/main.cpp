#include <iostream>
#include <ctime>
#include "catalog.h"
#include "dungeon.h"
#include "player.h"

#define NUM_ROOMS 20

int main() {
	srand(time(nullptr));


    Catalog myCatalog;
    Dungeon myDungeon;
    Player myPlayer("Carlos", "human");

    std::cout << "Loading file.\n";
    if (!myCatalog.loadFromCSV("monsters.csv")) {
        std::cout << "Could not create the catalog.\n";
        return 0;
    }

    std::cout << myCatalog.getCatalogSize() << " monsters loaded.\n";

    for (int i = 0; i < NUM_ROOMS; i++) {
        Monster* pMonster = myCatalog.getRandomMonster();
        if (!pMonster) {
            std::cout << "Couldn't get a random monster from the catalog.\n";
            return 0;
        }

        if (!myDungeon.createRoom(*pMonster)) {
            std::cout << "Could not add a room with a random monster to the dungeon.\n";
            return 0;
        }
    }

    //20 rooms
    myDungeon.printRooms();

    std::cout << "Player: " << myPlayer << "\n";

    return 0;
}