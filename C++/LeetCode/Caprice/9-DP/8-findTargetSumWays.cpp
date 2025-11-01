//
// Created by ousun on 2025/5/2.
// 目标和：https://www.programmercarl.com/0494.%E7%9B%AE%E6%A0%87%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 目标和：https://leetcode.cn/problems/target-sum/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include<numeric>

int findTargetSumWays(vector<int>& nums, int target) {
    // 这里需要注意的是，还需要关注是负数的情况
    // 先统一求和，使用j索引的时候都加个和再用
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (target > sum || target < -sum) return 0;
    int len = nums.size();
    // dp[i][j]表示使用前i个数，运算结果=j的个数
    vector<int> dp(sum * 2 + 1, 0);
    vector<int> pre = dp;
    pre[sum] = 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < sum * 2 + 1; ++j) {
            int num = nums[i - 1];
            dp[j] = 0;
            if (j + num < sum * 2 + 1)
                dp[j] += pre[j + num];
            if (j - num >= 0)
                dp[j] += pre[j - num];
        }
        pre = dp;
    }
    return dp[target + sum];
}

int main() {
    vector<int> nums{1,1,1,1,1};
    cout << findTargetSumWays(nums, 3) << endl;
    return 0;
}