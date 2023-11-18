#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？

    [7, 1, 5, 3, 6, 4]
       -6  4  2  5  3

    方法：
        动态规划，记录前i日的最小值，每次计算在第i天卖出时的最大利润
*/

int maxProfit(vector<int>& prices) {
    int minNum = prices[0], maxNum = prices[1] - prices[0];
    for (int i = 1; i < prices.size(); i++) {
        maxNum = max(maxNum, prices[i] - minNum);
        minNum = min(minNum, prices[i]);
    }
    return maxNum;
}

int main(int argc, char const *argv[]) {
    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl; 
    return 0;
}
