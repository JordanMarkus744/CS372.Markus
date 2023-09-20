#include "Question1.hpp"
#include <iostream>

int main(){
    SelfAdjustingList<int> myList;
    myList.push_back(50);
    myList.push_back(20);
    myList.push_back(10);
    myList.push_back(23);
    myList.push_back(84);
    int* found = myList.find(23);
    if (found != nullptr) {
        std::cout << "Found and moved: " << *found << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}