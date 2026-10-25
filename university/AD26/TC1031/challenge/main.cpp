#include <iostream>
#include "DLinkedList.h"
#include "monster.h"

int main(){
	Monster m1("goblin", 2, "humanoid", "small", 15, 9, "neutral");
	Monster m2("dragon", 24, "dragon", "big", 22, 30, "evil");

	std::cout << "Monster 1: " << m1 << "\n";
	std::cout << "Monster 2: " << m2 << "\n";

	DLinkedList<Monster> myMonsters;
	myMonsters.addSorted(Monster("zombie", 3.0, "dead", "medium", 10, 20, "hostile"));
	myMonsters.addSorted(Monster("witch", 1.5, "magic", "medium", 10, 15, "hostile"));
	myMonsters.printList();
	myMonsters.printReverse();
	myMonsters.addSorted(Monster("magician", 2.3, "magic", "medium", 15, 13, "neutral"));
	myMonsters.printList();
	return 0;
}
