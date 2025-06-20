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
    vector<vector<int>> path(len + 1, vector<int>(capacity + 1, 0));
    for (int i = 1; i <= len; ++i) {
        // 记录本次采纳的次数
        int cnt = 0;
        for (int j = 0; j <= capacity; ++j) {
            // 必须从前往后更新，这样同一个物体就可以被放进去多次
            if (j >= weight[i - 1] && dp[j - weight[i - 1]] + value[i - 1] > dp[j]) {
                cnt ++;
                dp[j] = dp[j - weight[i - 1]] + value[i - 1];
                path[i][j] = cnt;
            }
        }
    }

    // 重建路径
    vector<int> retPath;
    int curLen = len, curCapacity = capacity;
    while (curLen > 0 && curCapacity > 0) {
        int cnt = path[curLen][curCapacity];
        while (cnt --)
            retPath.push_back(curLen - 1), curCapacity -= weight[curLen - 1];
        curLen--;
    }
    for (int i = 0; i < retPath.size(); ++i) {
        cout << retPath[i] << " ";
    }
    cout << endl;

    return dp[capacity];
}

int main() {
    vector<int> weight{1,2,3,4};
    vector<int> value{2,4,4,5};
    cout << fullBag1(weight, value, 5) << endl;
    return 0;
}
