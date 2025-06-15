//
// Created by ousun on 2025/6/15.
// 零钱兑换：https://www.programmercarl.com/0322.%E9%9B%B6%E9%92%B1%E5%85%91%E6%8D%A2.html
// 零钱兑换：https://leetcode.cn/problems/coin-change/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int coinChange(vector<int>& coins, int amount) {
    int size = coins.size();
    vector<int> dp(amount + 1, 0);
    for (int i = 1; i <= amount; ++i) {
        dp[i] = -1;
        for (int j = 0; j < size; ++j) {
            int idx = i - coins[j];
            if (idx >= 0 && dp[idx] != -1)
                dp[i] = dp[i] == -1 ? dp[idx] + 1 : min(dp[i], dp[idx] + 1);
        }
    }
    return dp[amount];
}

int main() {
    return 0;
}