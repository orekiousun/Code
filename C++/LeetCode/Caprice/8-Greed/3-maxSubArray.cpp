//
// Created by cd_ouymh on 2025/4/30.
// 最大子数组和：https://www.programmercarl.com/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C.html
// 最大子数组和：https://leetcode.cn/problems/maximum-subarray/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 动态规划
int maxSubArrayDynamic(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int ret = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        ret = max(ret, dp[i]);
    }
    return ret;
}

// 贪心
int maxSubArrayGreed(vector<int>& nums) {
    int ret = INT32_MIN;
    int add = 0;
    for (int i = 0; i < nums.size(); i++) {
        add += nums[i];
        ret = max(ret, add);
        if (add <= 0) add = 0; // 相当于重置最大子序起始位置，因为遇到负数一定是拉低总和
    }
    return ret;
}

int main() {
    return 0;
}