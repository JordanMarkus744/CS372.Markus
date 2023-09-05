#include <iostream>
#include "List.hpp"
#pragma once

template<typename T, typename S>
class Priority : public List<T>{
    struct Node{
    public:
        S priority;
        T data;
        Node* next;
        Node* prev;
    };

    void setupList() {
        Node* newNode = new Node();
        head = newNode;
        tail = newNode;
    }

    void deleteListContents() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

    bool hasElement = false;

    public:
    Node* head;
    Node* tail;

    Priority(){
        setupList();
    }

    Priority(S Prio, T data){
        Node* newNode = new Node();
        newNode->priority = Prio;
        newNode->data = data;
        head = newNode;
        tail = newNode;
    }

    ~Priority(){
        deleteListContents();
    }



    Node* Tail(){ // Tail will have the highest priority
        return tail;
    }

    Node* Head(){ // Head will have the lowest priority
        return head;
    }

    void Insert(S Priority, T data){
        if (head->next == nullptr){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->priority = Priority;
            newNode->prev = head;
            newNode->next = nullptr;
            head->next = newNode;
            tail = newNode;
        }
        else{
            Node* newNode = new Node();
            newNode->priority = Priority;
            newNode->data = data;
            Node* temp = tail;
            while(temp != head){
                if (Priority > temp->priority){
                    if (temp == tail){
                        tail->next = newNode;
                        newNode->prev = tail;
                        tail = newNode;
                    }
                    else{
                        Node* temp2 = temp->next;
                        temp->next = newNode;
                        newNode->prev = temp;
                        newNode->next = temp2;
                        temp2->prev = newNode;
                    }
                    break;
                }
                temp = temp->prev;
            }
            if (temp == head){
                if (Priority > temp->priority || Priority == temp->priority){
                    Node* temp2 = temp->next;
                    temp->next = newNode;
                    newNode->prev = temp;
                    newNode->next = temp2;
                    temp2->prev = newNode;
                }
                else{
                    newNode->next = head;
                    head->prev = newNode;
                    head = newNode;
                }
            }
        }
        
    }

    void Insert(Node* node, S Priority, T data){
        if (node == head){
            Node* newNode = new Node();
            newNode->priority = Priority;
            newNode->data = data;
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        else{
            Node* newNode = new Node();
            newNode->data = data;
            newNode->priority = Priority;
            Node* temp = node;
            Node* temp2 = node->prev;
            temp2->next = newNode;
            temp->prev = newNode;
            newNode->prev = temp2;
            newNode->next = temp;
        }
        
    }

    void Print(){
        Node* temp = head;
        while(temp != nullptr){
            std::cout << "data: " << temp->data << " : priority: " << temp->priority << std::endl;
            temp = temp->next;
        }
    }



};