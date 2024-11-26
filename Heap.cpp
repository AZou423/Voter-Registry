#include <vector>
#include "Heap.h"

Heap::Heap(const vector<Voter*>& vec){
    voterVector = vec;
    heapify();
}

vector<Voter*> Heap::getVec() {
    return voterVector;
}

void Heap::percolateDown(int nodeIndex){
    int leftChildIndex = (nodeIndex * 2) + 1;
    int rightChildIndex = (nodeIndex * 2) + 2;
    int largest = nodeIndex;

    if(leftChildIndex < static_cast<int>(voterVector.size()) && voterVector.at(largest)->getImpact() < voterVector.at(leftChildIndex)->getImpact()){
        largest = leftChildIndex;
    }
    if(rightChildIndex < static_cast<int>(voterVector.size()) && voterVector.at(largest)->getImpact() < voterVector.at(rightChildIndex)->getImpact()){
        largest = rightChildIndex;
    }
    if(largest != nodeIndex){
        swap(voterVector.at(largest), voterVector.at(nodeIndex));
        voterVector.at(largest)->setHeapIndex(largest); //this line and next ensures maintenence of heapIndex of individual Voter
        voterVector.at(nodeIndex)->setHeapIndex(nodeIndex);
        percolateDown(largest);
    }
}

void Heap::percolateUp(int nodeIndex) {
    while (nodeIndex > 0) {  
        int parent = (int)(nodeIndex - 1) / 2;
        // cout << "Percolate time" << endl;
        if (voterVector.at(parent)->getImpact() < voterVector.at(nodeIndex)->getImpact()) {
            swap(voterVector.at(parent), voterVector.at(nodeIndex));
            // cout << "Swap made between " << voterVector.at(parent)->getLastName()<< " and " << voterVector.at(nodeIndex)->getLastName() << endl;
            voterVector.at(parent)->setHeapIndex(parent);
            voterVector.at(nodeIndex)->setHeapIndex(nodeIndex);
            nodeIndex = parent;  // Continue to percolate up from the new position
        } else {
            break;  // Stop percolating if the current node's impact is less than parent's
        }
    }
}


void Heap::heapify(){
    for (int i = (voterVector.size() / 2) - 1; i >= 0; i--) {
        percolateDown(i);
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
        percolateDown(0);
    }
    
    return max;
}

void Heap::insert(Voter* v){
    voterVector.push_back(v);
    voterVector.back()->setHeapIndex(voterVector.size()-1);
    percolateUp(voterVector.size() - 1);
}

