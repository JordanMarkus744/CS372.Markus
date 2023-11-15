#include <iostream>
#include <memory>

template<typename T>
class Tree {
public:
    struct Node {
        T data;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(T val) : data(val), left(nullptr), right(nullptr) {}
    };
    
    std::shared_ptr<Node> root;

    // Helper function to add a leaf node
    std::shared_ptr<Node> addLeaf(T data, std::shared_ptr<Node> curr) {
        if (!curr) {
            return std::make_shared<Node>(data);
        }

        if (data <= curr->data) {
            curr->left = addLeaf(data, curr->left);
        } else {
            curr->right = addLeaf(data, curr->right);
        }
        return curr;
    }

    // Helper function to delete a leaf node
    std::shared_ptr<Node> deleteLeaf(T data, std::shared_ptr<Node> curr) {
        if (!curr) {
            return nullptr; // Node not found
        }

        if (data < curr->data) {
            curr->left = deleteLeaf(data, curr->left);
        } else if (data > curr->data) {
            curr->right = deleteLeaf(data, curr->right);
        } else {
            if (!curr->left) {
                return curr->right;
            } else if (!curr->right) {
                return curr->left;
            }

            // Node with value data found, replace it with the in-order successor
            std::shared_ptr<Node> minRight = findMin(curr->right);
            curr->data = minRight->data;
            curr->right = deleteLeaf(minRight->data, curr->right);
        }
        return curr;
    }

    // Helper function to find the minimum value node in a subtree
    std::shared_ptr<Node> findMin(std::shared_ptr<Node> node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    // Helper function for tree traversal
    void Traverse(std::shared_ptr<Node> current) {
        if (current) {
            Traverse(current->left);
            std::cout << current->data << " ";
            Traverse(current->right);
        }
    }

    T getRoot(){
        return root->data;
    }


    Tree() : root(nullptr) {}

    bool SearchTree(std::shared_ptr<Tree<int>> currentTree, T val){
        if (currentTree->isEmpty()){
            return false;
        }
        else{
            return SearchTree(currentTree, val, currentTree->root);
        }
    }

    bool SearchTree(std::shared_ptr<Tree<int>> currentTree, T val, std::shared_ptr<Node> curr){
        if (currentTree->isEmpty()){
            return false;
        }
        if (curr->data < val){
            return SearchTree(currentTree, val, curr->right);
        }
        else if (curr->data > val){
            return SearchTree(currentTree, val, curr->left);
        }
        else{
            return true;
        }
    }

    // Public method to add a leaf node
    void addLeaf(T data) {
        root = addLeaf(data, root);
    }

    // Public method to delete a leaf node
    bool deleteLeaf(T data) {
        if (!root) {
            std::cout << "Tree is empty!" << std::endl;
            return false;
        }
        root = deleteLeaf(data, root);
        return true;
    }

    // Public method to check if the tree is empty
    bool isEmpty() const {
        return !root;
    }

    // Public method to traverse the tree
    void Traverse() {
        Traverse(root);
        std::cout << std::endl;
    }



   /*bool member(T x) const{
    if (isEmpty()){
        return false;
    }
    else{
        if (getRoot() == x){
            return true;
        }
        else{
            return left().member(x) || right().member(x);
        }
    }

   }*/
   bool isLeaf() const{
    if (isEmpty()){
        return false;
    }
    else{
        return !root->left && !root->right;
    }
   }

};

    // Part 1
template<typename V>
int countNodes(const std::shared_ptr<typename Tree<V>::Node>& root) {
    if (!root) {
        return 0;
    }

    return 1 + countNodes<V>(root->left) + countNodes<V>(root->right);
}

// Part 2
template<typename V>
int countInternalNodes(const std::shared_ptr<typename Tree<V>::Node>& root) {
    if (!root || (!root->left && !root->right)) { // base case
        return 0;
    }

    return 1 + countInternalNodes<V>(root->left) + countInternalNodes<V>(root->right);
}

// Part 3
template<typename V>
void computeExternalPathLength(const std::shared_ptr<typename Tree<V>::Node>& root, int& summation) {
    if (!root) { // base case
        return;
    }

    summation += 1;
    computeExternalPathLength<V>(root->left, summation);
    computeExternalPathLength<V>(root->right, summation);
}


int main() {
    std::shared_ptr<Tree<int>::Node> root = std::make_shared<Tree<int>::Node>(1);
    root->left = std::make_shared<Tree<int>::Node>(10);
    root->right = std::make_shared<Tree<int>::Node>(12);
    root->left->left = std::make_shared<Tree<int>::Node>(14);
    root->left->right = std::make_shared<Tree<int>::Node>(15);
    root->right->left = std::make_shared<Tree<int>::Node>(16);

    int nodeCount = countNodes<int>(root);
    std::cout << "Nodes Amount: " << nodeCount << std::endl;

    int internalNodeCount = countInternalNodes<int>(root);
    std::cout << "Internal Nodes Amount: " << internalNodeCount << std::endl;

    int externalPathLength = 0;
    computeExternalPathLength<int>(root, externalPathLength);
    std::cout << "Computed External Path Length: " << externalPathLength << std::endl;

    return 0;
}