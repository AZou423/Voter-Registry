#include <iostream>
#include <stdlib.h>
#include <string>
#include "Node.h"
#include "Voter.h"
using namespace std;

BST::BST() {
  root = NULL;
}

BST::BST(Node* newRoot) {
  root = newRoot;
}

BST::~BST() {
  delete root;
}

void BST::insert(Node* newNode) {
  if (root == NULL) {
    root = newNode;
    return;
  }
  Node* current = root;
  string insertFullName = newNode->getData().getFirst() + newNode->getData().getLast();
  while (current != NULL) {
    string currentFullName = current->getData().getFirst() + current->getData().getLast();
    if (currentFullName < insertFullName) { //compare names
      if (current->getRight() == NULL) {
        current->setRight(newNode);
        return;
      }
      else {
        current = current->getRight();
      }
    }
    else {
      if (current->getLeft() == NULL) {
        current->setLeft(newNode);
        return;
      }
      else {
        current = current->getLeft();
      }
    }
  }
}

/*
Node* BST::search(Voter voter) {
  Node current = root;
  while (current != NULL) {
    if (current == voter) {
      return &current;
    }
    if (current < voter) {
      current = current.getRight();
    }
    else {
      current = current.getLeft();
    }
  }
  return NULL;
}*/

Node* BST::search(string firstName, string lastName) {
  string targetFullName = firstName + lastName;
  Node* current = root;
  while (current != NULL) {
    string currentFullName = current->getData().getFirst() + current->getData().getLast();
    if (targetFullName == currentFullName) {
      return current;
    }
    if (currentFullName < targetFullName) {
      current = current->getRight();
    }
    else {
      current = current->getLeft();
    }
  }
  return NULL;
}


void BST::remove(Voter voter) {
  Node targetParent = NULL;
  Node target = root;
  while (target != NULL && target.getData() != voter) {
    targetParent = target;
    if (voter < target.getData()) {
      target = target.getLeft();
    }
    else {
      target = target.getRight();
    }
  }
  if (target == NULL) {
    return;
  }

  //case where target is a leaf node
  if (target.getLeft() == NULL && target.getRight() == NULL) {
    if (targetParent == NULL) {//target is also root of bst
      root == NULL;
    }
    else if (targetParent.getRight() == target) {
      targetParent.setRight(NULL);
    }
    else {
      targetParent.setLeft(NULL);
    }
    delete target;
  }

  //case where target has 2 children
  if (target.getRight() != NULL && target.getLeft() != NULL) {
    Node leftmostParent = target;
    Node leftmost = target.getRight();
    while (leftmost.getLeft() != NULL) {
      leftmostParent = leftmost;
      leftmost = leftmost.getLeft();
    }
    target.setData(leftmost.getData()); //replace the target with next smallest value
    if (leftmostParent.getLeft() == leftmost) {
      leftmostParent.setLeft(leftmost.getRight());
    }
    else {
      leftmostParent.setRight(leftmost.getRight());
    }
    delete leftmost;
  }
  else {//target has 1 children
    Node targetChild = NULL;
    if (target.getRight() != NULL) {
      targetChild = target.getRight();
    }
    else {
      targetChild = target.getLeft();
    }
    if (targetParent == NULL) {
      root = targetChild;
    }
    else if (targetParent.getLeft() == target) {
      targetParent.setLeft(targetChild);
    }
    else {
      targetParent.setRight(targetChild);
    }
    delete target;
  }
}

void BST::traverseInOrder(Node* n) {
  if (n == NULL) {
    return;
  }
  traverseInOrder(n->getLeft());
  //visit by printing
  traverseInOrder(n->getRight());
}
