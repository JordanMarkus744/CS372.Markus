#include <iostream>
#include <string>

const int SIZE = 1000;

void FirstFunc(){
    int *arr = new int[SIZE];

    for (int i = 0; i < SIZE; i++){
        arr[i] = i;
    }
    int *ptr = arr;
    delete[] arr;
    for (int i = 0; i < 10; i++){
        std::cout << ptr[i] << ", ";
    }
}


void SecondFunc(){
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++){
        arr[i] = i;
    }
    int *ptr = arr;
    int *secondptr = arr;
    delete arr;

    std::cout << "\n\nMemory Address: " << &secondptr << std::endl;
    for (int i = 0; i < 10; i++){
        std::cout << secondptr[i] << ", ";
    }
}

std::string* thirdFunc(){
    std::string *myString = new std::string("abcdefghijkl");
    return myString;
}

void fourthFunc(){
    std::string *newString = thirdFunc();
    std::cout << "\n\n" << *newString << std::endl;
}


int main(){
    FirstFunc();
    SecondFunc();
    fourthFunc();
    return 0;
}