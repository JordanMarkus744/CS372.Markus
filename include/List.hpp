#pragma once
#include <iostream>
#include <memory> // Include the <memory> header

template <typename T>
class List {
private:
    class Node {
    public:
        T data;
        std::shared_ptr<Node> prev;
        std::shared_ptr<Node> next;
    };
    std::shared_ptr<Node> head;
    std::shared_ptr<Node> tail;

    void deleteListContents() {
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        std::shared_ptr<Node> temp = current;
        current = current->next;
        // Delete the current node (if needed)
        // No need to manually delete when using smart pointers
    }
}


    void setupList() {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        newNode->data = NULL;
        head = newNode;
        tail = newNode;
    }

public:
    List() {
        setupList();
    }

    List(T newData) {
        setupList();
        head->data = newData;
    }

    List(const List& rhs) { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    ~List() {
        deleteListContents();
    }

    bool empty() {
        if (head->next == nullptr && head->data == NULL){
            return true;
        }
        else{
            return false;
        }
    }

    void push_front(T data) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = data;

        if (head->next == nullptr && tail->prev == nullptr) {
            head->data = newNode->data;
        } else {
            newNode->next = head;
            newNode->prev = nullptr;
            head = newNode;
        }
    }

    void push_back(T data) {
    if (empty()) {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        head = newNode;
        tail = newNode;
    } else {
        std::shared_ptr<Node> newNode = std::make_shared<Node>();
        newNode->data = data;
        newNode->next = nullptr;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

    T front() {
        return head->data;
    }

    T back() {
        return tail->data;
    }

    void pop_back() {
        std::shared_ptr<Node> lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
    }

    void pop_front() {
        std::shared_ptr<Node> firstNode = head;
        head = head->next;
    }

    void printTheList() {
    std::shared_ptr<Node> current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

    void traverse(void (*doIt)(T data)) {
        std::shared_ptr<Node> current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }
};