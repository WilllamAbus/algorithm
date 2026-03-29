#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

    void shift() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    void push(int x) { inStack.push(x); }

    int pop() {
        shift();
        int val = outStack.top();
        outStack.pop();
        return val;
    }

    int peek() {
        shift();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

void runQueue() {
    MyQueue q;
    vector<string> out;

    out.push_back("null");
    q.push(1); out.push_back("null");
    q.push(2); out.push_back("null");
    out.push_back(to_string(q.peek()));
    out.push_back(to_string(q.pop()));
    out.push_back(q.empty() ? "true" : "false");

    cout << "[ALGO] queue_stack\nRESULT: [";
    for (size_t i = 0; i < out.size(); ++i) {
        cout << out[i];
        if (i + 1 < out.size()) cout << ", ";
    }
    cout << "]\n\n";
}