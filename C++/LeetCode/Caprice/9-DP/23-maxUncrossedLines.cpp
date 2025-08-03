//
// Created by ousun on 2025/8/3.
// 不相交的线：https://www.programmercarl.com/1035.%E4%B8%8D%E7%9B%B8%E4%BA%A4%E7%9A%84%E7%BA%BF.html
// 不相交的线：https://leetcode.cn/problems/uncrossed-lines/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 和最长公共子串一个做法
int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();

    vector<vector<int>> dp(size1 + 1, vector<int>(size2 + 1, 0));
    for (int i = 1; i <= size1; ++i) {
        for (int j = 1; j <= size2; ++j) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[size1][size2];
}

int main() {
    return 0;
}
