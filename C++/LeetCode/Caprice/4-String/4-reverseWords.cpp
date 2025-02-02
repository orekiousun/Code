//
// Created by ousun on 2025/2/2.
// 翻转字符串：https://www.programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html
// 翻转字符串：https://leetcode.cn/problems/reverse-words-in-a-string/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

string reverseWords(string s) {
    string ret;
    int i = s.size() - 1;
    while(i >= 0) {
        if (s[i] == ' ') {
            i--;
            continue;
        }
        int left = i;
        while (left >= 0 && s[left] != ' ') {
            left--;
        }
        for (int j = left + 1; j <= i; j++) {
            ret.push_back(s[j]);
        }
        ret.push_back(' ');
        i = left - 1;
    }

    // 移除多余的空格
    i = ret.size() - 1;
    while (ret[i] == ' '){
        ret.erase(i--, 1);
    }

    return ret;
}

