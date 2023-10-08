#include <iostream>
#include <vector>

template <typename T>
bool binarySearch(std::vector<T> aSortedVector,  T itemToBeFound,  bool printDebugData = false);

int main(){
    std::vector<int> SortedIntVec = {1,2,3,4,5,6,7,8,9,10};
    bool isThere = binarySearch(SortedIntVec, 6, true);

    isThere = binarySearch(SortedIntVec, 6);
    
    if (isThere){
        std::cout << "Returned True." << std::endl;
    }
    else{
        std::cout << "Returned False." << std::endl;
    }

    return 0;
}
template <typename T>
bool binarySearch(std::vector<T> aSortedVector, T itemToBeFound, bool printDebugData){


    int count = 1;
    int low = 0;
    int high = aSortedVector.size() - 1;
    int mid = low + (high - low)/2; 

    while(aSortedVector[mid] != itemToBeFound || mid != static_cast<int>(aSortedVector.size()-1)){ // only put static_cast<int> there to get rid of an error
        if (count > static_cast<int>(aSortedVector.size())){
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
    if (printDebugData){
        if (aSortedVector[mid] == itemToBeFound){ // We found the target
            std::cout << "Searched " << count << " items to find " << aSortedVector[mid] << " at index " << mid << std::endl;
            return true;
        }

        std::cout << "Searched " << count << " items and couldn't find the item in the vector." << std::endl;
        return false;
    }
    else{
        if (aSortedVector[mid] == itemToBeFound){ // We found the target
            std::cout << "Found " << aSortedVector[mid] << " at index " << mid << std::endl;
            return true;
        }

        std::cout << "Couldn't find item in vector." << std::endl;
        return false;
    }
}