//
// Created by ousun on 2025/7/27.
// 最长递增子序列：https://www.programmercarl.com/0300.%E6%9C%80%E9%95%BF%E4%B8%8A%E5%8D%87%E5%AD%90%E5%BA%8F%E5%88%97.html
// 最长递增子序列：https://leetcode.cn/problems/longest-increasing-subsequence/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// O(n^2)解法，要求不连续递增
int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    // dp[i]表示以i结尾的最长字串长度
    vector<int> dp(size, 1);
    int ret = 1;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ret = max(ret, dp[i]);
    }
    return ret;
}

// 要求连续递增
int findLengthOfLCIS(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) return 0;
    // dp[i]表示以i结尾的最长字串长度
    vector<int> dp(size, 1);
    int ret = 1;
    for (int i = 1; i < size; ++i) {
        if (nums[i] > nums[i - 1])
            dp[i] = dp[i - 1] + 1;
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {

    return 0;
}