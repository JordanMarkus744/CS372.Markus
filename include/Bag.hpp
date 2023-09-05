#include "List.hpp"
#include <iostream>
#pragma once


template <typename Thing>
class Bag {
public:
  void insert(Thing aThing) {
    myList.push_back(aThing);
    bagSize++;
  }


  
  Thing &pop() {
    Thing aThing;
    if (myList.front() != myList.back()) {
      aThing = myList.back();
      bagSize--;
      myList.pop_back();
    }
    else {
      std::cerr << "Can't pop out of an empty bag" << std::endl;
    }
    return aThing;
  }



  int size() {
    return bagSize;
  }

  int count(Thing aThing) {
    int bagCount = 0;
    List<Thing> temp;
    temp = myList.front();
    while(temp != myList.back()){
        if (aThing == temp.listData()){
            bagCount++;
        }
        temp = temp->next;
    }
    return bagCount;
  }
private:
    List<Thing> myList;
    int bagSize = 0;
};