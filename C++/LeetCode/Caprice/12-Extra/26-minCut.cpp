//
// Created by ousun on 2025/11/21.
// 分割回文串：https://www.programmercarl.com/0132.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2II.html
// 分割回文串：https://leetcode.cn/problems/palindrome-partitioning-ii/description/
// 

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

/*
    给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文串。
    返回符合要求的 最少分割次数 。
*/

bool isPalindrome(string& s, int begin, int end) {
    if (begin > end) return true;
    if (s[begin] != s[end]) return false;
    return isPalindrome(s, begin + 1, end - 1);
}

void backtrack(string& s, int& retCnt, int curCnt, int startIdx) {
    if (startIdx == s.size()) {
        retCnt = min(curCnt - 1, retCnt);
        return;
    }

    // 选择当前索引的串作为单独的子串还是和后面的组成回文串
    for (int i = startIdx; i < s.size(); i++) {
        if (isPalindrome(s, startIdx, i)) backtrack(s, retCnt, curCnt + 1, i + 1);
    }
}

// 回溯--超时
int minCutBackTrack(string s) {
    int size = s.size();
    // 计算一下从i开始，往后可以组成的最长回文子串的位置
    int ret = size - 1;
    backtrack(s, ret, 0, 0);
    return ret;
}

// 动态规划
int minCutDp(string s) {
    int size = s.size();
    // 记录任意两个索引，哪些是回文串
    vector<vector<int>> palindromeRecord(size, vector<int>(size, false));
    for (int i = 1; i <= size; i++) {
        for (int j = 0; j <= size - i; j++)
        {
            int start = j, end = j + i - 1;
            if (start + 1 <= end - 1)
                palindromeRecord[start][end] = s[start] == s[end] && palindromeRecord[start + 1][end - 1]; 
            else
                palindromeRecord[start][end] = s[start] == s[end];
        }
    }
    
    // 表示0-i的子串中的回文串的最小个数
    vector<int> dp(size, 0);
    for (int i = 0; i < size; i++) {
        if (palindromeRecord[0][i])
        {
            dp[i] = 1;
        }
        else {
            dp[i] = i + 1;
            for (int j = 0; j < i; j++) {
                if(palindromeRecord[j + 1][i]) dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }
    return dp[size - 1] - 1;
}

int main() {
    cout << minCutDp("bb") << endl;
    return 0;
}