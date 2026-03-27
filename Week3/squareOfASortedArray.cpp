#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(const vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);

        int l = 0;
        int r = n - 1;
        int k = n - 1;

        while (l <= r) {
            int left_sq = nums[l] * nums[l];
            int right_sq = nums[r] * nums[r];

            if (left_sq > right_sq) {
                res[k--] = left_sq;
                l++;
            } else {
                res[k--] = right_sq;
                r--;
            }
        }

        return res;
    }
};

// in vector (production-safe: không dư dấu phẩy)
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i != v.size() - 1) cout << ",";
    }
    cout << "]\n";
}

int main() {
    Solution sol;

    // Example 1
    vector<int> nums1 = {-4, -1, 0, 3, 10};
    vector<int> res1 = sol.sortedSquares(nums1);

    cout << "Input 1: ";
    printVector(nums1);

    cout << "Output 1: ";
    printVector(res1);

    // Example 2
    vector<int> nums2 = {-7, -3, 2, 3, 11};
    vector<int> res2 = sol.sortedSquares(nums2);

    cout << "Input 2: ";
    printVector(nums2);

    cout << "Output 2: ";
    printVector(res2);

    return 0;
}