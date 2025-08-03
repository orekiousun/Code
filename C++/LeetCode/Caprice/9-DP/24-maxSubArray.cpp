//
// Created by ousun on 2025/8/3.
// 最大子数组和：https://www.programmercarl.com/0053.%E6%9C%80%E5%A4%A7%E5%AD%90%E5%BA%8F%E5%92%8C%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.html
// 最大子数组和：https://leetcode.cn/problems/maximum-subarray/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maxSubArray(vector<int>& nums) {
    int size = nums.size();
    int ret = nums[0];
    vector<int> dp(size + 1, 0);
    for (int i = 1; i <= size; ++i) {
        dp[i] = max(nums[i - 1], dp[i - 1] + nums[i - 1]);
        ret = max(ret, dp[i]);
    }
    return ret;
}

int main() {
    return 0;
}