//
// Created by ousun on 2025/10/08.
// 比较含退格的字符串：https://www.programmercarl.com/0844.%E6%AF%94%E8%BE%83%E5%90%AB%E9%80%80%E6%A0%BC%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2.html
// 比较含退格的字符串：https://leetcode.cn/problems/backspace-string-compare/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void handleBackspace(string &s) {
    int i = 0;
    while (i < s.size()) {
        if (s[i] == '#') {
            if (i > 0) {
                s.erase(i - 1, 2);
                i--;
            }
            else {
                s.erase(i, 1);
            }
        }
        else {
            i++;
        }
    }
}

bool backspaceCompare(string s, string t) {
    handleBackspace(s);
    handleBackspace(t);
    return s == t;
}

int main() {
    cout << backspaceCompare("bxo#j##tw", "ab##") << endl;
    return 0;
}