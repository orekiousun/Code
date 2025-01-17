//
// Created by cd_ouymh on 2025/1/17.
// 反转字符串II：https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html
// 反转字符串II：https://leetcode.cn/problems/reverse-string-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

string reverseStr(string s, int k) {
    int k2 = 2 * k;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        int rem = i % k2;
        int beginIdx = i - rem;
        int endIdx = min(beginIdx + k, len) - 1;
        if (i > (endIdx + beginIdx) / 2) continue;
        int tmp = s[i];
        s[i] = s[endIdx - rem];
        s[endIdx - rem] = tmp;
    }
    return s;
}

int main() {
    cout << reverseStr("abcdefghijklmn", 3) << endl;
    return 0;
}