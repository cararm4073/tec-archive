#pragma once
#include <cstdlib>
#include <iostream>
#include "monster.h"
#include "BST.h"

class Catalog{
private:
    BST<Monster> monstersTree;

    //helpers when reading the file
    std::string trim(const std::string& data) const;
    void nextData(const std::string& line, int& pos, std::string& field) const;
    bool isNumber(const std::string& data) const;
    bool isDecimal(const std::string& data) const;
    bool parseData(const std::string& line, Monster& out) const;

public:
    Catalog();
    ~Catalog();

    //based on the code made during the first weeks of the course
    bool loadFromCSV(const std::string& filename);
    int getCatalogSize() const;
    void printCatalog() const;

    Monster* getRandomMonster() const;
    Monster* findMonster(const std::string& name) const;
};