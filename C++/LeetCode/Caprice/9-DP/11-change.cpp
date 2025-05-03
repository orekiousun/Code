//
// Created by ousun on 2025/5/2.
// 零钱兑换II：https://www.programmercarl.com/0518.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 零钱兑换II：https://leetcode.cn/problems/coin-change-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int change(int amount, vector<int>& coins) {
    int len = coins.size();
    // dp[i][j]表示使用前i个硬币组成j金额的组合方式总数
    vector<uint64_t> dp(amount + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= len; ++i) {
        int coin = coins[i - 1];
        for (int j = coin; j <= amount; ++j) {
//            if (dp[j] < INT_MAX - dp[j - coins[i]])  // 防止相加数据超int
            // dp[i][j] = 不用第i个的次数 + 用第i个的次数
            // dp[i][j] = dp[i - 1][j] + dp[i][j - coin]
            dp[j] = dp[j] + dp[j - coin];
        }
    }
    return dp[amount];
}

int main() {
    return 0;
}