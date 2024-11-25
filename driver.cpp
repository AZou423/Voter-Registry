#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
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
    BST bst = new BST();
    //Heap constructor
    while (cin >> input) {
        getline(cin, input);
        vector<string> words = splitBySpace(input);
        
        if (words.at(0) == "quit") {
            break;
        }
        if (words.at(0) == "voter") {
            Voter* newVoter = new Voter(words.at(2), words.at(1), stoi(words.at(3)));
            //check if voter already exists
            Node* searchResult = bst.search(words.at(1), words.at(2));
            if (searchResult != NULL) {
              //voter already exists
            }
            vec->insertVoter(newVoter);
            //insert into BST
            Node* newNode = new Node(&newVoter);
            newVoter->setBstPtr(newNode);
            bst.insert(newNode)
            //insert into Heap
            //set pointer and indices for the data structures
        }
        if (words.at(0) == "voted") {
            //traverse through BST to find the name and then remove it from BST and Heap
            //set hasVoted to true
        }
        if (words.at(0) == "support") {
            //support stuff
        }
        if (words.at(0) == "show-impact") {
            vec->showImpact();
        }
        if (words.at(0) == "reduce-likelihood") {
            //reduce-likelihood stuff
        }
        if (words.at(0) == "chauffeur") {
            //get voter at root, and remove it from BST and Heap, and set hasVoted to true
            //set hasVoted to true
        }
    }

    return 0;
}
