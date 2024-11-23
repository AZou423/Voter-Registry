#include "Voter.h"

Voter::Voter(string firstname, string lastname, unsigned int voterage) {
	first = firstname;
	last = lastname;
	age = voterage;
  heapPtr = NULL;
  bstPtr = NULL;
  vectorIndex = 0;
  support = 75;
  likelihood = .75;
  impact = 100;
  hasVoted = false;
}

Voter::Voter() {
	first = "";
	last = "";
	age = 0;
  heapPtr = NULL;
  bstPtr = NULL;
  vectorIndex = 0;
  support = 0.0;
  likelihood = 0.0;
  impact = 0.0;
  hasVoted = false;
}

void Voter::show() {
	cout << last << ", " << first << ": " << age << endl;
}

bool Voter::operator>(const Voter& v2) const {
  Voter v1 = *this;
  if (v1.last > v2.last) {
    return true;
  }
  if (v1.last < v2.last) {
    return false;
  }
  if (v1.first > v2.first) {
    return true;
  }
  if (v1.first < v2.first) {
    return false;
  }
  if (v1.age > v2.age) {
    return false;
  }
  return true;
}

bool Voter::operator==(const Voter& v2) const {
  Voter v1 = *this;
  if (v1.last != v2.last) {
    return false;
  }
  if (v1.first != v2.first) {
    return false;
  }
  return v1.age == v2.age;
}

bool Voter::operator<(const Voter& v2) const {
  Voter v1 = *this;
  if (v1.last > v2.last) {
    return false;
  }
  if (v1.last < v2.last) {
    return true;
  }
  if (v1.first > v2.first) {
    return false;
  }
  if (v1.first < v2.first) {
    return true;
  }
  if (v1.age < v2.age) {
    return false;
  }
  return true;
}

Node* Voter::getHeapPtr() {
  return heapPtr;
}

Node* Voter::getBstPtr() {
  return bstPtr;
}

int Voter::getVectorIndex() {
  return vectorIndex;
}

int Voter::getAge() {
  return age;
}

float Voter::getSupport() {
  return support;
}

float Voter::getLikelihood() {
  return likelihood;
}

float Voter::getImpact() {
  return impact;
}

bool Voter::getHasVoted() {
  return hasVoted;
}

void Voter::setHeapPtr(Node* newHeapPtr) {
  heapPtr = newHeapPtr;
}

void Voter::setBstPtr(Node* newBstPtr) {
  bstPtr = newBstPtr;
}

void Voter::setVectorIndex(int newVectorIndex) {
  vectorIndex = newVectorIndex;
}

void Voter::setSupport(float newSupport) {
  support = newSupport;
}

void Voter::setLikelihood(float newLikelihood) {
  likelihood = newLikelihood;
}

void Voter::calculateImpact() {
  impact = support / likelihood;
}

void Voter::setHasVoted() {
  hasVoted = true;
}
