//
// Created by ousun on 2025/5/2.
// 一和零：https://www.programmercarl.com/0474.%E4%B8%80%E5%92%8C%E9%9B%B6.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 一和零：https://leetcode.cn/problems/ones-and-zeroes/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

int findMaxForm(vector<string>& strs, int m, int n) {
    int len = strs.size();
    // dp[i][j][k]表示使用前i个字符串，最多有j个0和k个1的最大子集个数
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= len; ++i) {
        // 统计里面0和1的个数
        int cnt0 = 0 , cnt1 = 0;
        string str = strs[i - 1];
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == '0') cnt0++;
            if (str[j] == '1') cnt1++;
        }
        for (int j = m; j >= cnt0; j--) {
            for (int k = n; k >= cnt1; k--) {
                dp[j][k] = max(dp[j][k], dp[j - cnt0][k - cnt1] + 1);
            }
        }
    }

    return dp[m][n];
}

int main() {
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    cout << findMaxForm(strs, 5, 3) << endl;
    return 0;
}