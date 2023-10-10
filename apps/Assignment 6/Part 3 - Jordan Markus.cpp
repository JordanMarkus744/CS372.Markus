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
std::shared_ptr<MyStructure> createAndInitializeStructure(size_t numItems) {
    auto myStruct = std::make_unique<MyStructure>();
    myStruct->size = numItems;
    myStruct->intVector = std::make_unique<std::vector<int>>();
    myStruct->binarySearchTree = std::make_shared<Tree<int>>(); 

    // Fill the vector with random integers
    //std::srand(time(NULL));

    for (int i = 0; i < numItems; ++i) {
        //int randomValue = rand() % 2500;
        myStruct->intVector->push_back(i);
    }

    // Sort the vector
    std::sort(myStruct->intVector->begin(), myStruct->intVector->end());

    // Insert sorted integers into the binary search tree
    for (int value : *(myStruct->intVector)) {
        myStruct->binarySearchTree->addLeaf(value);
    }

    return myStruct;
}

template <typename T>
bool binarySearch(const std::vector<T>& aSortedVector, T itemToBeFound, bool printDebugData = false){


    int count = 1;
    int low = 0;
    int high = aSortedVector.size() - 1;
    int mid = low + (high - low)/2; 

    while(aSortedVector[mid] != itemToBeFound || mid != static_cast<int>(aSortedVector.size()-1)){ 
        if (count > aSortedVector.size()){
            break;
        }
        if (itemToBeFound < aSortedVector[mid]){
            high = mid;
        }
        else if (itemToBeFound > aSortedVector[mid]){
            low = mid;
        }
        else{ // if aSortedVector[mid] == itemToBeFound
            break;
        }

        count++;
        mid = low + (high - low) / 2;
    }

    if (aSortedVector[mid] == itemToBeFound){ // We found the target
        if (printDebugData){
            std::cout << "Searched " << count << " items to find " << aSortedVector[mid] << " at index " << mid << std::endl;
            return true;
        }
        //std::cout << "Found " << aSortedVector[mid] << " at index " << mid << std::endl;
        return true;        
    }
    
    // We don't need an else here because if we found the data in the vector, then it'll return anyway and this code will not be ran.

    if (printDebugData){
        std::cout << "Searched " << count << " items and couldn't find the item in the vector." << std::endl;
        return false;
    }

    //std::cout << "Couldn't find item in vector." << std::endl;
    return false;
    
}

int main() {
    std::chrono::time_point<std::chrono::system_clock> start, end, start2, end2;
    std::vector<size_t> numItemsList = {1000, 2500, 5000, 10000, 50000};
    std::vector<int> randomNumbers;

    std::srand(time(NULL));

    for (int i = 0; i < 100; i++){ // Generates 100 random numbers
        randomNumbers.push_back(rand() % 1000);
    }

    

    for (size_t numItems : numItemsList){
        auto myStruct = createAndInitializeStructure(numItems);
        double avgArraySearchTime = 0.0;
        double avgTreeSearchTime = 0.0;
        for(int randnum : randomNumbers){
            // Measure array search time
            start = std::chrono::system_clock::now();
            auto resultArray = binarySearch(*myStruct->intVector, randnum, false);
            end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds_array = end - start;
            avgArraySearchTime += elapsed_seconds_array.count();

            // Measure tree search time
            start = std::chrono::system_clock::now();
            myStruct->binarySearchTree->SearchTree(myStruct->binarySearchTree, randnum);
            end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds_tree = end - start;
            avgTreeSearchTime += elapsed_seconds_tree.count();        
        }
        avgArraySearchTime /= 100.0;
        avgTreeSearchTime /= 100.0;
        std::cout << "For " << numItems << " elements:" << std::endl;
        std::cout << "Average Array Search Time: " << avgArraySearchTime << " seconds" << std::endl;
        std::cout << "Average Tree Search Time: " << avgTreeSearchTime << " seconds" << std::endl;
        std::cout << std::endl;
    }

        
    
    return 0;
}

