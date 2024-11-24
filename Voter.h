#ifndef _H_Voter_
#define _H_Voter_

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Node.h"
using namespace std;

class Voter {
   private:
      string first;
      string last;
      unsigned int age;
      Node* heapPtr;
      Node* bstPtr;
      int vectorIndex;
      float support;
      float likelihood;
      float impact;
      bool hasVoted;
   public:
      Voter(string firstname, string lastname, unsigned int voterage);
      Voter();
      void show();
      //auto operator<=>(const Voter &other) const = default;
      friend ostream& operator<<(ostream& os, const Voter& voter);
      bool operator>(const Voter& v2) const;
      bool operator<(const Voter& v2) const;
      bool operator==(const Voter& v2) const;
      Node* getHeapPtr();
      Node* getBstPtr();
      int getVectorIndex();
      string getName(); //added this so we can access full name (needs to be first and last) of Voter node for BST insert and find
      int getAge(); //added to use in vector implementation
      float getSupport();
      float getLikelihood();
      float getImpact();
      bool getHasVoted();
      void setHeapPtr(Node* newHeapPtr);
      void setBstPtr(Node* newBstPtr);
      void setVectorIndex(int newVectorIndex);
      void setSupport(float newSupport);
      void setLikelihood(float newLikelihood);
      void calculateImpact();
      void setHasVoted();
};

#endif
