#include <iostream>
#include "CircularList.hpp"

int main(){
    Circular<float> myList;

    myList.push_back(3.5);
    myList.push_back(4.5);
    myList.push_back(5.4);
    myList.push_back(6.5);
    myList.push_back(7.3);
    myList.push_back(8.2);

    myList.Circle(myList.tail->prev);

    myList.pop_back();

    myList.Circle(myList.tail->prev);

    myList.push_front(2.2);
    std::cout << "\n";

    myList.Circle(myList.tail);

    myList.pop_front();

    myList.Circle(myList.tail);

}