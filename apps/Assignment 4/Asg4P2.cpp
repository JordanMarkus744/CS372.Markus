#include "DerivedArray.hpp"
#include "DerivedVector.hpp"
#include <iostream>

int main() {
    // Testing Array class and vector class
    Array<int> arr(5);
    vector<int> vec;
    // Fill the array with values
    for (int i = 0; i < 5; ++i) {
        arr.insert(arr.begin() + i, i);
    }

    std::cout << "Array elements:" << std::endl;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Fill the vector with values
    for (int i = 0; i < 5; ++i) {
        vec.push_back(i);
    }

    std::cout << "Vector elements:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Testing insert method in vector
    vec.insert(vec.begin() + 2, 10); // Insert 10 at index 2

    std::cout << "Vector elements after insert:" << std::endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}