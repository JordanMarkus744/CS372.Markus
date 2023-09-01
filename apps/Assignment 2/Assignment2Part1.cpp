#include "Vector.hpp"
#include <iostream>
int main(){
    vector<int> test = vector<int>();
    const int SIZE = 100;
    std::cout << "Capacity: " << test.capacity() << std::endl;
    std::cout << "Size: " << test.size() << "\nPushing Elements into vector..." << std::endl;

    for (int i = 0; i <= SIZE; ++i){
        test.push_back(i);
    }
    test.traverse();
    std::cout << "Copying test into test2..." << std::endl;
    vector<int> test2 = test;
    test2.traverse();

    if (test == test2){
        std::cout << "\n\nTest 1 is equivalent to Test 2" << std::endl;
    }
    else{
        std::cout << "\n\nTest 1 is not equvalent to Test 2" << std::endl;
    }
    
    std::cout << test.at(5) << std::endl;

    test.put(1005, 5);

    for (int i = 0; i <= SIZE; i++){
        std::cout << test[i] << ", ";
    }
    std::cout << "\n\n\n";

    std::cout << "Capacity: " << test.capacity() << std::endl;
    std::cout << "Size: " << test.size() << "\nPushing Elements into vector..." << std::endl;

    return 0;
}