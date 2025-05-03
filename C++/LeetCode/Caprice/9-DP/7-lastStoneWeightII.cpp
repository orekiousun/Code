//
// Created by ousun on 2025/5/2.
// 最后一块石头的重量II：https://www.programmercarl.com/1049.%E6%9C%80%E5%90%8E%E4%B8%80%E5%9D%97%E7%9F%B3%E5%A4%B4%E7%9A%84%E9%87%8D%E9%87%8FII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 最后一块石头的重量II：https://leetcode.cn/problems/last-stone-weight-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include<numeric>

// 本质上的问题是把石头分为两组，使两边的差值最小
int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int bagSize = sum / 2;
    int len = stones.size();
    // dp[i][j]的意义为使用前i个石头，容量为j的背包，最多可以背的最大重量
    vector<vector<int>> dp(len, vector<int>(bagSize + 1));
    for (int i = 0; i < len; ++i) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= bagSize; ++i) {
        dp[0][i] = i >= stones[0] ? stones[0] : 0;
    }
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j <= bagSize; ++j) {
            if (j >= stones[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return sum - 2 * dp[len - 1][bagSize];
}

int lastStoneWeightII2(vector<int>& stones) {
    // dp[i][j]的意义为使用前i个石头，容量为j的背包，最多可以背的最大重量
    vector<int> dp(15001, 0);
    int sum = 0;
    for (int i = 0; i < stones.size(); i++) sum += stones[i];
    int target = sum / 2;
    for (int i = 0; i < stones.size(); i++) { // 遍历物品
        for (int j = target; j >= stones[i]; j--) { // 遍历背包
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - dp[target] - dp[target];
}

int main() {
    vector<int> stones{2,7,4,1,8,1};
    cout << lastStoneWeightII(stones);
    return 0;
}
