#include <iostream>
#include "List.hpp"


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

    std::cout << "\nTraversing the Linked List" << std::endl;

    myList.traverse(printElement);

    return 0;
}
