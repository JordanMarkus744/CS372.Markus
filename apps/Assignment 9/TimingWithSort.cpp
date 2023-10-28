#include <iostream>
#include <chrono>
#include <ctime>
#include <vector>
#include <algorithm>

int main(){
    std::vector<int> vec;
    std::chrono::time_point<std::chrono::system_clock> start, end;
    srand(time(NULL));

    for (int i = 0; i < 10000; i++){ 
        vec.push_back(rand() % 10000);
    }
    start = std::chrono::system_clock::now();
    auto itr = vec.begin();
    auto itr2 = vec.end();
    std::sort(itr, itr2);
    end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::cout << elapsed_seconds.count() << std::endl;

    
}