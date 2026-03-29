#include <iostream>
#include <vector>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    st.reserve(asteroids.size());

    for (int a : asteroids) {
        bool alive = true;

        while (alive && !st.empty() && st.back() > 0 && a < 0) {
            int top = st.back();

            if (abs(top) < abs(a)) {
                st.pop_back();
            } else if (abs(top) == abs(a)) {
                st.pop_back();
                alive = false;
            } else {
                alive = false;
            }
        }

        if (alive) st.push_back(a);
    }

    return st;
}

void printVec(const vector<int>& v) {
    cout << "[";
    size_t n = v.size();

    for (size_t i = 0; i < n; ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ",";
    }
    cout << "]\n";
}

void runAsteroid() {
    vector<vector<int>> tests = {
        {5,10,-5}, {8,-8}, {10,2,-5}
    };

    for (auto& t : tests)
        printVec(asteroidCollision(t));
}