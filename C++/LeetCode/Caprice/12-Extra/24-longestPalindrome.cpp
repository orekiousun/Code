//
// Created by ousun on 2025/10/24.
// 最长回文子串：https://www.programmercarl.com/0005.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html
// 最长回文子串：https://leetcode.cn/problems/longest-palindromic-substring/
//

#include <iostream>
using namespace std;
#include <vector>

string longestPalindrome(string s) {
    int size = s.size();
    if (size <= 1) return s;
    // dp[i][j] 长度为i，以j索引开头的字符串是否为回文字符串
    vector<vector<bool>> dp(size + 1, vector<bool>(size, false));
    // 长度为0和1的默认都是回文
    for (int i = 0; i < size; i++) {
        dp[0][i] = true;
        dp[1][i] = true;
    }
    for (int i = 2; i <= size; i++)
    {
        for (int j = 0; j + i - 1 < size; j++)
        {
            if (s[j] != s[j + i - 1])
                dp[i][j] = false;
            else
                dp[i][j] = dp[i - 2][j + 1];
        }
    }
    // 最后再计算一下结果返回
    for (int i = size; i >= 0; i--) {
        for (int j = 0; j < size; j++)
        {
            if (dp[i][j])
                return s.substr(j, i);
        }
    }
    return "";
}

int main() {
    cout << longestPalindrome("babad") << endl;
    return 0;
}