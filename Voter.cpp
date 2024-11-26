#include "Voter.h"

Voter::Voter(string firstname, string lastname, unsigned int voterage) {
	first = firstname;
	last = lastname;
	age = voterage;
    heapIndex = 0;
    bstPtr = NULL;
    vectorIndex = age - 18;
    support = 75;
    likelihood = 75.0;
    impact = 1.0;
    hasVoted = false;
}

Voter::Voter() {
    first = "";
	last = "";
	age = 0;
    heapIndex = 0;
    bstPtr = NULL;
    vectorIndex = age - 18;
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

int Voter::getHeapIndex() {
  return heapIndex;
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

string Voter::getFirstName() {
  return first;
}

string Voter::getLastName() {
  return last;
}

void Voter::setHeapIndex(int newHeapIndex) {
  heapIndex = newHeapIndex;
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
