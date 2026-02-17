#ifndef COLA_H
#define COLA_H

#include <stdexcept>
#include <iostream>
using namespace std;

template <typename T>
class CQueue {
    T* m_data;
    int m_capacity;
    int m_front, m_rear, m_count;

public:
    CQueue(int cap = 8);
    ~CQueue();

    void enqueue(const T& val);
    T dequeue();
    int search(const T& val) const;
    bool removeByValue(const T& val);
    bool removeByIndex(int idx);

    T& front();
    T& back();
    int count() const { return m_count; }
    bool empty() const { return m_count == 0; }
};

#endif
