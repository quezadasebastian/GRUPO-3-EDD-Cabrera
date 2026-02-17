#include "BST.h"

Node::Node(int value) {
    data = value;
    left = right = nullptr;
}

BST::BST() {
    root = nullptr;
}

// INSERT
Node* BST::insert(Node* node, int value) {
    if (node == nullptr)
        return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

void BST::insert(int value) {
    root = insert(root, value);
}

// SEARCH
Node* BST::search(Node* node, int value) {
    if (node == nullptr || node->data == value)
        return node;

    if (value < node->data)
        return search(node->left, value);

    return search(node->right, value);
}

void BST::search(int value) {
    Node* result = search(root, value);
    if (result)
        std::cout << "Elemento encontrado\n";
    else
        std::cout << "Elemento no encontrado\n";
}

// FIND MIN
Node* BST::findMin(Node* node) {
    while (node && node->left != nullptr)
        node = node->left;
    return node;
}

// REMOVE
Node* BST::remove(Node* node, int value) {
    if (node == nullptr)
        return node;

    if (value < node->data)
        node->left = remove(node->left, value);
    else if (value > node->data)
        node->right = remove(node->right, value);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = remove(node->right, temp->data);
    }

    return node;
}

void BST::remove(int value) {
    root = remove(root, value);
}

// TRAVERSALS
void BST::inorder(Node* node) {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }
}

void BST::preorder(Node* node) {
    if (node != nullptr) {
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
}

void BST::postorder(Node* node) {
    if (node != nullptr) {
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }
}

void BST::inorder() {
    inorder(root);
    std::cout << std::endl;
}

void BST::preorder() {
    preorder(root);
    std::cout << std::endl;
}

void BST::postorder() {
    postorder(root);
    std::cout << std::endl;
}

