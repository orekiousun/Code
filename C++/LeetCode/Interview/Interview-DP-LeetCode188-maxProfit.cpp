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

}


int main() {
    vector<int> prices{1,4,7,5,6,2,5,1,9};
    cout << maxProfit(3, prices) << endl;
    return 0;
}
