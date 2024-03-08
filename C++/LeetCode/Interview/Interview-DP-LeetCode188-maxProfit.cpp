#include <iostream>
using namespace std;
#include <vector>

/*
    给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    二维动态规划dp[i][j]表示在i处买入，j之前卖出获得的最大收益
    dp[i][j] = max(dp[i][j - 1], prices[j] - prices[i])
 */

int maxProfit(int k, vector<int>& prices) {
    int size = prices.size();

    // dp[i][j]表示第i天买入，第j天前卖出获得的最大收益
    // dp[0][k]记录第k天前卖出时所能获得的最大收益
    vector<vector<int>> dp(size + 1, vector<int>(size + 1));
    vector<int> stackCnt(size + 1, 0);
    int res = 0;
    for (int i = 1; i <= size; ++i) {
        for (int j = i; j <= size; ++j) {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] - prices[i - 1]);
            if (dp[0][i - 1] + dp[i][j] > dp[0][j]) {
                // 记录买卖次数
                stackCnt[j] = stackCnt[i - 1] + 1;
                dp[0][j] = dp[0][i - 1] + dp[i][j];
                if (stackCnt[j] <= k)
                    res = max(res, dp[0][j]);
            }
//            dp[0][j] = max(dp[0][i - 1] + dp[i][j], dp[0][j]);
        }
    }
    return res;
}

// 内存优化 --
int maxProfit2(int k, vector<int>& prices) {
    int size = prices.size();

    // dp[i][j]表示第i天买入，第j天前卖出获得的最大收益
    vector<int> dp(size + 1, 0);
    // maxProfitBefore[k]记录第k天前卖出时所能获得的最大收益
    vector<int> maxProfitBefore(size + 1, 0);
    vector<int> stackCnt(size + 1, 0);
    int res = 0;
    for (int i = 1; i <= size; ++i) {
        for (int j = i; j <= size; ++j) {
            dp[j] = max(dp[j - 1], prices[j - 1] - prices[i - 1]);
            if (maxProfitBefore[i - 1] + dp[j] > maxProfitBefore[j]) {
                // 记录买卖次数
                stackCnt[j] = stackCnt[i - 1] + 1;
                maxProfitBefore[j] = maxProfitBefore[i - 1] + dp[j];
                if (stackCnt[j] <= k)
                    res = max(res, maxProfitBefore[j]);
            }
//            dp[0][j] = max(dp[0][i - 1] + dp[i][j], dp[0][j]);
        }
    }
    return res;
}


int main() {
    vector<int> prices{1, 4, 0, 3, 1, 4};
    cout << maxProfit(2, prices) << endl;
    return 0;
}
