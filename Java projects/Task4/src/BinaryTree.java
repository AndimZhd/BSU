package com.metanit;

public class BinaryTree<T extends Comparable<T>> {
    private class Node<T extends Comparable<T>>{
        Node<T> left;
        Node<T> right;
        T value;
        public Node(T val){
            left = null;
            right = null;
            value = val;
        }
    }
    private Node<T> root;

    public BinaryTree(T value){
        root = new Node<T>(value);
    }

    public BinaryTree(){
        root = null;
    }

    private void printLeftRootRight(Node<T> node){
        if(node == null)
            return;
        printLeftRootRight(node.left);
        System.out.print(node.value + " ");
        printLeftRootRight(node.right);
    }

    public void printLeftRootRight(){
        printLeftRootRight(root);
        System.out.println();
    }

    private void printRootLeftRight(Node<T> node){
        if(node == null)
            return;
        System.out.println(node.value);
        printRootLeftRight(node.left);
        printRootLeftRight(node.right);
    }

    public void printRootLeftRight(){
        printRootLeftRight(root);
    }

    private void printLeftRightRoot(Node<T> node){
        if(node == null)
            return;
        printLeftRightRoot(node.left);
        printLeftRightRoot(node.right);
        System.out.println(node.value);
    }

    public void printLeftRightRoot(){printLeftRightRoot(root);}

    private Node<T> findInSubtree(Node<T> node, T value){
        if (node==null)
            return null;
        if(node.value.compareTo(value) == 0)
            return node;
        if(node.value.compareTo(value)<0)
            return findInSubtree(node.right, value);
        else
            return findInSubtree(node.left, value);
    }

    private Node<T> find(T value){
        return findInSubtree(root, value);
    }

    private void add(Node<T> node, T value){
        if(node.value.compareTo(value) < 0){
            if(node.right!=null)
                add(node.right, value);
            else
                node.right = new Node<T>(value);
        }
        else {
            if(node.left != null)
                add(node.left, value);
            else
                node.left = new Node<T>(value);
        }

    }

    public void add(T value){
        if(root != null)
            add(root, value);
        else
            root = new Node<T>(value);
    }

    public boolean isThereTheElementInTree(T value){return find(value)!=null;}

    private void deleteANode(Node<T> node){
        Node<T> parent = findTheParent(root, node);
        if(node.left == null && node.right == null){
            if(parent.right == node)
                parent.right = null;
            else
                parent.left = null;
            return;
        }
        if(node.right == null){
            if(parent.right == node)
                parent.right = node.left;
            else
                parent.left = node.left;
            return;
        }
        if (node.left == null){
            if(parent.right == node)
                parent.right = node.right;
            else
                parent.left = node.right;
        }
        else {
            Node<T> min = findMin(node.right);
            node.value = min.value;
            deleteANode(min);
        }

    }

    public void deleteANode(T value){
        Node<T> foundElement = find(value);
        if(foundElement == null)
            return;
        if(foundElement == root)
            deleteTheRoot();
        else
            deleteANode(foundElement);
    }

    private Node<T> findTheParent(Node<T> node, Node<T> child){
        if(node == null)
            return null;
        if(node.left == child || node.right == child){
            return node;
        }
        if(node.value.compareTo(child.value)>0){
            return findTheParent(node.left, child);
        }
        else
            return findTheParent(node.right, child);
    }

    private Node<T> findMin(Node<T> node){
        while(node.left!=null){
            node = node.left;
        }
        return node;
    }

    private void deleteTheRoot(){
        if(root.left == null && root.right == null){
            root = null;
            return;
        }
        if(root.right == null){
            root = root.left;
        }
        if (root.left == null){
            root = root.right;
        }
        else {
            Node<T> min = findMin(root.right);
            root.value = min.value;
            deleteANode(min);
        }

    }
}
