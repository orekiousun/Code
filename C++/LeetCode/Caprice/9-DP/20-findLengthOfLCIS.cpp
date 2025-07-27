//
// Created by ousun on 2025/7/27.
// 最长连续递增序列：https://www.programmercarl.com/0674.%E6%9C%80%E9%95%BF%E8%BF%9E%E7%BB%AD%E9%80%92%E5%A2%9E%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 最长连续递增序列：https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

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