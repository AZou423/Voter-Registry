#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Voter.h"

class Heap{
    private:
        void heapify(); //called on vector to turn vector into heap
        vector<Voter*> voterVector;
    public:
        Heap(const vector<Voter*>& vec);
        vector<Voter*> getVec();
        Voter* extractMax(); //returns voter with greatest impact and reheapify
        void insert(Voter* v); //has to handle resizing vector
        void percolateDown(int nodeIndex); //helper function for remove
        void percolateUp(int nodeIndex); //Helper function for insert
};

#endif