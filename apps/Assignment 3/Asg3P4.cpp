#include <iostream>
#include "PriorityList.hpp"

int main(){ // If you use the overloaded Insert function that takes in only priority and data, it will auto sort by priority, but if you choose a spot to put it in then it will be there
    Priority<int, int> PriorityList(1,1);
    PriorityList.Insert(5,2);
    PriorityList.Insert(6,1);
    PriorityList.Insert(7,9);
    PriorityList.Insert(3,12);
    PriorityList.Insert(1,4);
    PriorityList.Print();
    PriorityList.Insert(PriorityList.head, 10,10);
    std::cout << "Now I've inserted prio 10 data 10 at the head!" << std::endl;
    PriorityList.Print();

    return 0;
}