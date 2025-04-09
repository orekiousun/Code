//
// Created by cd_ouymh on 2025/4/8.
// 分割回文串：https://www.programmercarl.com/0131.%E5%88%86%E5%89%B2%E5%9B%9E%E6%96%87%E4%B8%B2.html
// 分割回文串：https://leetcode.cn/problems/palindrome-partitioning/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

// 判断是否是回文串
bool isPalindrome(const string& str) {
    int len = str.size();
    for (int i = 0; i < len / 2; ++i) {
        if (str[i] != str[len - 1 - i]) return false;
    }
    return true;
}

void backtrack(vector<vector<string>>& ret, vector<string>& tmp, const string& str, int beginIdx) {
    if (beginIdx == str.size()) {
        ret.push_back(tmp);
        return;
    }

    for (int i = beginIdx; i < str.size(); ++i) {
        string subStr = str.substr(beginIdx, i - beginIdx + 1);
        if (isPalindrome(subStr)) {
            tmp.push_back(subStr);
            backtrack(ret, tmp, str, i + 1);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    // 回溯构建子串
    vector<vector<string>> ret;
    vector<string> tmp;
    backtrack(ret, tmp, s, 0);
    return ret;
}

int main() {
    partition("aab");
    return 0;
}