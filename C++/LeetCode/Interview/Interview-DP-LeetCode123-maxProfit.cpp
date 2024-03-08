#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
    设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

    二维动态规划dp[i][j]表示在i处买入，j之前卖出获得的最大收益
    dp[i][j] = max(dp[i][j - 1], prices[j] - prices[i])
 */

//
int maxProfit(vector<int>& prices) {
    int size = prices.size();

    // record[k]表示在k天前买卖一张股票所能获得的最大收益
    vector<int> record(size + 1, 0);
    int minNum = 0x7fffffff;
    for (int i = 1; i <= size; ++i) {
        minNum = min(minNum, prices[i - 1]);
        record[i] = max(prices[i - 1] - minNum, record[i - 1]);
    }

    // dp[i][j]表示第i天买入，第j天前卖出获得的最大收益
    vector<vector<int>> dp(size + 1, vector<int>(size + 1));
    int res = 0;
    for (int i = 1; i <= size; ++i) {
        for (int j = i; j <= size; ++j) {
            dp[i][j] = max(dp[i][j - 1], prices[j - 1] - prices[i - 1]);
            res = max(res, record[i - 1] + dp[i][j]);
        }
    }
    return res;
}

// 内存优化，不开辟二维数组实现
int maxProfit2(vector<int>& prices) {
    int size = prices.size();

    // record[k]表示在k天前买卖一张股票所能获得的最大收益
    vector<int> record(size + 1, 0);
    int minNum = 0x7fffffff;
    for (int i = 1; i <= size; ++i) {
        minNum = min(minNum, prices[i - 1]);
        record[i] = max(prices[i - 1] - minNum, record[i - 1]);
    }

    // dp[i][j]表示第i天买入，第j天前卖出获得的最大收益
    int pre;
    vector<int> dp(size + 1, 0);
    int res = 0;
    for (int i = 1; i <= size; ++i) {
        pre = 0;
        for (int j = i; j <= size; ++j) {
            dp[j] = max(pre, prices[j - 1] - prices[i - 1]);
            pre = dp[j];
            res = max(res, record[i - 1] + dp[j]);
        }
    }
    return res;
}

// 内存+时间优化，用两个一维动态规划
int maxProfit3(vector<int>& prices) {
    int size = prices.size();

    // maxProfitBefore[k]表示在k天前买卖一张股票所能获得的最大收益
    vector<int> maxProfitBefore(size + 1, 0);
    int minNum = 0x7fffffff;
    for (int i = 1; i <= size; ++i) {
        minNum = min(minNum, prices[i - 1]);
        maxProfitBefore[i] = max(prices[i - 1] - minNum, maxProfitBefore[i - 1]);
    }

    // maxNumAfter[k]记录在k天之后的股票最大值
    vector<int> maxNumAfter(size, 0);
    int maxNum = 0;
    for (int i = size - 1; i >= 0; --i) {
        maxNum = max(maxNum, prices[i]);
        maxNumAfter[i] = maxNum;
    }

    int res = 0;
    for (int i = 1; i <= size; ++i) {
        res = max(res, maxProfitBefore[i - 1] + maxNumAfter[i - 1] - prices[i - 1]);
    }

    return res;
}

int main() {
    vector<int> prices{5, 0, 0, 3, 1, 4};
    cout << maxProfit3(prices) << endl;
    return 0;
}