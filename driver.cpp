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
    //BST constructor
    //Heap constructor
    while (cin >> input) {
        getline(cin, input);
        vector<string> words = splitBySpace(input);

        if (words.at(0) == "voter") {
            Voter* newVoter = new Voter(words.at(2), words.at(1), stoi(words.at(3)));
            //check if voter already exists

        }
    }

    return 0;
}