#include <iostream>
#include <vector>

int LIS(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);  // Initialize all elements with 1

    // Compute the LIS values for each index
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    // Find the maximum LIS value
    int maxLIS = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] > maxLIS) {
            maxLIS = dp[i];
        }
    }

    return maxLIS;
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    int length = LIS(nums);
    std::cout << "Length of the Longest Increasing Subsequence: " << length << std::endl;

    return 0;
}