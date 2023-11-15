#include <iostream>
#include <list>

template <typename T>
void partitionList(const T& splittingValue, const std::list<T>& inputList, std::list<T>* lessList, std::list<T>* greaterList) {
    for (const T& element : inputList) {
        if (element < splittingValue) {
            lessList->push_back(element);
        } else if (element > splittingValue) {
            greaterList->push_back(element);
        }
    }
}

template <typename T>
std::list<T>* quicksort(const std::list<T>& inputList) {

    if (inputList.size() <= 1) {
        return new std::list<T>(inputList);
    }

    auto pivotIterator = std::next(inputList.begin(), inputList.size() / 2);
    T pivot = *pivotIterator;


    std::list<T> lessList, greaterList;
    partitionList(pivot, inputList, &lessList, &greaterList);


    std::list<T>* sortedLess = quicksort(lessList);
    std::list<T>* sortedGreater = quicksort(greaterList);


    std::list<T>* combinedList = new std::list<T>(*sortedLess);
    combinedList->push_back(pivot);
    combinedList->splice(combinedList->end(), *sortedGreater);

    delete sortedLess;
    delete sortedGreater;

    return combinedList;
}

int main() {
    std::list<int> inputList = {25,32,55,12,92,104,512,42,67};
    std::list<int>* sortedList = quicksort(inputList);

    std::cout << "Sorted List: ";
    for (const int& element : *sortedList) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    delete sortedList;

    return 0;
}