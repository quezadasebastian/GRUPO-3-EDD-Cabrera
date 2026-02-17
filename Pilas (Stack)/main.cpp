#include "cola.cpp"

int main() {
    CQueue<int> cola;

    cola.enqueue(10);
    cola.enqueue(20);
    cola.enqueue(30);

    cout << "Front: " << cola.front() << endl;   // 10
    cout << "Back: " << cola.back() << endl;     // 30
    cout << "Search 20: " << cola.search(20) << endl; // 1

    cout << "Dequeue: " << cola.dequeue() << endl; // 10
    cola.removeByValue(30);

    cout << "Front después de operaciones: " << cola.front() << endl; // 20
    return 0;
}
