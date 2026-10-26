#include "catalog.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <ctime>

//----------------------constructor and destructor----------------------
Catalog::Catalog() {
    std::srand(std::time(nullptr));
}

Catalog::~Catalog(){
    monstersTree.clearTree();   //using the function from BST
}

//----------------------helpers----------------------
std::string Catalog::trim(const std::string& data) const{
    int start = 0;              //position after first string's char
    int end = data.size();      //position after last char from string
    
    //loop used to move to next char if it is a space or a \r at beginning of string
    while(start < end){                             //while we haven't reached the end
        char cData = data[start];                   //store the character from start
        if((cData == ' ') or (cData == '\r')){      //check if it is a space or a \r
            start++;                                //yes: jump and move to next char
        } else break;                               //no: there is text, exit while loop

    }

    //go backwards while there is a space or a \r at the end
    while(end > start){                             //while we don't go into start's value
        char cData = data[end -1];                  //store last real char
        if((cData == ' ') or (cData == '\r')){      //chec if it is a space or a \r
            end--;                                  //yes: jump and go backwards once, to prev char
        } else break;                               //no: there is text, exit while loop
    }

    //using substring, we take a portion of a string and return it as a new string
    return data.substr(start, end-start);           //copy from start until end-start (our desired text)
}


void Catalog::nextData(const std::string& line, int& pos, std::string& field) const{
    //check if we have read the last data, or if there is no data at all
    if(pos == -1) return; 

    //looks for the next coma, starting at pos. returns -1 if there are no left
    int comma = line.find(',', pos);

    if(comma == -1){                                    //are there any extra commas? if not, last field
        field = trim(line.substr(pos));                 //from pos until the end of the string, without spaces
        pos = -1;                                       //there are no fields left, last one
    } else {                                            //are there any extra commas? yes, and the field ends before that comma
        field = trim(line.substr(pos, comma-pos));      //just takes the string between pos and where the comma is at
        pos = comma+1;                                  //next field starts after the comma 
    }
}


bool Catalog::isNumber(const std::string& data) const{
    if( (data.empty()) or (data.size() > 9) ) return false;     //field is empty, or it is too large to be a number

    int length = data.size();
    for(int i=0; i<length; i++){                           //go through each string's character
        if(data[i] < '0' or data[i] > '9') return false;       //if the car is not between '0' and '9', it is not a number (compares strings)
    }
    return true;                                                //all string's chars were numbers
}


bool Catalog::isDecimal(const std::string& data) const{
    if( (data.empty()) or (data.size() > 15) ) return false;            //field is empty, or it is too large

    bool hasPoint = false;      //is there a point?
    bool hasDigit = false;      //is there at leat one number?

    int length = data.size();
    for(int i=0; i < length; i++){                              //go through each string's char
        if(data[i] >= '0' and data[i] <= '9') hasDigit = true;          //is it a number?
        else if(data[i] == '.' and (hasPoint == false)) hasPoint = true; //is there a point, and is it the first one (avoid multiple points)?
        else return false;                                              //anything else in the string, like a letter. not a decimal
    }

    return hasDigit;                                                    //if there is only a dot it doesn't count. there should be a number at least
}


bool Catalog::parseData(const std::string& line, Monster& out) const{
    //a string for each csv's column
    std::string nameString, crString, typeString, sizeString, acString, hpString, alignString;
    int pos = 0;

    //read the 7 columns or fields. a missing one stays empty
    nextData(line, pos, nameString);
    nextData(line, pos, crString);
    nextData(line, pos, typeString);
    nextData(line, pos, sizeString);
    nextData(line, pos, acString);
    nextData(line, pos, hpString);
    nextData(line, pos, alignString);

    //if there are more than 7 fields, there is no text missing
    if(pos != -1) return false;

    //no field can be empty, and there are monsters with less than 7 fields
    //string fields
    if(nameString.empty() or typeString.empty() or sizeString.empty() or alignString.empty()) return false;
    //number fields
    if(!isDecimal(crString) or !isNumber(acString) or !isNumber(hpString)) return false;

    //data conversion, only numbers as strings were checked prev
    double cr = std::stod(crString);
    int ac = std::stoi(acString);
    int hp = std::stoi(hpString);

    //verify if it has health
    //if(hp <= 0) return false;     //comment for now, otherwise the loading stops at line 236

    //create a monster with the converted and parsed data, sending it as 'out'
    //to-do: there might be another way to output this result, check
    out = Monster(nameString, cr, typeString, sizeString, ac, hp, alignString);
    return true;
}

//----------------------methods for managing the file itself----------------------

bool Catalog::loadFromCSV(const std::string& filename){
    std::ifstream file(filename);
    if(!file.is_open()){
        std::cerr << "Could not open file " << filename << "\n";
        return false;
    }

    
    std::string line;                               //parse from file
    if(!std::getline(file, line)) return false;     //discard the header from CSV, first line

    int lineNumber = 1;                             //header was line 1, or 0 in the program. starting where data should be
    int loaded = 0;                                 //how many monsters have been loaded from csv into the program
    
    //read line per line, until end of file
    while(std::getline(file, line)){
        lineNumber++;
        
        if(trim(line).empty() == true) continue;    //there is a blank line, skip it
        Monster monster;                            //create new empty monster

        //if line from file is invalid (missing or extra fields, invalid conversions), let the user know and move to next line
        if(parseData(line, monster) == false){
            std::cerr << "Invalid data at line " << lineNumber << ". Stopping load.\n";
            monstersTree.clearTree();
            return false;
        }

        //insert the monster into the BST, return false if it is a duplicate
        if(monstersTree.insert(monster) == true) loaded++;
        else {
            std::cerr << "Duplicate monster at line " << lineNumber << ". Skipped.\n";
            monstersTree.clearTree();
            return false;
        }
    }
    
    //show final results of loading monsters from csv into the program
    std::cout << "Monsters loaded: " << loaded << "\n";
    
    //return bool 
    if(loaded>0) return true;                      //return x number of loaded monsters    
    else return false;                             //did not save any monster, return false

}

int Catalog::getCatalogSize() const{
    return monstersTree.getTreeSize();  //use method from BST, the monsters should be loaded into the tree, allowing it to have a size
}

Monster* Catalog::getRandomMonster() const{
    int total = monstersTree.getTreeSize();
    //if BST is empty
    if(total==0) return nullptr;

    int randIndex = std::rand() % total;
    return monstersTree.getValue(randIndex);
}

Monster* Catalog::findMonster(const std::string& name) const{
    Monster monsterTarget(name, 0.0, "", "", 0, 0, "");
    return monstersTree.searchValueTree(monsterTarget);
}

void Catalog::printCatalog() const{
    monstersTree.printTree();   //using method form bst
}

/*
Resources used:
    Part of the code developed on the first weeks of the course
    https://www.youtube.com/watch?v=NFvxA-57LLA
    https://www.youtube.com/watch?v=nkKeA74p3RY
    https://www.geeksforgeeks.org/cpp/substring-in-cpp/
*/