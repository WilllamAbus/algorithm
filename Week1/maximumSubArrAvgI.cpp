#include <iostream>
#include <vector>
using namespace std;

double findMaxAverage(vector<int>& nums, int k) {

    long long window_sum = 0;

    for (int i = 0; i < k; i++)
        window_sum += nums[i];

    long long max_sum = window_sum;

    for (int i = k; i < (int)nums.size(); i++) {
        window_sum += nums[i];
        window_sum -= nums[i - k];

        if (window_sum > max_sum)
            max_sum = window_sum;
    }

    return (double)max_sum / k;
}

void runAvg() {
    vector<int> nums = {1,12,-5,-6,50,3};
    cout << findMaxAverage(nums, 4) << endl;
}