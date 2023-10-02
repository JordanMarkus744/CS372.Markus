#include <memory.h>
#pragma once
template<typename V>
class Tree {
private:
   struct Node {
      Node(V v, shared_ptr<Node> & l, shared_ptr<Node>Node & r):
               value(v), left(l), right(r) {}
      V value;
      shared_ptr<Node> left;
      shared_ptr<Node> right;
   };
   explicit Tree(shared_ptr<Node> & node): root(node) {}
   shared_ptr<Node> root;
public:
   Tree() {}
   Tree(Tree const &lft, V value, Tree const &rgt) : root(Node(val, lft->root, rgt->root )) {}
           
   bool isEmpty() const { return !root; }
   V getRoot() const { return root->val; }
   Tree &left() const {return root->left; }
   Tree &right() const {return root->right; }

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