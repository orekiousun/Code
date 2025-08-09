//
// Created by ousun on 2025/08/09.
// 两个字符串的删除操作：https://www.programmercarl.com/0583.%E4%B8%A4%E4%B8%AA%E5%AD%97%E7%AC%A6%E4%B8%B2%E7%9A%84%E5%88%A0%E9%99%A4%E6%93%8D%E4%BD%9C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 两个字符串的删除操作：https://leetcode.cn/problems/delete-operation-for-two-strings/
// 编辑距离：https://www.programmercarl.com/0072.%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 编辑距离：https://leetcode.cn/problems/edit-distance/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

int longestCommonSubsequence(string text1, string text2) {
    int ret = 0;
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    for (int i = 1; i <= text1.size(); ++i) {
        for (int j = 1; j <= text2.size(); ++j) {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

// 两个字符串的删除操作
// 给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。
// 本质上是求最长公共子序列的长度
int minDistance(string word1, string word2) {
    int maxLen = longestCommonSubsequence(word1, word2);
    return word1.size() + word2.size() - 2 * maxLen;
}

// 编辑距离
// 字符串可以删除，插入和替换
int minDistance2(string word1, string word2) {
    int len1 = word1.size(), len2 = word2.size();
    // dp[i][j]表示将word1变换为word2的最少操作次数
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 0; i <= len1; ++i)
        dp[i][0] = i;
    for (int j = 0; j <= len2; ++j)
        dp[0][j] = j;
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            // 插入、删除
            dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
            // 替换
            if(word1[i - 1] == word2[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            else
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
        }
    }
    
    return dp[len1][len2];
}

int main() {
    return 0;
}