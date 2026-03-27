#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        long long expected = 1LL * n * (n + 1) / 2;
        long long actual = 0;

        for (int x : nums) {
            actual += x;
        }

        return (int)(expected - actual);
    }
};

// helper để in vector (debug visibility)
void printVector(const vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i != nums.size() - 1) cout << ",";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {3, 0, 1};
    cout << "Input: ";
    printVector(nums1);
    cout << "\nOutput: " << sol.missingNumber(nums1) << endl;
    cout << "Expected: 2\n\n";

    // Example 2
    vector<int> nums2 = {0, 1};
    cout << "Input: ";
    printVector(nums2);
    cout << "\nOutput: " << sol.missingNumber(nums2) << endl;
    cout << "Expected: 2\n\n";

    // Example 3
    vector<int> nums3 = {9,6,4,2,3,5,7,0,1};
    cout << "Input: ";
    printVector(nums3);
    cout << "\nOutput: " << sol.missingNumber(nums3) << endl;
    cout << "Expected: 8\n\n";

    return 0;
}