//
// Created by ousun on 2025/5/2.
// 完全背包：https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85.html#%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 完全背包-2维数组做法
// 有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。
// 和 0-1 背包的区别是每件物品有无限个
int fullBag2(vector<int>& weight, vector<int>& value, int capacity) {
    int len = weight.size();
    // i,j表示使用前i个物品装j容量的背包的最大价值
    int dp[len + 1][capacity + 1];
    for (int i = 0; i <= capacity; ++i) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (j >= weight[i - 1])
                // 选择装或者不装第i个物品的最大价值
                // 注意这里和0-1背包的区别是，max的第二个参数的开头是dp[i]不是dp[i-1]，表示第i个可以重复用
                // 由于是从前往后更新的，所以dp[i][j - weight[i - 1]]一定更新过了
                dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1]] + value[i - 1]);
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[len][capacity];
}

// 完全背包-1维数组实现
int fullBag1(vector<int>& weight, vector<int>& value, int capacity) {
    int len = weight.size();
    vector<int> dp(capacity + 1, 0);
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (j >= weight[i - 1]) dp[j] = max(dp[j], dp[j - weight[i - 1]] + value[i - 1]);
        }
    }

    return dp[capacity];
}

// 完全背包-多次遍历的方式，这种方法性能开销较大，舍去
// 有N件物品和一个最多能背重量为W的背包。第i件物品的重量是weight[i]，得到的价值是value[i] 。每件物品都有无限个（也就是可以放入背包多次），求解将哪些物品装入背包里物品价值总和最大。
// 和 0-1 背包的区别是每件物品有无限个
// 处理方式：只要容量放得下，就去遍历所有可以塞的情况
int fullBagBan(vector<int>& weight, vector<int>& value, int capacity) {
    int len = weight.size();
    vector<int> dp(capacity + 1, 0);
    for (int i = 1; i <= len; ++i) {
        for (int j = capacity; j >= weight[i - 1]; j--) {
            // 处理方式1：只要容量放得下，就去遍历所有可以塞的情况
            int cnt = j / weight[i - 1];
//            dp[j] = dp[j];  // 更新为上一个，一维数组可与忽略这一步
            for (int k = 1; k <= cnt; ++k) {
                dp[j] = max(dp[j], dp[j - k * weight[i - 1]] + value[i - 1] * k);
            }
        }
    }

    return dp[capacity];
}



int main() {
    vector<int> weight{2,2,3,1,5,2};
    vector<int> value{2,3,1,5,4,3};
    return 0;
}
