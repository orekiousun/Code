//
// Created by ousun on 2025/2/2.
// 重复的子字符串：https://www.programmercarl.com/0459.%E9%87%8D%E5%A4%8D%E7%9A%84%E5%AD%90%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 重复的子字符串：https://leetcode.cn/problems/repeated-substring-pattern/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

// 法一：两个s拼接，掐头去尾，如果拼接过后的字符串中能查找到s，说明是重复的子字符串
bool repeatedSubstringPattern(string s) {
    string t = s + s;
    t.erase(t.begin());
    t.erase(t.end() - 1);
    if (t.find(s) != string::npos) return true;
    return false;
}

// 法二：KMP解法
// 最长相等前后缀不包含的子串一定是字符串s的最小重复子串
// 如果这个字符串s是由重复子串组成，那么最长相等前后缀不包含的子串是字符串s的最小重复子串
bool repeatedSubstringPattern2(string s) {
    int len = s.size();
    vector<int> next(len, 0);
    for (int i = 1; i < len; ++i) {
        int j = next[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) j++;
        next[i] = j;
    }

    if (next[len - 1] != 0 && len % (len - next[len - 1]) == 0)
        return true;
    return false;
}

int main() {
    cout << repeatedSubstringPattern("abaababaab") << endl;
    return 0;
}