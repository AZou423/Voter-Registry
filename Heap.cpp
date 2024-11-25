#include <vector>
#include "Heap.h"

Heap::Heap(const vector<Voter*>& vec){
    voterVector = vec;
    heapify(voterVector);
}

void Heap::percolateDown(int nodeIndex, vector<Voter*> vec){
    int leftChildIndex = (nodeIndex * 2) + 1;
    int rightChildIndex = (nodeIndex * 2) + 2;
    int largest = nodeIndex;

    if(leftChildIndex < static_cast<int>(vec.size()) && vec.at(largest)->getImpact() < vec.at(leftChildIndex)->getImpact()){
        largest = leftChildIndex;
    }
    if(rightChildIndex < static_cast<int>(vec.size()) && vec.at(largest)->getImpact() < vec.at(rightChildIndex)->getImpact()){
        largest = rightChildIndex;
    }
    if(largest != nodeIndex){
        swap(largest, nodeIndex);
        voterVector.at(largest)->setHeapIndex(largest); //this line and next ensures maintenence of heapIndex of individual Voter
        voterVector.at(nodeIndex)->setHeapIndex(nodeIndex);
        percolateDown(largest, vec);
    }
}

void Heap::percolateUp(int nodeIndex, vector<Voter*> vec){
    int parent = (nodeIndex - 1) * 2;
    int largest = parent;

    if(parent >= 0 && vec.at(parent)->getImpact() < vec.at(nodeIndex)->getImpact()){
        largest = nodeIndex;
    }
    if(largest != parent){
        swap(largest, nodeIndex);
        voterVector.at(largest)->setHeapIndex(largest); //this line and next ensures maintenence of heapIndex of individual Voter
        voterVector.at(nodeIndex)->setHeapIndex(nodeIndex);
        percolateUp(largest, vec);
    }
}

void Heap::heapify(vector<Voter*> vec){
    for (int i = (vec.size() / 2) - 1; i >= 0; i--) {
        percolateDown(i, vec);
    }
}

Voter* Heap::extractMax(){
    if(voterVector.empty()){
        cout << "Empty heap" << endl;
        return NULL;
    }

    Voter* max = voterVector.at(0); //save the Voter with greatest impact
    voterVector.at(0) = voterVector.back(); //replace root with last node
    voterVector.pop_back();

    if(!voterVector.empty()){
        percolateDown(0, voterVector);
    }
    
    return max;
}

void Heap::insert(Voter* v){
    voterVector.push_back(v);
    voterVector.at(0)->setHeapIndex(0);
    percolateUp(voterVector.size() - 1, voterVector);
}

