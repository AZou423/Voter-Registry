#include "Vector.h"
#include "Voter.h"

Vector::Vector() {
    //Pushes 100 lists into the vector
    for (int i = 0; i < 100; i++) {
        listOfLists.push_back(list<Voter*>());
    }
}

//Rule of Three
// Vector(const Vector& v);
// auto operator=(const Vector& v);
// ~Vector();

//Functions
void Vector::insertVoter(Voter* newVoter) {
    int age = newVoter->getAge();
    listOfLists[age - 18].push_back(newVoter);
}

void Vector::showImpact() {
    int index = 0;
    for (list<Voter*>& element : listOfLists) {
        for (Voter* person : element) {
            if (!(person->getHasVoted())) {
                cout << person->getFirstName() << " " << person->getLastName() << "(" 
                    << person->getAge() << "): strength of support: " 
                    << person->getSupport() <<", likelihood: " << person->getLikelihood()
                    << ", impact: " << person->getImpact() << endl;
            }
        }
        index++;
    }
}
