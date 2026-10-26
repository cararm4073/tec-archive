#include <iostream>

//----------------------constructor and destructor----------------------
template <typename T>
BST<T>::BST() : root(nullptr), size(0) {}

template <typename T>
BST<T>::~BST(){
    clearTree();
}

//----------------------clear methods----------------------
template <typename T>
void BST<T>::clearTree() {
    deleteTreeRecursive(&root);
    size = 0;
}
template <typename T>
void BST<T>::deleteTreeRecursive(typename BST<T>::Node** node){
    if(*node){
        deleteTreeRecursive( &((*node)->left) );
        deleteTreeRecursive( &((*node)->right) );

        delete *node;
        *node = nullptr;
    }
}

//----------------------insertion methods----------------------
template <typename T>
bool BST<T>::insert(const T& data){
    return insertRecursive(&root, data);
}

template <typename T>
bool BST<T>::insertRecursive(typename BST<T>::Node** node, const T& data){
    if(!*node) {
        *node = new(std::nothrow) Node(data);
        if(!*node) return false;
        size++;         //as we just added a new node, increment the size
        return true;
    }

    //inserting duplicate values is not allowed for now. chance < to <= otherwise
    if(data < ((*node)->data) ) return insertRecursive(&(*node)->left, data);
    else if(data > ((*node)->data) ) return insertRecursive(&(*node)->right, data);
    return false;
}

//----------------------searchinng methods----------------------
template <typename T>
T* BST<T>::searchValueTree(const T& value) const{
    return searchRecursive(root, value);
}

template <typename T>
T* BST<T>::searchRecursive(typename BST<T>::Node* current, const T& data) const{
    if(!current) return nullptr;
    
    //if we are looking for a value smaller than on the current node, go to the left
    if(data < (current->data)) return searchRecursive(current->left, data);
    //if it is bigger, go to the right subtree
    else if(data > (current->data)) return searchRecursive(current->right, data);

    //otherwise, we have found the value. return its memory address
    return &(current->data);
}

//----------------------get value methods----------------------
template <typename T>
T* BST<T>::getValue(int index) const {
    //if index is negative, over the size of the tree or the tree is empty
    if((index<0) or (index >= size) or (root==nullptr)){
        return nullptr;
    }

    int currentIndex = 0;      //counter for how many nodes have been visited
    T* result = nullptr;     //stores memory address of the value at given index

    //recursively go through the tree, starting at root
    getValueRecursive(root, currentIndex, index, result);
    return result;
}

template <typename T>
void BST<T>::getValueRecursive(typename BST<T>::Node* node, int& currentIndex, int targetIndex, T*& result) const{
    //base case, there is a null node, or we already found the result
    if((node==nullptr) or (result != nullptr)) return;

    //go through the left subtree
    getValueRecursive(node->left, currentIndex, targetIndex, result);

    //if in the current left subtree we found the value's index, exit
    if(result != nullptr) return;

    //otherwise, check if the current node has the "index" that we look for
    if(currentIndex == targetIndex){
        result = &(node->data);     //store its memory address
        return;                     //exit the recursive part
    }
    
    //if we are still looking for the node, increment the counter
    currentIndex++;

    //so far if we have not find it, we are going into the right subtree, with higher values
    getValueRecursive(node->right, currentIndex, targetIndex, result);
}

//----------------------get size methods----------------------
template <typename T>
bool BST<T>::treeIsEmpty() const{
    if(root == nullptr) return true;
    return false;
}

template <typename T>
int BST<T>::getTreeSize() const {
    return size;
}

//----------------------printing methods----------------------
template <typename T>
void BST<T>::printTree() const{
    printByLevelsRecursive(root, 0);    //level 0 is the root of bst
}

template <typename T>
void BST<T>::printByLevels() const{
    //base case: if there is no list, there is no root
    if(!root) return;

    printByLevelsRecursive(root, 0);
    std::cout << "\n";
}

template <typename T>
void BST<T>::printByLevelsRecursive(typename BST<T>::Node* node, int level) const{
    if(!node) return;

    //visist the right subtree, higher values
    printByLevelsRecursive(node->right, level+1);

    //indentation for printing, depending on the depth of each node, a tabulation (4 spaces) is printed
    for (int i=0; i<level; ++i){
        std::cout << "    ";
    }
    //print the actual value
    std::cout << node-> data << "\n";

    //visit the left subtree, lower values
    printByLevelsRecursive(node->left, level+1);
}


/*
Resources used for developing part of the code:
    https://www.youtube.com/watch?v=PVB0KGiS9Jw
    https://www.youtube.com/watch?v=qNWeenanhaw
    https://www.youtube.com/watch?v=0G5cYENDMTI
    https://www.youtube.com/watch?v=DfYjBc_PqcY
    https://muzahid-nafiz.medium.com/problem-solving-in-c-binary-search-tree-bst-079b84a9c011
    https://www.youtube.com/watch?v=zt0EMKtyyLc
*/