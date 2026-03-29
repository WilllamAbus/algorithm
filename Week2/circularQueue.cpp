#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
    vector<int> buf;
    int head, size, cap;

public:
    MyCircularQueue(int k): buf(k), head(0), size(0), cap(k) {}

    bool enQueue(int v) {
        if (size == cap) return false;
        buf[(head + size) % cap] = v;
        size++;
        return true;
    }

    bool deQueue() {
        if (size == 0) return false;
        head = (head + 1) % cap;
        size--;
        return true;
    }

    int Front() { return size ? buf[head] : -1; }
    int Rear() { return size ? buf[(head + size - 1) % cap] : -1; }
};

void runCircularQueue() {
    MyCircularQueue q(3);

    cout << q.enQueue(1) << " ";
    cout << q.enQueue(2) << " ";
    cout << q.enQueue(3) << " ";
    cout << q.enQueue(4) << " ";
    cout << q.Rear() << "\n";
}