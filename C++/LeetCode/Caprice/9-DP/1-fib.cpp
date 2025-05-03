//
// Created by ousun on 2025/5/2.
// 斐波那契数：https://www.programmercarl.com/0509.%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 斐波那契数：https://leetcode.cn/problems/fibonacci-number/
// 爬楼梯：https://www.programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.html
// 爬楼梯：https://leetcode.cn/problems/climbing-stairs/
// 使用最小花费爬楼梯：https://www.programmercarl.com/0746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.html
// 使用最小花费爬楼梯：https://leetcode.cn/problems/min-cost-climbing-stairs/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 内存可优化
// 斐波那契数：https://leetcode.cn/problems/fibonacci-number/
int fib(int n) {
    if (n == 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 内存可优化
// 爬楼梯：https://leetcode.cn/problems/climbing-stairs/
int climbStairs(int n) {
    if (n == 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// 内存可优化
// 使用最小花费爬楼梯：https://leetcode.cn/problems/min-cost-climbing-stairs/
int minCostClimbingStairs(vector<int>& cost) {
    int len = cost.size();
    if (len == 0) return 0;
    vector<int> dp(len + 1, 0);
    dp[0] = 0, dp[1] = 0;
    for (int i = 2; i <= len; ++i) {
        dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    }
    return dp[len];
}

int main() {
    cout << fib(10) << endl;
    return 0;
}
