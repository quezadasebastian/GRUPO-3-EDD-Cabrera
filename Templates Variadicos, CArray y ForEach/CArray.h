\
#ifndef CARRAY_H
#define CARRAY_H

#include <stdexcept>

template <typename T>
class CArray {
    T*  m_data;
    int m_size;
    int m_capacity;

public:
    using value_type = T;

    // Iterador simple (puntero)
    T* begin() { return m_data; }
    T* end()   { return m_data + m_size; }

    CArray() : m_data(nullptr), m_size(0), m_capacity(0) {}
    ~CArray() { delete[] m_data; }

    int size() const { return m_size; }
    bool empty() const { return m_size == 0; }

    void push_back(const T& val) {
        if (m_size == m_capacity) {
            int newCap = (m_capacity == 0) ? 4 : (m_capacity * 2);
            T* tmp = new T[newCap];
            for (int i = 0; i < m_size; i++) tmp[i] = m_data[i];
            delete[] m_data;
            m_data = tmp;
            m_capacity = newCap;
        }
        m_data[m_size++] = val;
    }

    // BÚSQUEDA por valor (retorna índice o -1)
    int search(const T& val) const {
        for (int i = 0; i < m_size; i++)
            if (m_data[i] == val) return i;
        return -1;
    }

    // ELIMINACIÓN por índice
    void removeAt(int idx) {
        if (idx < 0 || idx >= m_size) throw std::out_of_range("Indice fuera de rango");
        for (int i = idx; i < m_size - 1; i++)
            m_data[i] = m_data[i + 1];
        m_size--;
    }

    // ELIMINACIÓN por valor
    bool removeByValue(const T& val) {
        int idx = search(val);
        if (idx == -1) return false;
        removeAt(idx);
        return true;
    }

    // ━━ FOREACH VARIÁDICO ━━
    template <typename ObjFunc, typename ...Args>
    void Foreach(ObjFunc fn, Args... args) {
        auto iter = begin();
        for (; iter != end(); ++iter)
            fn(*iter, args...);
    }
};

#endif
