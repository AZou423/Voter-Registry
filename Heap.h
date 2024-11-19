#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include "Voter.h"

class Heap{
    private:
        void swap(int a, int b);
        void percolateDown(int nodeIndex, vector<Voter> vec, int vecSize);
        void percolateUp(int nodeIndex, vector<Voter> vec);
        void heapify(int i);
};

#endif HEAP_H