//
// Created by a3057 on 12/10/2020.
//

#include "BinaryTree.h"

BinaryTree::Node * BinaryTree::findMin(Node * node){
    auto current = node;
    while(current->left)
        current = current->left;
    return current;
}

BinaryTree::Node * BinaryTree::findParent(Node* child, Node * node) {
    if(!node)
        return 0;
    if(node->right == child || node->left == child)
        return node;
    if(node->value <= child->value)
        return findParent(child, node->right);
    else
        return findParent(child, node->left);
}

BinaryTree::Node * BinaryTree::findNode(int value, Node *node) {
    if (!node)
        return 0;
    if (node->value == value)
        return node;
    if (node->value > value)
        return findNode(value, node->left);
    else
        return findNode(value, node->right);
}

BinaryTree::Node * BinaryTree::findNode(int value) {
    return findNode(value, root);
}

void BinaryTree::addNode(Node *node, int value) {
    if (node->value > value) {
        if (node->left)
            addNode(node->left, value);
        else {
            node->left = new Node();
            node->left->value = value;
        }
    } else {
        if (node->right)
            addNode(node->right, value);
        else {
            node->right = new Node();
            node->right->value = value;
        }
    }
}

void BinaryTree::addAll(Node *node) {
    if(!node)
        return;
    addNode(node->value);
    addAll(node->left);
    addAll(node->right);
}

BinaryTree::BinaryTree(int value) {
    addNode(value);
}

BinaryTree::BinaryTree(const BinaryTree & tree) {
    deleteTree();
    addAll(tree.root);
}

BinaryTree::BinaryTree(BinaryTree && tree) {
    root = tree.root;
    tree.root = nullptr;
}

BinaryTree::~BinaryTree() {
    deleteTree();
}

BinaryTree & BinaryTree::operator=(const BinaryTree &tree) {
    if(this == &tree)
        return *this;
    deleteTree();
    addAll(tree.root);
}

BinaryTree & BinaryTree::operator=(BinaryTree && tree) {
    if(this == &tree)
        return *this;
    deleteTree();
    root = tree.root;
    tree.root = nullptr;
}

void BinaryTree::addNode(int value)  {
    if (root) {
        addNode(root, value);
    } else {
        root = new Node();
        root->value = value;
    }
}

void BinaryTree::deleteTree(Node *node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void BinaryTree::deleteTree() {
    deleteTree(root);
    root = nullptr;
}

std::ostream& BinaryTree::printTree(std::ostream& out, Node *node) const{
    if (!node) return out;
    printTree(out, node->left);
    out << node->value << " ";
    printTree(out, node->right);
}

std::ostream & operator<<(std::ostream& out, const BinaryTree & tree) {
    return tree.printTree(out, tree.root)<<std::endl;
}

void BinaryTree::deleteRoot(){
    if(!root->left && !root->right){
        root = nullptr;
        return;
    }
    if(root->right && !root->left){
        auto tempRoot = root->right;
        delete root;
        root = tempRoot;
        return;
    }
    if(!root->right && root->left){
        auto tempRoot = root->left;
        delete root;
        root = tempRoot;
        return;
    }
    else{
        auto rightMin= findMin(root->right);
        root->value = rightMin->value;
        deleteElement(rightMin);
        return;
    }
}

void BinaryTree::deleteElement(Node* node) {
    auto parent = findParent(node, root);
    if(!node->left && !node->right){
        if(parent->right == node){
            parent->right = nullptr;
            delete node;
        }
        else{
            parent->left = nullptr;
            delete node;
        }
        return;
    }
    if(node->right && !node->left){
        if(parent->right == node){
            parent->right = node->right;
            delete node;
        }
        else{
            parent->left = node->right;
            delete node;
        }
        return;
    }
    if(!node->right && node->left){
        if(parent->right == node){
            parent->right = node->left;
            delete node;
        }
        else{
            parent->left = node->left;
            delete node;
        }
        return;
    }
    else {
        auto rightMin = findMin(node->right);
        node->value = rightMin->value;
        deleteElement(rightMin);
        return;
    }
}

void BinaryTree::deleteElement(int value) {
    auto node = findNode(value, root);
    if(node == 0)
        return;
    if(node == root){
        deleteRoot();
        return;
    }
    deleteElement(node);
}

int BinaryTree::lengthOfTheLongestWayFromRootToLeaf() {
    int counter = 0;
    int max = 0;
    return lengthOfTheLongestWayFromRootToLeaf(root);
}

int BinaryTree::lengthOfTheLongestWayFromRootToLeaf(Node *node) {
    if(!node) return 0;
    return std::max(lengthOfTheLongestWayFromRootToLeaf(node->left), lengthOfTheLongestWayFromRootToLeaf(node->right)) + 1;
}

int BinaryTree::count(Node* node) {
    if(!node) return 0;
    return count(node->left)+count(node->right)+1;
}

std::pair<BinaryTree::Node*, int> BinaryTree::writeTheResultIntoMaxTree(Node* node) {
    if(!node) return {node, 0};
    if(writeTheResultIntoMaxTree(node->left).second==-1 || writeTheResultIntoMaxTree(node->right).second==-1)
        return {node, -1};
    int quantity = count(node->left)+ count(node->right);
    if(quantity==0)
        return {node, 0};
    if(count(node->left) > count(node->right)) {
        if(quantity>maxTree.second)
            maxTree = {node, quantity};
        return {node, quantity};
    }
    return {node, -1};
}

BinaryTree::Node* BinaryTree::maxTreeWithLeftSideBiggerThanRightOne() {
    writeTheResultIntoMaxTree(root);
    return maxTree.first;
}