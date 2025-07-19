//
// Created by ousun on 2025/7/13.
// 买卖股票的最佳时机：https://www.programmercarl.com/0121.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BA.html
// 买卖股票的最佳时机：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/
// 买卖股票的最佳时机II：https://www.programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII%EF%BC%88%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%EF%BC%89.html
// 买卖股票的最佳时机II：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
// 买卖股票的最佳时机III：https://www.programmercarl.com/0123.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 买卖股票的最佳时机III：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
// 买卖股票的最佳时机IV：https://www.programmercarl.com/0188.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAIV.html
// 买卖股票的最佳时机IV：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
// 买卖股票的最佳时间含冷冻期：https://www.programmercarl.com/0309.%E6%9C%80%E4%BD%B3%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E6%97%B6%E6%9C%BA%E5%90%AB%E5%86%B7%E5%86%BB%E6%9C%9F.html
// 买卖股票的最佳时间含冷冻期：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
//

#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

int maxProfit(vector<int> &prices) {
    int minVal = prices[0];
    int ret = 0;
    for (int i = 0; i < prices.size(); ++i) {
        minVal = min(minVal, prices[i]);
        ret = max(ret, prices[i] - minVal);
    }
    return ret;
}

// 可以重复购买和卖出，但是同一时间只能持有一支股票
// 算所有递增的，只要在递增就买
int maxProfitII(vector<int> &prices) {
    int ret = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i] >= prices[i - 1])
            ret += prices[i] - prices[i - 1];
    }
    return ret;
}

// 可以进行两笔交易，但是同一时间只能持有一支股票
int maxProfitIII(vector<int> &prices) {
    // dp[i][j]表示在第i-j数组范围内，购买一支股票所能获得的最大利润
    // 修改为先计算前缀数组，再算i-size-1
    int size = prices.size();
    int minVal = prices[0];
    vector<int> preDp(size, 0);
    for (int i = 1; i < size; ++i) {
        minVal = min(minVal, prices[i]);
        preDp[i] = max(preDp[i - 1], prices[i] - minVal);
    }

    int ret = preDp[size - 1];
    int maxVal = prices[size - 1];
    for (int i = size - 1; i >= 1; --i) {
        maxVal = max(maxVal, prices[i]);
        ret = max(ret, preDp[i - 1] + maxVal - prices[i]);
    }

    return ret;
}

// 所有股票类问题都可以通过此状态方法解决
int maxProfitIII2(vector<int> &prices) {
    int size = prices.size();
    if (size == 0)  return 0;
    // 0-无操作
    // 1-第一次持有股票
    // 2-第一次不持有股票
    // 3-第二次持有股票
    // 4-第二次不持有股票
    // dp[i][j]表示前i只股票处于j状态的最大现金数
    vector<vector<int>> dp(size, vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < size; ++i) {
        dp[i][0] = dp[i - 1][0];
        // 第一次持有股票：1-前一天就持有 2-今天才持有
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        // 第一次不持有股票：1-前一天就不持有状态 2-今天才不持有
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        // 第二次持有股票：1-前一天就持有 2-今天才持有
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        // 第二次不持有股票：1-前一天就不持有 2-今天才不持有
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[size - 1][4];
}

// 最多买k次22
int maxProfitIV(int k, vector<int>& prices) {
    int size = prices.size();
    if (size == 0) return 0;
    // 0-无操作
    // 2n+1 第n次持有股票
    // 2n+2 第n次不持有股票
    vector<vector<int>> dp(size, vector<int>(2 * k + 1, 0));
    for (int i = 0; i < k; i++) {
        dp[0][2 * i + 1] = -prices[0];
    }
    for (int i = 1; i < size; ++i) {
        dp[i][0] = dp[i - 1][0];
        for (int j = 0; j < k; j++) {
            // 第j次持有股票：1-前一天就持有，2-今天才持有
            dp[i][2 * j + 1] = max(dp[i - 1][2 * j + 1], dp[i - 1][2 * j] - prices[i]);
            // 第j次不持有股票：1-前一天就不持有，2-今天才不持有
            dp[i][2 * j + 2] = max(dp[i - 1][2 * j + 2], dp[i - 1][2 * j + 1] + prices[i]);       
        }
    }
    return dp[size - 1][2 * k];
}

// 含1天冷冻期
int maxProfitWithCd(vector<int>& prices) {
    int size = prices.size();
    if (size == 0) return 0;
    // 状态转移
    // 0-持有股票
    // 1-不持有股票，且处于冷冻期
    // 2-不持有股票，且不处于冷冻期
    vector<vector<int>> dp(size, vector<int>(3, 0));
    dp[0][0] = -prices[0];
    for (int i = 1; i < size; i++) {
        // 持有股票：1-前一天持有 2-今天才持有
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        // 不持有股票，且处于冷冻期：前一天卖出
        dp[i][1] = dp[i - 1][0] + prices[i];
        // 不持有股票，且不处于冷冻期：1-前一天就不持有且处于不处于冷冻期 2-前一天不持有且处于冷冻期
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1]);
    }
    return max(dp[size - 1][1], dp[size - 1][2]);
}

int maxProfitWithFee(vector<int>& prices, int fee) {
    int size = prices.size();
    if (size == 0) return 0;
    // 状态转移
    // 0-持有股票
    // 1-不持有股票
    vector<vector<int>> dp(size, vector<int>(2, 0));
    dp[0][0] = -prices[0] - fee;
    for (int i = 1; i < size; ++i) {
        // 持有股票: 1-前一天持有 2-今天才持有
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i] - fee);
        // 不持有股票：1-前一天就不持有 2-今天刚卖出
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }
    return dp[size - 1][1];
}

int main() {
    vector<int> prices{3,3,5,0,0,3,1,4};
    cout << maxProfitIII(prices) << endl;
    return 0;
}
