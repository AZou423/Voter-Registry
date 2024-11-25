#ifndef _H_BST_
#define _H_BST_

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Node.h"
using namespace std;

class BST {
  private:
    Node* root;
  public:
    BST();
    BST(Node* newRoot);
    ~BST();
    void insert(Node* newNode);
    Node* search(string firstName, string lastName);
    void remove(Voter voter);
    Node* getRoot();
    void traverseInOrder(Node* n);
    void traversePreOrder(Node* n);
};

#endif
