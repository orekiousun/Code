#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。也就是说，你最多可以买 k 次，卖 k 次。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    buy[i][j]: 恰好进行j笔交易，并且当前手上持有一支股票，这种情况下的最大利润
    sell[i][j]: 恰好进行j笔交易，并且当前手上不持有股票，这种情况下的最大利润
    状态转移方程：
        buy[i][j]
        -- 第i天买入：buy[i][j] = sell[i-1][j] - prices[i]
        -- 不是第i天买入：buy[i][j] = buy[i - 1][j]
        sell[i][j]
        -- 第i天卖出：buy[i-1][j-1] + prices[i]
        -- 不是第i天卖出：sell[i-1][j]
 */

int maxProfit(int k, vector<int>& prices) {
    if (prices.empty())
        return 0;

    int n = prices.size();
    k = min(k, n / 2);
    vector<vector<int>> buy(n, vector<int>(k + 1));
    vector<vector<int>> sell(n, vector<int>(k + 1));

    // 初始化
    buy[0][0] = -prices[0];
    sell[0][0] = 0;
    for (int i = 1; i <= k ; ++i) {
        buy[0][i] = sell[0][i] = INT_MIN / 2;
    }

    for (int i = 1; i < n; ++i) {
        buy[i][0] = max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
        for (int j = 1; j <= k; ++j) {
            buy[i][j] = max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
            sell[i][j] = max(sell[i - 1][j], buy[i - 1][j - 1] + prices[i]);
        }
    }

    return *max_element(sell[n - 1].begin(), sell[n - 1].end());
}


int main() {
    vector<int> prices{1,4,7,5,6,2,5,1,9};
    cout << maxProfit(3, prices) << endl;
    return 0;
}
