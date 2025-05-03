//
// Created by ousun on 2025/5/2.
// 组合总和IV：https://www.programmercarl.com/0377.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C%E2%85%A3.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 组合总和IV：https://leetcode.cn/problems/combination-sum-iv/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 存在顺序问题
int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1;
    // 由于这里是求排列，所以把遍历背包放在外层，这样每一个索引的节点都会在后面的遍历里被重复访问到
    for (int i = 0; i <= target; i++) { // 遍历背包
        for (int j = 0; j < nums.size(); j++) { // 遍历物品
            if (i - nums[j] >= 0) {
                // 把i放到最后面
                dp[i] += dp[i - nums[j]];
            }
        }
    }
    return dp[target];
}

int main() {
    return 0;
}
