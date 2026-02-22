#ifndef CARRAY_H
#define CARRAY_H

template <typename T>
class CArray {
protected:
    T* m_data;
    int m_size;
    int m_capacity;

public:
    CArray() : m_data(nullptr), m_size(0), m_capacity(0) {}
    
    virtual ~CArray() { delete[] m_data; }
    
    void resize(int newCap) {
        T* tmp = new T[newCap];
        for (int i = 0; i < m_size; i++) 
            tmp[i] = m_data[i];
        delete[] m_data;
        m_data = tmp;
        m_capacity = newCap;
    }
    
    T& operator[](int i) { return m_data[i]; }
    int size() const { return m_size; }
    bool empty() const { return m_size == 0; }
};

#endif