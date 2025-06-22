//
// Created by ousun on 2025/6/22.
// 多重背包：https://www.programmercarl.com/%E8%83%8C%E5%8C%85%E9%97%AE%E9%A2%98%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85.html#%E5%A4%9A%E9%87%8D%E8%83%8C%E5%8C%85
// 多重背包：https://kamacoder.com/problempage.php?pid=1066
//
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int bag(vector<int>& weights, vector<int>& prices, int size) {
    int n = weights.size();
    vector<int> dp(size + 1, 0);
    vector<vector<bool>> path(n + 1, vector<bool>(size + 1, false));
    for (int i = 1; i <= n; ++i) {
        for (int j = size; j >= weights[i - 1]; --j) {
            int tmp = dp[j - weights[i - 1]] + prices[i - 1];
            if (tmp > dp[j]) {
                dp[j] = tmp;
                path[i][j] = true;
            }
        }
    }

    int i = n, j = size;
    vector<int> retPath;
    while (i > 0 && j > 0) {
        if (path[i][j]) {
            retPath.push_back(i - 1);
            j -= weights[i - 1];
        }
        i--;
    }

    return dp[size];
}

int main() {
    int size, n;
    cin >> size >> n;
    vector<int> weights, prices;
    int tmpWeights[n];
    int tmpPrices[n];
    int tmpCounts[n];
    for (int i = 0; i < n; ++i) cin >> tmpWeights[i];
    for (int i = 0; i < n; ++i) cin >> tmpPrices[i];
    for (int i = 0; i < n; ++i) cin >> tmpCounts[i];
    for (int i = 0; i < n; ++i) {
        while (tmpCounts[i]--) {
            weights.push_back(tmpWeights[i]);
            prices.push_back(tmpPrices[i]);
        }
    }
    cout << bag(weights, prices, size) << endl;
    return 0;
}