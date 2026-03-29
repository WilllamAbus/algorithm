#include "vector_utils.h"

void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i + 1 < nums.size()) cout << ",";
    }
    cout << "]\n";
}