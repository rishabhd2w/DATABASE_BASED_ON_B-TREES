#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
 
   public:
    bool isLeaf;
    vector<int> keys;
 
    Node* ptr2next;               
    union ptr {                  
        vector<Node*> ptr2Tree;  
        vector<FILE*> dataPtr;   

        ptr();  
        ~ptr(); 
    } ptr2TreeOrData;

    friend class BPTree;   
   public:
    Node();
};

class BPTree {
    
   private:
    int maxIntChildLimit;                                  
    int maxLeafNodeLimit;                               
    Node* root;                                            
    void insertInternal(int x, Node** cursor, Node** child);   
    Node** findParent(Node* cursor, Node* child);
    Node* firstLeftNode(Node* cursor);

   public:
    BPTree();
    BPTree(int degreeInternal, int degreeLeaf);
    Node* getRoot();
    int getMaxIntChildLimit();
    int getMaxLeafNodeLimit();
    void setRoot(Node *);
    void display(Node* cursor);
    void seqDisplay(Node* cursor);
    void search(int key);
    void insert(int key, FILE* filePtr);
    void removeKey(int key);
    void removeInternal(int x, Node* cursor, Node* child);
};

#endif