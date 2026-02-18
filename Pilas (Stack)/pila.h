#ifndef PILA_H
#define PILA_H

#include <vector>
#include <stdexcept>

template <class T>
class Stack {
private:
    std::vector<T> elements;
public:
    void push(const T& value) {
        elements.push_back(value);
    }

    void pop() {
        if (isEmpty()) throw std::out_of_range("Error: la pila está vacía");
        elements.pop_back();
    }

    T top() const {
        if (isEmpty()) throw std::out_of_range("Error: la pila está vacía");
        return elements.back();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    int size() const {
        return elements.size();
    }
};

#endif
