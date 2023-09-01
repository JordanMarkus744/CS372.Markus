#include <iostream>

template <typename T, size_t MAXSIZE>
class Bag{
    T items[MAXSIZE];
    int reciepts[MAXSIZE];
    bool isUsed[MAXSIZE];
    int next;

public:

    Bag(){
        next = 1;
        for (unsigned int i = 0; i < MAXSIZE; i++){
            isUsed[i] = false; // Making sure that none of the reciepts are used on instantiation
        }
    }

    T& remove(int reciept){
        for (int i = 0; i < MAXSIZE; i++){
            if (isUsed[i] == true && reciept == reciepts[i]){
                isUsed[i] = false;
                return items[i];
            }
        }
        std::cout << "That reciept could not be found. " << std::endl;
    }

    int insert(T& object){
        if (next >= MAXSIZE){
            std::cout << "The bag is already full" << std::endl;
        }
        else{
            int reciept = next++;
            for (unsigned int i = 0; i < MAXSIZE; i++){
                if (isUsed[i] == false){
                    isUsed[i] = true;
                    items[i] = object;
                    reciepts[i] = reciept;
                    std::cout << object << " was inserted into the bag!" << std::endl;
                    return reciept;
                }
            }
        }
        return -1;
    }

    int size(){
        return MAXSIZE;
    }

    int count(){
        int num = 0;
        for (int i = 0; i <= MAXSIZE; i++){
            if (isUsed[i]){
                num++;
            }
        }
        return num;
    }

};

int main(){
    Bag<int, 100> bag;
    for (int i = 1; i <= 10; i++){
        bag.insert(i);
    }

    int reciept = bag.remove(2);
    std::cout << reciept << std::endl;

    std::cout << bag.size() << std::endl;
    std::cout << bag.count();
    return 0;
}