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
   public:
      Voter(string firstname, string lastname, unsigned int voterage);
      Voter();
      void show();
      //auto operator<=>(const Voter &other) const = default;
      friend ostream& operator<<(ostream& os, const Voter& voter);
      bool operator>(const Voter& v2) const;
      bool operator<(const Voter& v2) const;
      bool operator==(const Voter& v2) const; 
};

#endif
