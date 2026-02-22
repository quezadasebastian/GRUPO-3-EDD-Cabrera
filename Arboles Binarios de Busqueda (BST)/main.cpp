#include "BST.h"

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "InOrder: ";
    tree.inorder();

    std::cout << "PreOrder: ";
    tree.preorder();

    std::cout << "PostOrder: ";
    tree.postorder();

    tree.search(40);
    tree.search(100);

    tree.remove(20);

    std::cout << "InOrder despues de eliminar 20: ";
    tree.inorder();

    return 0;
}

