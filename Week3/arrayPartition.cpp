#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // bottleneck: O(n log n)
        sort(nums.begin(), nums.end());

        // linear pass: O(n)
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2) {
            sum += nums[i];
        }
        return sum;
    }
};

// util: in vector (debug + visibility)
void printVector(const vector<int>& nums) {
    cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ", ";
    }
    cout << "]";
}

// util: chạy 1 test case
void runTest(vector<int> nums, int expected) {
    Solution sol;

    cout << "Input: ";
    printVector(nums);
    cout << endl;

    int result = sol.arrayPairSum(nums);

    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;

    if (result == expected) {
        cout << "Status: PASS";
    } else {
        cout << "Status: FAIL";
    }

    cout << "\n--------------------------\n";
}

int main() {
    // Example 1
    runTest({1, 4, 3, 2}, 4);

    // Example 2
    runTest({6, 2, 6, 5, 1, 2}, 9);

    return 0;
}