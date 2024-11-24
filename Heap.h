#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Voter.h"

class Heap{
    private:
        void swap(int a, int b); //helper function for build heap
        void percolateDown(int nodeIndex, vector<Voter> vec, int vecSize); //helper function for remove
        void percolateUp(int nodeIndex, vector<Voter> vec); //Helper function for insert
        void heapify(); //called on heap object to turn vector into heap
        vector<Voter> voterVector;
        int size;
        int capacity;
        bool empty;
    public:
        Heap(vector<Voter> vec);
        Node* extractMax(); //returns voter with greatest impact and reheapify
        void insert(Voter v); //should check if 
};

#endif HEAP_H