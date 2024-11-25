#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

Node::Node(Voter* voterPtr){
    voter = voterPtr;
    left = nullptr;
    right = nullptr;
}

Node::~Node(){
    delete left;
    delete right;
}

void Node::setLeft(Node* node) {
    left = node;
}

void Node::setRight(Node* node) {
    right = node;
}

void Node::setData(const Voter& v) {
    voter = v;
}

Node* Node::getLeft() {
    return left;
}

Node* Node::getRight() {
    return right;
}

Voter* Node::getData() {
  return voter;
}
