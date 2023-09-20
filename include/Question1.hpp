#include <iostream>
#include "ListTest.hpp"
#pragma once

template<typename T>
class SelfAdjustingList : public List<T>{
    public:
    SelfAdjustingList() = default;

    T* find(T itemToFind){
        typename List<T>::Node* current = this->head;
        while(current != nullptr){
            if (current->data == itemToFind){
                // We found the node, so move it to the front
                typename List<T>::Node* prev = current->prev;
                typename List<T>::Node* next = current->next;
                prev->next = next;
                next->prev = prev;
                current->next = this->head;
                current->prev = nullptr;
                this->head = current;
                return &(current->data);
            }
            current = current->next;
            
        }
        
        std::cout << "Node doesn't exist!" << std::endl;
        return nullptr;
        
    }
};