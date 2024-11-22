#include "Vector.h"
#include "Voter.h"

Vector::Vector() {
    //Pushes 100 lists into the vector
    for (int i = 0; i < 100; i++) {
        listOfLists.push_back(std::list<Voter>());
    }
}

//Rule of Three
// Vector(const Vector& v);
// auto operator=(const Vector& v);
// ~Vector();

//Functions
void Vector::showImpact() {
    // for (int i = 0; i < 100; i++) {
    //     for (int j = 0; j < listOfLists.at(i).size(); j++) {
    //         cout << 
    //     }
    // }
    int index = 0;
    for (std::list<Voter>& element : listOfLists) {
        for (Voter person : element) {
            cout << element.getName() << "(" << index << "): strength of support: " << element.getSupport() <<", likelihood: "
        }
        index++;
    }
}
