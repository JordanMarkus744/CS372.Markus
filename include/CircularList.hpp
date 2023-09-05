#include"List.hpp"
#include <iostream>
#pragma once
template<typename T>
class Circular : public List<T>{
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };

    void setupList() {
        Node* newNode = new Node();
        newNode->next = tail;
        newNode->prev = head;
        head = newNode;
        tail = newNode;
    }
    
    public:
    Node* head;
    Node* tail;
    Circular(){
        setupList();
    }

    Node* Tail(){
        return tail;
    }

    Node* Head(){
        return head;
    }

    void push_back(T data){
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

    void push_front(T data){
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
            head = temp;
        }
    }

    void pop_back(){
        Node* temp = new Node();
        temp = tail;
        tail = tail->prev;
        tail->next = head;
        std::cout << "Popped " << temp->data << std::endl;
        delete temp;
    }

    void pop_front(){
        Node* temp = new Node();
        temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        std::cout << "Popped " << temp->data << std::endl;
        delete temp;
    }

    void Circle(Node* node){
        Node* temp = node->next;
        do{
            std::cout << temp->data << std::endl;
            temp = temp->next;
        }
        while(temp->data != node->data);
        std::cout << temp->data << std::endl;
    }
};