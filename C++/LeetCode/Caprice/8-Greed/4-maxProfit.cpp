//
// Created by cd_ouymh on 2025/4/30.
// 买卖股票的最佳时机II：https://www.programmercarl.com/0122.%E4%B9%B0%E5%8D%96%E8%82%A1%E7%A5%A8%E7%9A%84%E6%9C%80%E4%BD%B3%E6%97%B6%E6%9C%BAII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 买卖股票的最佳时机II：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
//

#include <iostream>
using namespace std;
#include <vector>

// 还在递增就继续持有
int maxProfit(vector<int>& prices) {
    int ret = 0;
    // 递增就累加收益，下降就结束
    for (int i = 1; i < prices.size(); ++i) {
        ret += max(prices[i] - prices[i - 1], 0);
    }
    return ret;
}

int main() {
    vector<int> prices{7,1,15,3,6,4};
    cout << maxProfit(prices) << endl;
    return 0;
}