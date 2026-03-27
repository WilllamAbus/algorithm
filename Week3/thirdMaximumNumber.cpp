#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long max1 = LONG_MIN;
        long max2 = LONG_MIN;
        long max3 = LONG_MIN;

        for (int x : nums) {
            // skip duplicate
            if (x == max1 || x == max2 || x == max3) continue;

            if (x > max1) {
                max3 = max2;
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max3 = max2;
                max2 = x;
            } else if (x > max3) {
                max3 = x;
            }
        }

        return (max3 == LONG_MIN) ? (int)max1 : (int)max3;
    }
};

// utility: in vector
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

    // ===== Example 1 =====
    vector<int> nums1 = {3, 2, 1};
    cout << "Input: ";
    printVector(nums1);
    cout << endl;

    int res1 = sol.thirdMax(nums1);
    cout << "Output: " << res1 << endl;
    cout << "Expected: 1" << endl;
    cout << "----------------------" << endl;

    // ===== Example 2 =====
    vector<int> nums2 = {1, 2};
    cout << "Input: ";
    printVector(nums2);
    cout << endl;

    int res2 = sol.thirdMax(nums2);
    cout << "Output: " << res2 << endl;
    cout << "Expected: 2" << endl;
    cout << "----------------------" << endl;

    // ===== Example 3 =====
    vector<int> nums3 = {2, 2, 3, 1};
    cout << "Input: ";
    printVector(nums3);
    cout << endl;

    int res3 = sol.thirdMax(nums3);
    cout << "Output: " << res3 << endl;
    cout << "Expected: 1" << endl;
    cout << "----------------------" << endl;

    return 0;
}