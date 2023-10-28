#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <time.h>

// QuickSort Times: 100: 0.009s 500: 0.000996s 1000: 0s 5000: 0.000997 10000: 0.002991

template<typename T>
int partition(std::vector<T> &vec, int start, int end)
{
 
    int pivot = vec[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (vec[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    std::swap(vec[pivotIndex], vec[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (vec[i] <= pivot) {
            i++;
        }
 
        while (vec[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            std::swap(vec[i++], vec[j--]);
        }
    }
 
    return pivotIndex;
}

template<typename T>
void QuickSort(std::vector<T> &Vec, int start, int end){
    
    if (start >= end){
        return;
    }

    int par = partition(Vec, start, end);

    QuickSort(Vec, start, par-1);
    QuickSort(Vec, par + 1, end);
}



int main(){
    std::vector<int> vec;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    srand(time(NULL));

    for (int i = 0; i < 1000000; i++){ 
        vec.push_back(rand() % 1000000);
    }
    start = std::chrono::system_clock::now();
    QuickSort(vec, 0, vec.size()-1);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << elapsed_seconds.count() << std::endl;
    /*for (auto itr = vec.begin(); itr != vec.end(); ++itr){
        std::cout << *itr << ", ";
    }*/
    return 0;
}