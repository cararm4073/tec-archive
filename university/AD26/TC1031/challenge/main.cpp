#include <iostream>
#include <ctime>
#include "DLinkedList.h"
#include "monster.h"
#include "BST.h"
#include "catalog.h"

int main(){
	//test of monster class
	Monster m1("goblin", 2, "humanoid", "small", 15, 9, "neutral");
	Monster m2("dragon", 24, "dragon", "big", 22, 30, "evil");
	Monster m3("witch", 1.5, "magic", "medium", 10, 15, "hostile");
	Monster m4("zombie", 3.0, "dead", "medium", 10, 20, "hostile");

	std::cout << "Monster 1: " << m1 << "\n";
	std::cout << "Monster 2: " << m2 << "\n";

	//test of double linked list
	std::cout << "\n";

	DLinkedList<Monster> myMonsters;
	myMonsters.addSorted(Monster("zombie", 3.0, "dead", "medium", 10, 20, "hostile"));
	myMonsters.addSorted(Monster("witch", 1.5, "magic", "medium", 10, 15, "hostile"));
	myMonsters.printList();
	myMonsters.printReverse();
	myMonsters.addSorted(Monster("magician", 2.3, "magic", "medium", 15, 13, "neutral"));
	myMonsters.printList();

	//test of BST
	std::cout << "\n";

	BST<Monster> myTree;
	myTree.insert(m2);
	myTree.insert(m1);
	myTree.insert(m3);
	myTree.printByLevels();
	std::cout << "Size of the tree: " << myTree.getTreeSize() << "\n";

	Monster* searchValue = myTree.searchValueTree(m2);
	std::cout << (searchValue ? "Found value" : "Value Not found") << "\n";

	myTree.insert(m4);
	myTree.printByLevels();
	std::cout << "Size of the tree: " << myTree.getTreeSize() << "\n";

	std::cout << "Second monster's address: " << myTree.getValue(2) << "\n";

	//test of catalog
	std::cout << "\n";
	std::srand(std::time(nullptr));

	Catalog myCatalog;
	bool loadFile = myCatalog.loadFromCSV("monsters.csv");
	std::cout << "Load: " << (loadFile ? "true" : "false") << "\n";
	std::cout << "Size: " << myCatalog.getCatalogSize() << "\n";

	myCatalog.printCatalog();
	Monster* findMyMonster = myCatalog.findMonster("octopus");
	if(findMyMonster) std::cout << "Found octopus: " << *findMyMonster << "\n";
	else std::cout << "My octopus was not found :(\n";

	findMyMonster = myCatalog.findMonster("crab");
	if(findMyMonster) std::cout << "Found crab: " << *findMyMonster << "\n";
	else std::cout << "My crab was not found :(\n";

	Monster* randomMonster = myCatalog.getRandomMonster();
	std::cout << "Random: " << *randomMonster << "\n";

	Catalog anotherCatalog;
	anotherCatalog.loadFromCSV("nonExisting.csv");

	return 0;
}
