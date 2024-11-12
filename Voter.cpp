#include "Voter.h"

Voter::Voter(string firstname, string lastname, unsigned int voterage) {
	first = firstname;
	last = lastname;
	age = voterage;
}

Voter::Voter() {
	first = "";
	last = "";
	age = 0;
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
