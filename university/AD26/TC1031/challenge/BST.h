#pragma once
#include <iostream>

template <typename T>
class BST{
private: 
    class Node{
    public:
        T data;
        Node* left;
        Node* right;

        //constructor
        Node(const T& value): data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int size;

    //private methods
    bool insertRecursive(Node** node, const T& data);
    T* searchRecursive(Node* current, const T& data) const;
    void deleteTreeRecursive(Node** node);
    void printInOrderRecursive(Node* node) const;
    void printByLevelsRecursive(Node* node, int level);
    void getValueRecursive(Node* node, int& currentIndex, int targetIndex, T*& result) const;    //needed for catalog


public:
    BST();
    ~BST();

    //disable copies
    BST(const BST& other) = delete;
    BST& operator= (const BST& other) = delete;

    //methods
    bool insert(const T& data);

    void clearTree();
    bool treeIsEmpty() const;

    int getTreeSize() const;

    void printTree() const;
    void printByLevels();
    
    T* searchValueTree(const T& data) const;
    T* getValue(int index) const;         //necesarry for catalog implementation
};

#include "BST.tpp"