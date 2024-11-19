#include <iostream>
#include <stdlib.h>
#include <string>
#include "Node.h"
#include "Voter.h"
using namespace std;



void BST::insert(Node* newNode) {
  if (root == NULL) {
    root = newNode;
    return;
  }
  Node current = root
  while (current != NULL) {
    if (current.getData() < newNode.getData()) { //compare names
      if (current.getRight() == NULL) {
        current.setRight(newNode);
      }
      else {
        current = current.getRight();
      }
    }
    else {
      if (current.getLeft() == NULL) {
        current.setLeft(newNode);
      }
      else {
        current = current.getLeft();
      }
    }
  }
}

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
}

void BST::remove(Voter voter) {
  //get parent of target and target, 
  Node targetParent = root;
  if (targetParent != NULL && targetParent.getData() == voter) {
    //case where root is the target
  }
  while (targetParent != NULL) { //find the parent of the target
    if (targetParent.getRight() != NULL && targetParent.getRight().getData() == voter) {
      break;
    }
    if (targetParent.getLeft() != NULL && targetParent.getLeft().getData() == voter) {
      break;
    }
  } 
  if (targetParent != NULL) {
    Node target = NULL;
    if (targetParent.getRight() != NULL && targetParent.getRight().getData() == voter) {
      target = targetParent.getRight();
    }
    else if (targetParent.getLeft() != NULL && targetParent.getLeft().getData() == voter) {
      target = targetParent.getLeft();
    }
    //get the leftmost of the right subtree of target
    Node leftmostParent = target.getRight();
    while (leftmostParent != NULL && leftmostParent.getLeft() != NULL && leftmostParent.getLeft().getLeft() != NULL) {
      leftmostParent = leftmostParent.getLeft();
    }
    if (leftmostParent == NULL) {

    }
  }
  return;
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

