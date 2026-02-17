#include "cola.h"

template <typename T>
CQueue<T>::CQueue(int cap) : m_capacity(cap), m_front(0), m_rear(-1), m_count(0) {
    m_data = new T[m_capacity];
}

template <typename T>
CQueue<T>::~CQueue() { delete[] m_data; }

template <typename T>
void CQueue<T>::enqueue(const T& val) {
    if (m_count == m_capacity) {
        T* tmp = new T[m_capacity * 2];
        for (int i = 0; i < m_count; i++)
            tmp[i] = m_data[(m_front + i) % m_capacity];
        delete[] m_data;
        m_data = tmp;
        m_front = 0;
        m_rear = m_count - 1;
        m_capacity *= 2;
    }
    m_rear = (m_rear + 1) % m_capacity;
    m_data[m_rear] = val;
    m_count++;
}

template <typename T>
T CQueue<T>::dequeue() {
    if (m_count == 0) throw underflow_error("Cola vacía");
    T val = m_data[m_front];
    m_front = (m_front + 1) % m_capacity;
    m_count--;
    return val;
}

template <typename T>
int CQueue<T>::search(const T& val) const {
    for (int i = 0; i < m_count; i++) {
        int idx = (m_front + i) % m_capacity;
        if (m_data[idx] == val) return i;
    }
    return -1;
}

template <typename T>
bool CQueue<T>::removeByValue(const T& val) {
    int pos = search(val);
    if (pos == -1) return false;
    return removeByIndex(pos);
}

template <typename T>
bool CQueue<T>::removeByIndex(int idx) {
    if (idx < 0 || idx >= m_count) return false;
    for (int i = idx; i < m_count - 1; i++) {
        int cur = (m_front + i) % m_capacity;
        int nxt = (m_front + i + 1) % m_capacity;
        m_data[cur] = m_data[nxt];
    }
    m_rear = (m_rear - 1 + m_capacity) % m_capacity;
    m_count--;
    return true;
}

template <typename T>
T& CQueue<T>::front() { return m_data[m_front]; }

template <typename T>
T& CQueue<T>::back() { return m_data[m_rear]; }
