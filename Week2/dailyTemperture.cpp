#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> res(n, 0);
        vector<int> st; // dùng vector thay stack (faster)
        st.reserve(n);

        for (int i = 0; i < n; ++i) {
            while (!st.empty() && T[i] > T[st.back()]) {
                int prev = st.back();
                st.pop_back();
                res[prev] = i - prev;
            }
            st.push_back(i);
        }

        return res;
    }
};

// helper in vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;

    // ===== Example 1 =====
    vector<int> t1 = {73,74,75,71,69,72,76,73};
    vector<int> r1 = sol.dailyTemperatures(t1);

    cout << "Input: temperatures = ";
    printVector(t1);
    cout << "\nOutput: ";
    printVector(r1);
    cout << "\n\n";

    // ===== Example 2 =====
    vector<int> t2 = {30,40,50,60};
    vector<int> r2 = sol.dailyTemperatures(t2);

    cout << "Input: temperatures = ";
    printVector(t2);
    cout << "\nOutput: ";
    printVector(r2);
    cout << "\n\n";

    // ===== Example 3 =====
    vector<int> t3 = {30,60,90};
    vector<int> r3 = sol.dailyTemperatures(t3);

    cout << "Input: temperatures = ";
    printVector(t3);
    cout << "\nOutput: ";
    printVector(r3);
    cout << "\n";

    return 0;
}