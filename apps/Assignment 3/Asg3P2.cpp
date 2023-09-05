#include "Bag.hpp"
#include <iostream>


int main(){
    Bag<int> myBag;
    myBag.pop();
    myBag.insert(5);
    myBag.insert(10);
    std::cout << myBag.size() << std::endl;
    myBag.pop();
    std::cout << myBag.size() << std::endl;
    return 0;
}