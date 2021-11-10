package com.metanit;

public class Main {

    public static void main(String[] args) {
        /*BinaryTree<Integer> tree = new BinaryTree<Integer>(5);
        tree.add(3);
        tree.add(10);
        tree.add(12);
        tree.add(14);
        tree.add(11);
        tree.add(2);
        tree.add(4);
        tree.add(4);
        tree.printLeftRootRight();
        tree.deleteANode(4);
        tree.deleteANode(1);
        tree.deleteANode(4);
        tree.deleteANode(5);
        tree.printLeftRootRight();*/

        BinaryTree<CustomClass> tree = new BinaryTree<CustomClass>(new CustomClass(5));
        tree.add(new CustomClass(3));
        tree.add(new CustomClass(10));
        tree.add(new CustomClass(12));
        tree.add(new CustomClass(14));
        tree.add(new CustomClass(11));
        tree.add(new CustomClass(2));
        tree.add(new CustomClass(4));
        tree.add(new CustomClass(13));
        //tree.printLeftRootRight();
        tree.deleteANode(new CustomClass(12));
        tree.deleteANode(new CustomClass(4));
        tree.deleteANode(new CustomClass(3));
        //tree.printLeftRootRight();
        tree.printRootLeftRight();
    }
}
