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
    void insert(Node* newNode);
    Node* search(Voter voter);
    void remove(Node* node);
    void traverseInOrder(Node* n);
};

#endif _H_BST_
