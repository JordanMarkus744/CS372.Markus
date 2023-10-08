#include "Tree.hpp"
#include <iostream>
#include <memory>

std::shared_ptr<Tree<int>> createTreeWithoutLeaves(const Tree<int>& originalTree) {
    std::shared_ptr<Tree<int>> newTree = std::make_shared<Tree<int>>();

        // Helper function to copy the tree without leaves
    std::shared_ptr<Node> copyWithoutLeaves(const std::shared_ptr<Node>& currentNode) {
        if (!currentNode) {
            return nullptr;
        }

        if (!currentNode->left && !currentNode->right) {
            return nullptr; // Omit leaves
        }

        std::shared_ptr<Node> newNode = std::make_shared<Node>(currentNode->data);
        newNode->left = copyWithoutLeaves(currentNode->left);
        newNode->right = copyWithoutLeaves(currentNode->right);

        return newNode;
    }

    newTree.getRoot() = copyWithoutLeaves(originalTree.root);
    return newTree;
}


int main() {
    // Example usage
    Tree<int> originalTree;
    originalTree.addLeaf(10);
    originalTree.addLeaf(5);
    originalTree.addLeaf(15);
    originalTree.addLeaf(3);
    originalTree.addLeaf(7);
    originalTree.addLeaf(12);
    originalTree.addLeaf(18);

    std::shared_ptr<Tree<int>> newTree = createTreeWithoutLeaves(originalTree);
    newTree->Traverse(); // Traverse the new tree

    return 0;
}