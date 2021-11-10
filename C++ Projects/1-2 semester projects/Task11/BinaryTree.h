//
// Created by a3057 on 12/10/2020.
//

#ifndef TASK11_BINARYTREE_H_
#define TASK11_BINARYTREE_H_
#include <ostream>

class BinaryTree {
private:
    struct Node {
        int value;
        Node *left;
        Node *right;
    };

    Node *root;

    std::pair<Node*, int> maxTree;

    Node* findNode(int value, Node *node);

    Node* findNode(int value);

    Node* findMin(Node* );

    Node* findParent(Node*, Node*);

    void deleteRoot();

    void deleteTree(Node*);

    void deleteElement(Node*);

    void addAll(Node *node);

    std::ostream& printTree(std::ostream&, Node*) const;

    int lengthOfTheLongestWayFromRootToLeaf(Node*);

public:
    BinaryTree():root(nullptr){}

    BinaryTree(int);

    BinaryTree(const BinaryTree&);

    BinaryTree(BinaryTree&&);

    ~BinaryTree();

    BinaryTree& operator= (const BinaryTree&);

    BinaryTree& operator= (BinaryTree&&);

    void addNode(Node*, int);

    void addNode(int);

    void deleteTree();

    friend std::ostream & operator<< (std::ostream&, const BinaryTree& );

    void deleteElement(int);

    int lengthOfTheLongestWayFromRootToLeaf();

    std::pair<Node*, int> writeTheResultIntoMaxTree(Node* );
    int count(Node*);
    Node* maxTreeWithLeftSideBiggerThanRightOne();

};

#endif //TASK11_BINARYTREE_H_
