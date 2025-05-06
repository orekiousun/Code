//
// Created by ousun on 2025/5/2.
// 背包：https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%8001%E8%83%8C%E5%8C%85-1.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 01背包
// 可以优化为1维数组，利用一个数组把dp[i - 1][.]缓存起来即可
// 有n件物品和一个最多能背重量为w 的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品只能用一次，求解将哪些物品装入背包里物品价值总和最大。
int bag(vector<int>& weight, vector<int>& value, int capacity) {
    int len = weight.size();
    // i,j表示使用前i个物品装j容量的背包的最大价值
    vector<vector<int>> dp(len + 1, vector<int>(capacity + 1, 0));
    // 用于记录每次的选择
    vector<vector<bool>> path(len + 1, vector<bool>(capacity + 1, false));
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]) {
                // 选择装或者不装第i个物品的最大价值
                int tmp = dp[i - 1][j - weight[i - 1]] + value[i - 1];
                if (tmp > dp[i - 1][j]) {
                    dp[i][j] = tmp;
                    // 记录路径
                    path[i][j] = true;
                }
            }
        }
    }

    // 打印结果集合
    vector<int> retPath;
    int curLen = len, curCapacity = capacity;
    while (curLen > 0 && curCapacity > 0) {
        if (path[curLen][curCapacity])
            retPath.push_back(curLen - 1), curCapacity -= weight[curLen - 1];
        curLen--;
    }
    for (int i = 0; i < retPath.size(); ++i) {
        cout << retPath[i] << " ";
    }
    cout << endl;

    return dp[len][capacity];
}

// 01背包 - 一维数组实现
int bag2(vector<int>& weight, vector<int>& value, int capacity) {
    int len = weight.size();
    // i,j表示使用前i个物品装j容量的背包的最大价值
    int dp[capacity + 1];
    for (int j = 0; j <= capacity; ++j) {
        dp[j] = j >= weight[0] ? value[0] : 0;
    }
    for (int i = 1; i < len; ++i) {
        // 需要从后往前遍历，因为从前往后的话，前面的结果可能已经装了当前的物品了
        // 也可以拷贝一个之前的数据来用
        for (int j = capacity; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    return dp[capacity];
}

int main() {
    vector<int> weight{2,2,3,1,5,2};
    vector<int> value{2,3,1,5,4,3};
    cout << bag(weight, value, 12) << endl;
    return 0;
}
