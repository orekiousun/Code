//
// Created by ousun on 2025/11/21.
// 最长递增子序列的个数：https://www.programmercarl.com/0673.%E6%9C%80%E9%95%BF%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97%E7%9A%84%E4%B8%AA%E6%95%B0.html#%E6%80%9D%E8%B7%AF
// 最长递增子序列的个数：https://leetcode.cn/problems/number-of-longest-increasing-subsequence/
// 

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

int findNumberOfLIS(vector<int>& nums) {
    int size = nums.size();
    if (size <= 1) return size;
    // i之前（包括i）最长递增子序列的长度为dp[i]
    vector<int> dp(size, 1);
    // 以nums[i]为结尾字符串，最长递增子序列个数为count[i]
    vector<int> count(size, 1);
    int maxLen = 0;
    for (int i = 1; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    // 最长递增子序列的长度更新了，响应的个数也随之更新
                    dp[i] = dp[j] + 1;
                    count[i] = count[j];
                } else if (dp[j] + 1 == dp[i]) {
                    count[i] += count[j];
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
    }
    int result = 0; // 统计结果
    for (int i = 0; i < nums.size(); i++) {
        if (maxLen == dp[i]) result += count[i];
    }
    return result;
}

int main() {
    vector<int> nums{1,3,5,4,7};
    cout << findNumberOfLIS(nums) << endl;
    return 0;
}