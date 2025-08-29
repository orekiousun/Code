//
// Created by ousun on 2025/8/17.
// 回文子串：https://www.programmercarl.com/0647.%E5%9B%9E%E6%96%87%E5%AD%90%E4%B8%B2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 回文子串：https://leetcode.cn/problems/palindromic-substrings/
// 最长回文子序列：https://www.programmercarl.com/0516.%E6%9C%80%E9%95%BF%E5%9B%9E%E6%96%87%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 最长回文子序列：https://leetcode.cn/problems/longest-palindromic-subsequence/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool check(string &s, int begin, int end) {
    for (int i = 0; i <= (end - begin) / 2; ++i) {
        if (s[i + begin] != s[end - i])
            return false;
    }
    return true;
}

// 暴力解法
int countSubstrings(string s) {
    int ret = 0;
    for (int i = 1; i <= s.size(); ++i) {
        for (int j = 0; j <= s.size() - i; ++j) {
            if (check(s, j, j + i - 1))
                ret++;
        }
    }
    return ret;
}

// 动态规划
int countSubstrings2(string s) {
    int size = s.size();
    int ret = 0;
    vector<vector<bool>> dp(size, vector<bool>(size, false));
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i; j < size; ++j) {
            if (i == j) {
                dp[i][j] = true, ret += 1;
            }
            else if(s[i] == s[j]) {
                if (j - i == 1)
                    dp[i][j] = true, ret += 1;
                else if(dp[i + 1][j - 1])
                    dp[i][j] = true, ret += 1;
            }
        }
    }
    return ret;
}

int longestPalindromeSubseq(string s) {
    int size = s.size();
    int ret = 0;
    // dp[i][j]表示i到j范围内最长回文子序列的长度
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i; j < size; ++j) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else if(s[i] == s[j]) {
                if (j - i == 1)
                    dp[i][j] = 2;
                else
                    dp[i][j] = dp[i + 1][j - 1] + 2;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int longestPalindromeSubseq2(string s) {
    int size = s.size();
    int ret = 1;
    // dp[i][j]表示i到j范围内最长回文子序列的长度
    vector<vector<int>> dp(size, vector<int>(size, 0));
    // 简化数组初始化
    for (int i = 0; i < size; ++i) dp[i][i] = 1;
    for (int i = size - 1; i >= 0; i--) {
        for (int j = i + 1; j < size; ++j) {
            if(s[i] == s[j])
                dp[i][j] = dp[i + 1][j - 1] + 2;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int main() {
    cout << longestPalindromeSubseq("bbbab") << endl;
    return 0;
}
