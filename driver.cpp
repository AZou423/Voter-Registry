#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "BST.h"
#include "Heap.h"
#include "Vector.h"
#include "Voter.h"
using namespace std;

vector<string> splitBySpace(string& str) {
    vector<string> output;
    istringstream stream(str);
    string word;

    while (stream >> word) {
        output.push_back(word);
    }

    return output;
}

int main() {
    string input;
    Vector* vec = new Vector();
    BST bst;
    vector<Voter*> in;
    Heap hep(in);
    //Heap constructor
    while (true) {
        getline(cin, input);
        vector<string> words = splitBySpace(input);
        
        if (words.at(0) == "quit") {
            break;
        }
        if (words.at(0) == "voter") {
            Voter* newVoter = new Voter(words.at(2), words.at(1), stoi(words.at(3)));
            //check if voter already exists
            Node* searchResult = bst.search(words.at(2), words.at(1));
            if (searchResult != NULL) {
              //voter already exists
              string firstname = searchResult->getData()->getFirstName();
              string lastname = searchResult->getData()->getLastName();
              int age = searchResult->getData()->getAge();
              cout << "Voter " << firstname << " " << lastname << ", age " << age << ", already exists" << endl;
              continue;
            }
            if ((newVoter->getAge() < 18) || (newVoter->getAge() > 118)) {
                cout << "Voter age should be between 18 and 118" << endl;
            }
            else {   
                vec->insertVoter(newVoter);
                //insert into BST
                Node* newNode = new Node(newVoter);
                newVoter->setBstPtr(newNode);
                bst.insert(newNode);
                //insert into Heap
                hep.insert(newVoter);
                //set pointer and indices for the data structures
                cout << "New voter " << newVoter->getFirstName() << " " << newVoter->getLastName()
                    << ", age " << newVoter->getAge() << ", added" << endl;
            }
        }
        if (words.at(0) == "voted") {
            //traverse through BST to find the name and then remove it from BST and Heap
            Node* searchResult = bst.search(words.at(2), words.at(1));
            if (searchResult == NULL) {
              //voter not found
              continue;
            }
            Voter* voter = searchResult->getData();
            if (voter->getHasVoted() == true) {
              cout << voter->getFirstName() << " " << voter->getLastName() << " already voted" << endl;
              continue;
            }
            cout << "Voter " << voter->getFirstName() << " " << voter->getLastName() << ", age " 
                << voter->getAge() << ", voted" << endl;
            //set hasVoted to true
            voter->setHasVoted();
            //remove from heap using voter's heap index
        }
        if (words.at(0) == "support") {
            //support stuff
            Node* searchResult = bst.search(words.at(2), words.at(1));
            if (searchResult == NULL) {
              //voter not found
              cout << "Voter not found" << endl;
              continue;
            }
            Voter* voter = searchResult->getData();
            if (voter->getHasVoted() == true) {
              cout << voter->getFirstName() << " " << voter->getLastName() << " already voted" << endl;
            }
            // cout << voter->getSupport() << endl; //before changing support
            // cout << hep.getVec().at(0) << endl; // heap before changing
            voter->setSupport(stof(words.at(3)) + voter->getSupport());
            // cout << voter->getSupport() << endl; //after changing support
            voter->calculateImpact();
            // cout << "New impact: " << voter->getImpact() << endl;
            // cout << "Voter index in heap: " << voter->getHeapIndex() << endl;
            hep.percolateUp(voter->getHeapIndex());
            // cout << hep.getVec().at(0) << endl; // heap after changing
            cout << "Support from " << voter->getFirstName() << " " << voter->getLastName() 
                << " increased by " << stof(words.at(3)) << " strength points" << endl;
        }
        if (words.at(0) == "show-impact") {
            vec->showImpact();
        }
        if (words.at(0) == "reduce-likelihood") {
            //reduce-likelihood stuff
            Node* searchResult = bst.search(words.at(2), words.at(1));
            if (searchResult == NULL) {
              //voter not found
              cout << "Voter not found" << endl;
              continue;
            }
            Voter* voter = searchResult->getData();
            if (voter->getHasVoted() == true) {
              cout << voter->getFirstName() << " " << voter->getLastName() << " already voted" << endl;
              continue;
            }
            voter->setLikelihood(voter->getLikelihood() * 0.01 * (100.0 - stof(words.at(3)) ));
            voter->calculateImpact();
            hep.percolateUp(voter->getHeapIndex());
            cout << "Voting likelihood of " << voter->getFirstName() << " " << voter->getLastName() << " decreased by " << stof(words.at(3)) << "%" << endl;
            //use this voter from the bst to get the heap index and reduce likelihood
        }
        if (words.at(0) == "chauffeur") {
            //get voter at root, and remove it from Heap, and set hasVoted to true
            Voter* max = hep.extractMax();
            if(max->getHasVoted() == true){
                max = hep.extractMax();
            }
            else if(max == NULL){
                cout << "No more people to drive" << endl;
            }
            else{
                max->setHasVoted();
                cout << "Driving " << max->getFirstName() << " " << max->getLastName() << "("
                   << max->getAge() << "): strength of support: " << max->getSupport() 
                   << ", likelihood: " << max->getLikelihood() << ", impact: " << max->getImpact() << endl;
            }

            // while (true) {
            //   max = hep.extractMax();
            //   if (!max->getHasVoted() || max == NULL) {
            //     break;
            //   }
            // }
            // if (max == NULL) {
            //   continue;
            // }
            // else {
            //   max->setHasVoted();
            //   cout << "Driving " << max->getFirstName() << " " << max->getLastName() << "("
            //       << max->getAge() << "): strength of support: " << max->getSupport() 
            //       << ", likelihood: " << max->getLikelihood() << ", impact: " << max->getImpact() << endl;
            // }
            //set hasVoted to true
        }
    }

    return 0;
}
