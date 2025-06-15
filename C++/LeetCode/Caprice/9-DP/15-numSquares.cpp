//
// Created by ousun on 2025/6/15.
// 完全平方数：https://www.programmercarl.com/0279.%E5%AE%8C%E5%85%A8%E5%B9%B3%E6%96%B9%E6%95%B0.html
// 完全平方数：https://leetcode.cn/problems/perfect-squares/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int numSquares(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = dp[i] == 0 ? dp[i - j * j] + 1 : min(dp[i], dp[i - j * j] + 1);
        }
    }
    return dp[n];
}

int main() {
    return 0;
}