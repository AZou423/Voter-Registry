#include "Node.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

Node::Node(const Voter& v){
    data = v;
    left = nullptr;
    right = nullptr;
}

Node::~Node(){
    delete left;
    delete right;
}

void Node::setLeft(Node* left) {
    this.left = left;
}

void Node::setRight(Node* right) {
    this.right = right;
}

void Node::setData(const Voter& v) {
    this.data = v;
}

Node* Node::getLeft() {
    return left;
}

Node* Node::getRight() {
    return right;
}

Voter Node::getData() {
  return data;
}
