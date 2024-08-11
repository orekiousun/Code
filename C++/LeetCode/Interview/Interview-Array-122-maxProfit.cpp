//
// Created by ousun on 2024/8/10.
// 只能买一次，卖一次: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
// 可以买卖多次，但是只能持有一只股票: https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
//
#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/?envType=study-plan-v2&envId=top-interview-150
// 只能买一次，卖一次
// 1.单调栈：记录买卖的最大值
// 2.1次遍历，记录左侧的最小值，用新加进来的值减去最小值
int maxProfit(vector<int>& prices) {
    stack<int> s;
    int ret = 0;
    int bottom = prices[0];
    for(auto price : prices) {
        while ((!s.empty()) && price < s.top()) {
            s.pop();
        }
        if (s.empty())
            bottom = price;
        s.push(price);
        ret = max(ret, price - bottom);
    }
    return ret;
}

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
// 可以买卖多次，但是只能持有一只股票
// 单调栈：单调向上的就卖掉，向下就重新买入
int maxProfit2(vector<int>& prices) {
    stack<int> s;
    int ret = 0;
    int pre;
    for(auto price : prices) {
        while ((!s.empty()) && price < s.top()) {
            s.pop();
        }
        pre = s.empty() ? price : pre;
        s.push(price);
        ret += max(price - pre, 0);
        pre = price;
    }
    return ret;
}

// https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/?envType=study-plan-v2&envId=top-interview-150
// 贪心思路，更简单，认为是多个买与卖的操作，只要能赚钱就卖掉
int maxProfit3(vector<int>& prices) {
    int ans = 0;
    int n = prices.size();
    for (int i = 1; i < n; ++i) {
        ans += max(0, prices[i] - prices[i - 1]);
    }
    return ans;
}

int main() {
    vector<int> prices{7,1,5,3,6,4};
    int ret = maxProfit2(prices);
    cout << ret << endl;
    return 0;
}