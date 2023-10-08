#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <time.h>
#include <chrono>
#include <cmath>
#include "Tree.hpp"

struct MyStructure {
    size_t size;
    std::unique_ptr<std::vector<int>> intVector;
    std::shared_ptr<Tree<int>> binarySearchTree;
};

// Function to create and initialize the structure
std::unique_ptr<MyStructure> createAndInitializeStructure(size_t numItems) {
    auto myStruct = std::make_unique<MyStructure>();
    myStruct->size = numItems;
    myStruct->intVector = std::make_unique<std::vector<int>>();
    myStruct->binarySearchTree = std::make_shared<Tree<int>>(); 

    // Fill the vector with random integers
    std::srand(time(NULL));

    for (size_t i = 0; i < numItems; ++i) {
        int randomValue = rand() % 1000;
        myStruct->intVector->push_back(randomValue);
    }

    // Sort the vector
    std::sort(myStruct->intVector->begin(), myStruct->intVector->end());

    // Insert sorted integers into the binary search tree
    for (int value : *(myStruct->intVector)) {
        myStruct->binarySearchTree->addLeaf(value);
    }

    return myStruct;
}

int main() {
    size_t numItems = 1000; // Change this as needed

    auto myStruct = createAndInitializeStructure(numItems);


    myStruct->binarySearchTree->Traverse();


    return 0;
}

