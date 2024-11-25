#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Voter.h"

class Heap{
    private:
        void heapify(vector<Voter*> vec); //called on vector to turn vector into heap
        vector<Voter*> voterVector;
    public:
        Heap(const vector<Voter*>& vec);
        vector<Voter*> getVec();
        Voter* extractMax(); //returns voter with greatest impact and reheapify
        void insert(Voter* v); //has to handle resizing vector
        void percolateDown(int nodeIndex, vector<Voter*> vec); //helper function for remove
        void percolateUp(int nodeIndex, vector<Voter*> vec); //Helper function for insert
};

#endif