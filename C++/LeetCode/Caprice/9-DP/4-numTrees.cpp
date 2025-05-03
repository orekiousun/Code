//
// Created by ousun on 2025/5/2.
// 不同的二叉搜索树：https://www.programmercarl.com/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 不同的二叉搜索树：https://leetcode.cn/problems/unique-binary-search-trees/
//

#include <iostream>
using namespace std;
#include <vector>

int numTrees(int n) {
    if (n == 1) return 1;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = 0;
        for (int j = 0; j < i; ++j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    return dp[n];
}

int main() {
    return 0;
}