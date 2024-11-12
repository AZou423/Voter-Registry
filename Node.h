#ifndef _Node_
#define _Node_
#include "Voter.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Node{
    private:
        Node* parent;
        Node* left;
        Node* right;
        Voter data;
        
}

#endif _Node_