#include <iostream>
#include "pila.h"

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    std::cout << "Top: " << s.top() << std::endl; // 30
    s.pop();
    std::cout << "Top despues de pop: " << s.top() << std::endl; // 20

    std::cout << "Tamano actual: " << s.size() << std::endl;

    return 0;
}
