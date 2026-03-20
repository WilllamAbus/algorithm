#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;
        st.reserve(asteroids.size()); // tránh realloc (cost copy)

        for (int a : asteroids) {
            bool alive = true;

            while (alive && !st.empty() && st.back() > 0 && a < 0) {
                int top = st.back();

                if (abs(top) < abs(a)) {
                    st.pop_back(); // top chết → tiếp tục chain collision
                } 
                else if (abs(top) == abs(a)) {
                    st.pop_back(); // cả 2 chết
                    alive = false;
                } 
                else {
                    alive = false; // asteroid hiện tại chết
                }
            }

            if (alive) {
                st.push_back(a);
            }
        }

        return st;
    }
};

// util: in vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i != v.size() - 1) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {5, 10, -5},
        {8, -8},
        {10, 2, -5},
        {3, 5, -6, 2, -1, 4}
    };

    for (auto& asteroids : testCases) {
        vector<int> result = sol.asteroidCollision(asteroids);
        printVector(result);
    }

    return 0;
}