#ifndef BST_H
#define BST_H

#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value);
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int value);
    Node* search(Node* node, int value);
    Node* findMin(Node* node);
    Node* remove(Node* node, int value);

    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);

public:
    BST();

    void insert(int value);
    void search(int value);
    void remove(int value);

    void inorder();
    void preorder();
    void postorder();
};

#endif

