#include <iostream>

template <typename T>
class List {
private:
    class Node {
    public:
        T  data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void deleteListContents() {
        Node* current = head;
        Node* temp = nullptr;
        while (current != nullptr) {
            temp = current->next;
            delete current;
            current = temp;
        }
    }
    void setupList() {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
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

    List(List& rhs) { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }

    ~List(){
        deleteListContents();
    }

    bool  empty(){
        if (head == nullptr){
            return true;
        }
        else{
            return false;
        }
    }

    void push_front(T data) {
        
        Node* newNode = new Node();
        newNode->data = data;
        if (head->next == nullptr && tail->prev == nullptr){
            head->data = newNode->data;
        }
        else{
            newNode->next = head;
            newNode->prev = nullptr;
            head = newNode;
        }
    }

    void push_back(T data) {
        if (head->next == nullptr && tail->prev == nullptr && head->data == NULL){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->prev = nullptr;
            newNode->next = nullptr;
            head = newNode;
            tail = newNode;
        }
        else{
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = nullptr;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    T front() {
        return (head->data);
    }
    T back() {
        return (tail->data);
    }

    void pop_back() {
        Node *lastNode = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete lastNode;
    }

    void pop_front() {
        Node *firstNode = head;
        head = head->next;
        head->prev = nullptr;
        delete firstNode;
    }

    void printTheList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void traverse(void (*doIt)(T data)) {
        Node* current = head;
        while (current != nullptr) {
            doIt(current->data);
            current = current->next;
        }
    }

};

void printElement(int data){
    std::cout << data << " ";
}


int main() {
    // Create an empty list
    List<int> myList;

    // Check if the list is empty
    if (myList.empty()) {
        std::cout << "List is empty." << std::endl;
    } else {
        std::cout << "List is not empty." << std::endl;
    }

    // Add elements to the list
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);

    // Print the list
    myList.printTheList(); // Output: 5 10 20 30

    // Access the front and back elements
    std::cout << "Front element: " << myList.front() << std::endl; // Output: 5
    std::cout << "Back element: " << myList.back() << std::endl;   // Output: 30

    // Remove elements from the list
    myList.pop_back();
    myList.pop_front();

    // Print the modified list
    myList.printTheList(); // Output: 10 20

    std::cout << "\n\nTraversing the Linked List" << std::endl;

    myList.traverse(printElement);

    return 0;
}
