#include <iostream>

#pragma once

class HotPotato{
    struct Node{
        int data; // data will be the position in the linked list of the node
        Node* next;
        Node* prev;
    };
    Node* head;
    Node* tail;

    void StartUp(){
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
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

    void insert(int data){
        if (head == tail && head->data == NULL){
            Node* temp = new Node();
            temp->data = data;
            head = temp;
            tail = temp;
        }
        else{
            Node* temp = new Node();
            temp->data = data;
            temp->next = head;
            temp->prev = tail;
            head->prev = temp;
            tail->next = temp;
            tail = temp;
        }
    }

    void Delete(Node* node){
        if (node == head){
            Node* temp = new Node();
            temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        else if (node == tail){
            Node* temp = new Node();
            temp = tail;
            tail = tail->prev;
            tail->next = head;
            delete temp;
        }
        else{
            Node* temp = node->prev;
            Node* temp2 = node->next;
            temp->next = temp2;
            temp2->prev = temp;
            delete node;
        }
    }

    void print(){
        Node* temp = head;
        std::cout << "\n\n" << temp->data << ", ";
        temp = temp->next;
        while(temp != head){
            std::cout << temp->data << ", ";
            temp = temp->next;
        }
    }

    

public:

    HotPotato(){
        StartUp();
    }

    HotPotato(int data){
        StartUp();
        head->data = data;
    }

    ~HotPotato(){
        deleteListContents();
    }

    void example(){
        int i = 0;
        Node* temp = head;
        while(i != 50){
            std::cout << temp->data << ", ";
            temp = temp->next;
            i++;
        }
    }

    

    void PlayGame(int N, int M){ // N = number of players, and M = tosses before someone gets out
        for (int i = 0; i <= N; ++i){
            insert(i);
        }
        print();
        Node* temp = head;
        for (int i = 0; i < N-1; i++){
            for (int i = 0; i < M; i++){
                temp = temp->next;
            }
            Node* newNode = temp->next;
            std::cout << "\n" << temp->data << " has been eliminated!";
            Delete(temp);
            temp = newNode;
            print();
        }
        std::cout << "\n\n" << temp->data << " has won!" << std::endl;
    }
};