#pragma once
#include <iostream>

class BST{
private: 
    class Node{
    public:
        int data;
        Node* left;
        Node* right;

        //constructor
        Node(int value): data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    //private methods
    bool insertRecursive(Node** node, int data);
    int* searchRecursive(Node* current, int data) const;
    void deleteTreeRecursive(Node** node);
    void printInOrderRecursive(Node* node) const;
    void printByLevelsRecursive(Node* node, int level);
    void getValueRecursive(Node* node, int& currentIndex, int targetIndex, int *& result) const;    //needed for catalog


public:
    BST();
    ~BST();

    //disable copies
    BST(const BST& other) = delete;
    BST& operator= (const BST& other) = delete;

    //methods
    bool insert(int val);

    void clearTree();
    bool treeIsEmpty() const;

    int getTreeSize() const;

    void printTree() const;
    void printByLevels();
    
    int* searchValueTree(int value) const;
    int* getValue(int index) const;         //necesarry for catalog implementation
};