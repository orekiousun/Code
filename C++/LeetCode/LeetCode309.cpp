#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
    设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
    卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
    注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
*/

// O(n^2) 好理解
int maxProfit(vector<int>& prices) {
    int size = prices.size();
    if(size == 1) return 0;
    vector<int> dp(size, 0);
    vector<int> maxElement(size, 0);
    for (int i = 1; i < size; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if(prices[j] < prices[i]) {
                if(j >= 2)
                    dp[i] = max(dp[i], maxElement[j - 2] + prices[i] - prices[j]);
                else 
                    dp[i] = max(dp[i], prices[i] - prices[j]);
            }
        }
        maxElement[i] = max(maxElement[i - 1], dp[i]);
    }
    return maxElement[size - 1];
}

// 官方题解 O(n) 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int f0 = -prices[0];
        int f1 = 0;
        int f2 = 0;
        // f0: 手上持有股票的最大收益
        // f1: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // f2: 手上不持有股票，并且不在冷冻期中的累计最大收益
        for (int i = 1; i < n; ++i) {
            // f0：目前持有的这一支股票可以是在第i−1天就已经持有的，或者是第i天买入的
            int newf0 = max(f0, f2 - prices[i]);
            // f1：处于冷冻期的原因是在当天卖出了股票，那么说明在第i−1天时我们必须持有一支股票
            int newf1 = f0 + prices[i];
            // f2：第i−1天时不持有任何股票，如果第i-1天处于冷冻期，则为f1，如果第i-1天不处于冷冻期，则为f2
            int newf2 = max(f1, f2);
            f0 = newf0;
            f1 = newf1;
            f2 = newf2;
        }
        return max(f1, f2);
    }
};

int main() {
    vector<int> prices{1,7,2,4};
    cout << maxProfit(prices) << endl;
    system("pause");
    return 0;
}