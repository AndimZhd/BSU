#include <iostream>
#include "BinaryTree.h"


int main()
{
    BinaryTree bt1;
    int n;
    std::cin>>n;
    // add nodes to tree
    for(int i = 0; i<n; i++)
    {
        int value;
        std::cin>>value;
        bt1.addNode(value);
    }
    std::cout<<bt1;
    //bt1.deleteElement(5);
    //std::cout<<bt1;
    std::cout<<bt1.lengthOfTheLongestWayFromRootToLeaf();
    bt1.deleteTree();
    return 0;
}

