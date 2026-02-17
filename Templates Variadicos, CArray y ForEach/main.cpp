\
#include <iostream>
#include "CArray.h"
#include "funcs.h"

static void printRange(int* b, int* e) {
    for (auto it = b; it != e; ++it) std::cout << *it << " ";
    std::cout << "\n";
}

int main() {
    CArray<int> arr;
    arr.push_back(7);
    arr.push_back(4);
    arr.push_back(9);
    arr.push_back(2);
    arr.push_back(5);

    std::cout << "Inicial: ";
    printRange(arr.begin(), arr.end());

    arr.Foreach(f1);
    std::cout << "Luego de Foreach(f1): ";
    printRange(arr.begin(), arr.end());

    arr.Foreach(f2, 5);
    std::cout << "Luego de Foreach(f2, 5): ";
    printRange(arr.begin(), arr.end());

    arr.Foreach(f3, 7, 4, 8, 14);
    std::cout << "Luego de Foreach(f3, 7,4,8,14): ";
    printRange(arr.begin(), arr.end());

    return 0;
}
