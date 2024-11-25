#include <iostream>
#include <stdlib.h>
#include <string>
#include "BST.h"
#include "Voter.h"
#include "BST.h"
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
  string insertFullName = newNode->getData()->getFirstName() + newNode->getData()->getLastName();
  while (current != NULL) {
    string currentFullName = current->getData()->getFirstName() + current->getData()->getLastName();
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
    string currentFullName = current->getData()->getFirstName() + current->getData()->getLastName();
    cout << "target: " << targetFullName << " current: " << currentFullName << endl;
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
  Node* targetParent = NULL;
  Node* target = root;
  string removeFullName = voter.getFirstName() + voter.getLastName();
  while (target != NULL && (target->getData()->getFirstName() != voter.getFirstName() || target->getData()->getLastName() != voter.getLastName())) {
    targetParent = target;
    if (removeFullName < (target->getData()->getFirstName() + target->getData()->getLastName())) {
      target = target->getLeft();
    }
    else {
      target = target->getRight();
    }
  }
  if (target == NULL) {
    return;
  }

  //case where target is a leaf node
  if (target->getLeft() == NULL && target->getRight() == NULL) {
    if (targetParent == NULL) {//target is also root of bst
      root = NULL;
    }
    else if (targetParent->getRight() == target) {
      targetParent->setRight(NULL);
    }
    else {
      targetParent->setLeft(NULL);
    }
    delete target;
  }

  //case where target has 2 children
  if (target->getRight() != NULL && target->getLeft() != NULL) {
    Node* leftmostParent = target;
    Node* leftmost = target->getRight();
    while (leftmost->getLeft() != NULL) {
      leftmostParent = leftmost;
      leftmost = leftmost->getLeft();
    }
    target->setData(leftmost->getData()); //replace the target with next smallest value
    if (leftmostParent->getLeft() == leftmost) {
      leftmostParent->setLeft(leftmost->getRight());
    }
    else {
      leftmostParent->setRight(leftmost->getRight());
    }
    delete leftmost;
  }
  else {//target has 1 children
    Node* targetChild = NULL;
    if (target->getRight() != NULL) {
      targetChild = target->getRight();
    }
    else {
      targetChild = target->getLeft();
    }
    if (targetParent == NULL) {
      root = targetChild;
    }
    else if (targetParent->getLeft() == target) {
      targetParent->setLeft(targetChild);
    }
    else {
      targetParent->setRight(targetChild);
    }
    delete target;
  }
}

Node* BST::getRoot() {
  return root;
}

void BST::traverseInOrder(Node* n) {
  if (n == NULL) {
    return;
  }
  traverseInOrder(n->getLeft());
  //visit by printing
  cout << n << endl;
  cout << n->getData()->getFirstName() << " " << n->getData()->getLastName() << " " << n->getData()->getAge() << endl;
  cout << "left: " << n->getLeft() << " right: " << n->getRight() << endl;
  cout << endl;
  traverseInOrder(n->getRight());
}

void BST::traversePreOrder(Node* n) {
  if (n == NULL) {
    return;
  } 
  //visit by printing
  cout << n << endl;
  cout << n->getData()->getFirstName() << " " << n->getData()->getLastName() << " " << n->getData()->getAge() << endl;
  cout << "left: " << n->getLeft() << " right: " << n->getRight() << endl;
  cout << endl;
  traversePreOrder(n->getLeft());
  traversePreOrder(n->getRight());
}
