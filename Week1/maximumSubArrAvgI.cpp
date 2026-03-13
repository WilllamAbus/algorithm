#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int n = nums.size();
        long long window_sum = 0;

        // first window
        for (int i = 0; i < k; i++) {
            window_sum += nums[i];
        }

        long long max_sum = window_sum;

        // sliding window
        for (int i = k; i < n; i++) {

            window_sum += nums[i];     // element entering
            window_sum -= nums[i - k]; // element leaving

            if (window_sum > max_sum)
                max_sum = window_sum;
        }

        return (double)max_sum / k;
    }
};

int main() {

    Solution sol;

    // Example 1
    vector<int> nums1 = {1,12,-5,-6,50,3};
    int k1 = 4;

    cout << "Example 1: ";
    cout << fixed << setprecision(5)
         << sol.findMaxAverage(nums1, k1) << endl;

    // Example 2
    vector<int> nums2 = {5};
    int k2 = 1;

    cout << "Example 2: ";
    cout << fixed << setprecision(5)
         << sol.findMaxAverage(nums2, k2) << endl;

    return 0;
}