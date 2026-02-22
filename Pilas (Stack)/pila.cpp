#include "pila.h"

template <class T>
void Stack<T>::push(const T& value) {
    elements.push_back(value);
}

template <class T>
void Stack<T>::pop() {
    if (isEmpty()) throw std::out_of_range("Error: la pila está vacía");
    elements.pop_back();
}

template <class T>
T Stack<T>::top() const {
    if (isEmpty()) throw std::out_of_range("Error: la pila está vacía");
    return elements.back();
}

template <class T>
bool Stack<T>::isEmpty() const {
    return elements.empty();
}

template <class T>
int Stack<T>::size() const {
    return elements.size();
}
