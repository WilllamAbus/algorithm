#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {}

    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    int pop() {
        int val = q1.front();
        q1.pop();
        return val;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    vector<string> output;

    MyStack* myStack = new MyStack();
    output.push_back("null"); // constructor

    myStack->push(1);
    output.push_back("null");

    myStack->push(2);
    output.push_back("null");

    output.push_back(to_string(myStack->top()));   // 2
    output.push_back(to_string(myStack->pop()));   // 2
    output.push_back(myStack->empty() ? "true" : "false");

    // print format giống LeetCode
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    delete myStack;
    return 0;
}