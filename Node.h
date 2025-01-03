#ifndef _Node_
#define _Node_
#include "Voter.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Voter;

class Node{
    private:
        Node* left;
        Node* right;
        Voter* voter;

    public:
        Node(Voter* voterPtr);
        ~Node();
        void setLeft(Node* left);
        void setRight(Node* right);
        void setData(Voter* voterPtr);
        Node* getLeft();
        Node* getRight();
        Voter* getData();
};

#endif //_Node_
