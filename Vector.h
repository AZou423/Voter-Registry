#ifndef _Vector_
#define _Vector_
#include "Voter.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Vector{
    private:
        vector<list<Voter*>> listOfLists; //vector of lists

    public:
        Vector(); //default constructor

        //Rule of Three
        // Vector(const Vector& v);
        // auto operator=(const Vector& v);
        // ~Vector();

        //Functions
        void insertVoter(Voter* newVoter);
        void showImpact();
};

#endif
