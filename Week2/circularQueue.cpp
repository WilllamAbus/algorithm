#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> buf;
    int head;
    int size;
    int cap;

public:
    MyCircularQueue(int k) : buf(k), head(0), size(0), cap(k) {}

    bool enQueue(int value) {
        if (isFull()) return false;

        int idx = (head + size) % cap;
        buf[idx] = value;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;

        head = (head + 1) % cap;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return buf[head];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int idx = (head + size - 1) % cap;
        return buf[idx];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == cap;
    }
};

int main() {
    cout << "Output:\n";

    MyCircularQueue q(3);
    cout << "null ";

    cout << (q.enQueue(1) ? "true " : "false ");
    cout << (q.enQueue(2) ? "true " : "false ");
    cout << (q.enQueue(3) ? "true " : "false ");
    cout << (q.enQueue(4) ? "true " : "false ");

    cout << q.Rear() << " ";

    cout << (q.isFull() ? "true " : "false ");

    cout << (q.deQueue() ? "true " : "false ");

    cout << (q.enQueue(4) ? "true " : "false ");

    cout << q.Rear() << endl;

    return 0;
}