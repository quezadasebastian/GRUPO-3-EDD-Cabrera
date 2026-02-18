#ifndef CQUEUE_H
#define CQUEUE_H
#include <iostream>
#include "CArray.h"
#include <stdexcept>

template <typename T>
class CQueue : public CArray<T> {
    int m_front, m_rear, m_count;

public:
    CQueue() : m_front(0), m_rear(-1), m_count(0) {
        this->resize(8); // capacidad inicial
    }

    // 1. ENQUEUE - Insertar al final
    void enqueue(const T& val) {
        if (m_count == this->m_capacity) {
            T* tmp = new T[this->m_capacity * 2];
            for (int i = 0; i < m_count; i++)
                tmp[i] = this->m_data[(m_front + i) % this->m_capacity];
            delete[] this->m_data;
            this->m_data = tmp;
            m_front = 0;
            m_rear = m_count - 1;
            this->m_capacity *= 2;
        }
        m_rear = (m_rear + 1) % this->m_capacity;
        this->m_data[m_rear] = val;
        m_count++;
    }

    // 2. DEQUEUE - Eliminar frente
    T dequeue() {
        if (m_count == 0) 
            throw std::underflow_error("Cola vacia");
        T val = this->m_data[m_front];
        m_front = (m_front + 1) % this->m_capacity;
        m_count--;
        return val;
    }

    // 3. FRONT - Ver frente sin eliminar
    T& front() {
        if (m_count == 0) 
            throw std::underflow_error("Cola vacia");
        return this->m_data[m_front];
    }

    // 4. BACK - Ver final sin eliminar
    T& back() {
        if (m_count == 0) 
            throw std::underflow_error("Cola vacia");
        return this->m_data[m_rear];
    }

    // 5. SEARCH - Buscar por valor (retorna posición desde frente)
    int search(const T& val) const {
        for (int i = 0; i < m_count; i++) {
            int idx = (m_front + i) % this->m_capacity;
            if (this->m_data[idx] == val) 
                return i; // 0 = frente
        }
        return -1;
    }

    // 6. REMOVE BY VALUE - Eliminar primera ocurrencia
    bool removeByValue(const T& val) {
        int pos = search(val);
        if (pos == -1) return false;
        return removeByIndex(pos);
    }

    // 7. REMOVE BY INDEX - Eliminar por posición (0 = frente)
    bool removeByIndex(int idx) {
        if (idx < 0 || idx >= m_count) return false;
        
        // Desplazar elementos hacia adelante
        for (int i = idx; i < m_count - 1; i++) {
            int cur = (m_front + i) % this->m_capacity;
            int nxt = (m_front + i + 1) % this->m_capacity;
            this->m_data[cur] = this->m_data[nxt];
        }
        m_rear = (m_rear - 1 + this->m_capacity) % this->m_capacity;
        m_count--;
        return true;
    }
    void print() const {
        if (m_count == 0) {
            std::cout << "[]";
            return;
        }
        
        std::cout << "["; 
        for (int i = 0; i < m_count; i++) {
            int idx = (m_front + i) % this->m_capacity;
            std::cout << this->m_data[idx];  
            if (i < m_count - 1) 
                std::cout << ", ";  
        }
        std::cout << "]"; 
    }
    // Utilidades adicionales
    int count() const { return m_count; }
    void clear() {
        m_front = 0;
        m_rear = -1;
        m_count = 0;
    }
};

#endif