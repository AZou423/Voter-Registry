#ifndef _Node_
#define _Node_
#include "Voter.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Node{
    private:
        Node* left;
        Node* right;
        Voter data;

    public:
        Node(const Voter& v);
        ~Node();
};

#endif _Node_