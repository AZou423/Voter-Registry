#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

Node::Node(const Voter& v){
    voter = v;
    left = nullptr;
    right = nullptr;
}

Node::~Node(){
    delete left;
    delete right;
}


