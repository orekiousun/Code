//
// Created by ousun on 2025/2/2.
// 实现strStr：https://www.programmercarl.com/0028.%E5%AE%9E%E7%8E%B0strStr.html
// 找出字符串中第一个匹配项的下标：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

// 构造next数组--记录needle中的前缀表
// 记录了最长相同的前缀和后缀长度
// 即查找到i时，重新开始查找从数组的哪个索引开始找
vector<int> getNext(string s) {
    vector<int> next(s.size(), 0);
    // i指向文本起始串的位置，j指向模式起始串的位置
    for (int i = 1; i < s.size(); ++i) {
        // 前后缀不同时，向前回退
        int j = next[i - 1];
        // 此时前缀和后缀相同，前缀部分也满足部分前后缀相等
        // 例如abacabab中，第一个aba和第二个aba的相同，找到最后一个abab时，和abac不匹配，所以要找前面一个a的前缀
        while (j > 0 && s[i] != s[j]) {
            j = next[j - 1];
        }
        if (s[i] == s[j]) j++;
        next[i] = j;
    }

    return next;
}

// kmp算法
int strStr(string haystack, string needle) {
    vector<int> next = getNext(needle);

    // 遍历haystack字符串
    int i = 0, j = 0;                           // i表示主串的位置，j表示模式串的位置
    while (i < haystack.size()) {
        if (haystack[i] == needle[j])           // 字符匹配，指针后移
            i++, j++;
        else if (j > 0)                         // 不匹配，j设置为前一个字符的next值，重新开始匹配
            j = next[j - 1];
        else                                    // 第一个字符就匹配失败
            i++;

        if (j == needle.size()) return i - j;   // 匹配成功
    }

    return -1;
}

int main() {
    cout << strStr("aabaaabaaac", "aabaaac") << endl;
    return 0;
}