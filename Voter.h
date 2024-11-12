#ifndef _H_Voter_
#define _H_Voter_

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Voter {
   private:
      string first = "";
      string last = "";
      unsigned int age = 0;
      Node* heapPtr = NULL;
      Node* bstPtr = NULL;
      int vectorIndex = 0;
      float strength;
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
      float getStrength();
      float getLikelihood();
      float getImpact();
      bool getHasVoted();
      void setHeapPtr(Node* newHeapPtr);
      void setBstPtr(Node* newBstPtr);
      void setVectorIndex(int newVectorIndex);
      void setStrength(float newStrength);
      void setLikelihood(float newLikelihood);
      void calculateImpact();
      void setHasVoted();
};

#endif
