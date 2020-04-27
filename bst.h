// bst.h
// Binary search tree header file for CS 130A lab

#ifndef BST_H
#define BST_H

#include <iostream>

using namespace std;

class BST {
public:
    
    //constructor
    BST();
    
    // destructor
    ~BST();
    
    //insert
    void bstInsert(std::string name);     // insert value; return false if duplicate
    
    //insert(no cout)
    void bstInsert2(std::string name);

    //search (contains)
    void bstSearch(std::string name) const;

    //delete
    void bstDelete(std::string name);
    
    //void bstRangeSearch();
    void bstRangeSearch(string begin, string end);
    
    void printInOrder() const;   

    string getPredecessor(string name) const;       // returns the predecessor value of the given value or 0 if there is none
    string getSuccessor(string name) const; 
private:
struct Node {
	std::pair<std::string, int> word;
	Node *left, *right, * parent;
	// useful constructor:
    Node(string s="") :  left(0), right(0), parent(0) { 
        word.first=s;
        }
    };

    // just one instance variable (pointer to root node):
    Node *root;

    // recursive utility functions for use by public methods above
    
    Node* getNodeFor(string name, Node* n) const; // IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
    void clear(Node *n); // for destructor
    void insert(string name, Node *n); // note overloading names for simplicity
   
    void insert2(string name, Node *n);

    void printInOrder(Node *n) const;
    void printRangeSearch(Node* n,  string begin, string end) const;
    
    //void printPreOrder(Node *n) const;
    //void printPostOrder(Node *n) const;
    //int sum(Node *n) const;
    //int count(Node *n) const;

    // these should be used by getPredecessor and getSuccessor, and ONE of them should be used by remove
    Node* getSuccessorNode(string value) const;   // returns the Node containing the successor of the given value
    Node* getPredecessorNode(string value) const; // returns the Node containing the predecessor of the given value i
};
#endif
