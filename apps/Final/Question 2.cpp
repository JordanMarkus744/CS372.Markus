#include <list>
#include <iostream>

template <typename T>
void Partition(T splittingValue, const std::list<T>& inputList, std::list<T>* lessThan, std::list<T>* greaterThan){
    for (const T& element : inputList){
        if (element > splittingValue){
            greaterThan->push_back(element);
        }
        else{
            lessThan->push_back(element);
        }
    }
}

template <typename T>
std::list<T> quickSort(const std::list<T>& inputList){
    if (inputList.size() <= 1){
        return inputList;
    }

    int middle = inputList.size()/2;
    T pivot = inputList[middle];

    std::list<T> lessThan, greaterThan;
    Partition(pivot, inputList, &lessThan, &greaterThan);

    std::list<T>* sortedLess = quickSort(lessThan);
    std::list<T>* sortedGreater = quickSort(greaterThan);

    sortedLess->push_back(pivot);
    sortedLess->splice(sortedLess->end(), *sortedGreater);
    
    delete sortedGreater;
    return sortedLess; // Sorted list
}

int main(){
    std::list<int> myList = {5,4,3, 6,8,23,16,87,1,-5};
    std::list<int> sortedList = quickSort(myList);
    for (auto itr : sortedList){
        std::cout << itr << ", ";
    }
    return 0;
}

