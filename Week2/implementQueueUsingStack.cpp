#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class MyQueue {
private:
    stack<int> inStack;
    stack<int> outStack;

    void shift() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }

public:
    void push(int x) {
        inStack.push(x);
    }

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

int main() {
    MyQueue myQueue;
    vector<string> output;

    // MyQueue()
    output.push_back("null");

    // push(1)
    myQueue.push(1);
    output.push_back("null");

    // push(2)
    myQueue.push(2);
    output.push_back("null");

    // peek()
    output.push_back(to_string(myQueue.peek()));

    // pop()
    output.push_back(to_string(myQueue.pop()));

    // empty()
    output.push_back(myQueue.empty() ? "true" : "false");

    // in ra đúng format LeetCode
    cout << "[";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}