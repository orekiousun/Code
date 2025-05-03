//
// Created by ousun on 2025/5/2.
// 分割等和子集：https://www.programmercarl.com/0416.%E5%88%86%E5%89%B2%E7%AD%89%E5%92%8C%E5%AD%90%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 分割等和子集：https://leetcode.cn/problems/partition-equal-subset-sum/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include<numeric>

// 问题装换为，能否把容量为sum/2的背包填满
bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 == 1) return false;

    int bagSize = sum / 2;
    int len = nums.size();
    // dp[i][j]表示使用前i个数字，是否能填满容量为j的背包
    bool dp[len][bagSize + 1];
    for (int i = 0; i < len; ++i) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= bagSize; ++i) {
        dp[0][i] = nums[0] == i ? true : false;
    }
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j <= bagSize; ++j) {
            if (j >= nums[i])
                dp[i][j] = dp[i - 1][j] or dp[i - 1][j - nums[i]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[len - 1][bagSize];
}

int main() {
    return 0;
}
