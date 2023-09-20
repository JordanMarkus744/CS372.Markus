#pragma once
template <typename T>
class List
{
protected:
	int deleted = 0;
	int notDeleted = 0;
	class Node {
	public:
		T  data;
		Node* prev;
		Node* next;
		bool deleted; // Lazy Deletion Implementation
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	void setupList() {
		Node* newNode = new Node();
		newNode->next = nullptr;
		newNode->prev = nullptr;
		newNode->deleted = false;
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
public:
	List() = default;
	List(T newData) {
		setupList();
		head->data = newData;
	}
	List(List& rhs) { // copy constructor
		deleteListContents();
		head = rhs.head;
		tail = rhs.tail;
	}
	~List() {// And a destructor
		deleteListContents();
	}
	bool  empty() {
		return (head == nullptr);
	}
	void push_front(T data)
	{
		if (this->empty()) {
			setupList();
			head->data = data;
			tail = head;
			notDeleted = 1;
		}
		else {
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = head;
			newNode->prev = nullptr;
			head = newNode;
			notDeleted++;
			if (notDeleted == deleted){
				cleanup();
			}
		}
	}
	void push_back(T data)
	{
		if (this->empty()) {
			setupList();
			head->data = data;
			tail = head;
			notDeleted = 1;
		}
		else {
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = nullptr;
			newNode->prev = tail;
            tail->next = newNode;
			tail = newNode;
			notDeleted++;
			if (notDeleted == deleted){
				cleanup();
			}
		}
	}
	T front() {
		return (head->data);
	}
	T back() {
		return (tail->data);
	}
	void pop_back() {
		Node* lastNode = tail;
		tail = tail.prev;
		tail.next = nullptr;
		delete lastNode;
		notDeleted--;
		deleted++;
		if (notDeleted == deleted){
			cleanup();
		}
	}
	void pop_front() {
		Node* firstNode = head;
		head = head.next;
		head.prev = nullptr;
		delete firstNode;
		notDeleted--;
		deleted++;
		if (notDeleted == deleted){
			cleanup();
		}
	}
	void traverse(void (*doIt)(T data)) {
		Node* current = head;
		while (current != nullptr) {
			doIt(current->data);
			current = current->next;
		}
	}

	void cleanup(){
		Node* current = new Node();
		Node* temp = new Node(); // current->next
		Node* temp2 = new Node(); // current->prev
		current = head;
		while(current != nullptr){
			temp = current->next;
			temp2 = current->prev;
			if (current->deleted){
				if (current == head){
					head = temp;
				}
				if (head != nullptr){
					head->prev = nullptr;
				}
				delete current;
			}
			else{
				temp2->next = temp;
				if (temp != nullptr){
					temp->prev = temp2;
				}
				delete current;
			}
			current = current->next;
		}
		deleted = 0;
	}
};