#include <memory>
#pragma once
// Got code from Dr. Lewis Lecture Notes
template<typename V>
class Tree {
private:
   struct Node {
      Node(V v, std::shared_ptr<Node> & l, std::shared_ptr<Node>Node & r):
               value(v), left(l), right(r) {}
      V value;
      std::shared_ptr<Node> left;
      std::shared_ptr<Node> right;
   };
   explicit Tree(shared_ptr<Node> & node): root(node) {}
   std::shared_ptr<Node> root;
public:
   Tree() {}
   Tree(Tree const &lft, V value, Tree const &rgt) : root(Node(val, lft->root, rgt->root )) {}
           
   bool isEmpty() const { return !root; }
   V getRoot() const { return root->val; }
   Tree &left() const {return root->left; }
   Tree &right() const {return root->right; }


    bool deleteLeaf(V x) {
    return deleteLeaf(root, x);
}

bool deleteLeaf(std::shared_ptr<Node>& currentNode, V x) {
    if (!currentNode) {
        return false; // Node not found
    }

    if (currentNode->value == x) {
        // Node with value x found, delete it
        currentNode = nullptr;
        return true;
    }

    // Recursively search in the left and right subtrees
    bool deletedLeft = deleteLeaf(currentNode->left, x);
    bool deletedRight = deleteLeaf(currentNode->right, x);

    return deletedLeft || deletedRight;

}


   bool member(V x) const{
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

   }
   bool isLeaf() const{
    if (isEmpty()){
        return false;
    }
    else{
        return !root->left && !root->right;
    }
   }
};