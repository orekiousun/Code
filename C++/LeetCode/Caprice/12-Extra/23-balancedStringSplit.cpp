//
// Created by ousun on 2025/10/24.
// 分割平衡字符串：https://www.programmercarl.com/1221.%E5%88%86%E5%89%B2%E5%B9%B3%E8%A1%A1%E5%AD%97%E7%AC%A6%E4%B8%B2.html
// 分割平衡字符串：https://leetcode.cn/problems/split-a-string-in-balanced-strings/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

int balancedStringSplit(string s) {
    int lCnt = 0, rCnt = 0, ret = 0;
    for (auto c : s) {
        if (c == 'L')
            lCnt++;
        else if (c == 'R')
            rCnt++;
        if (lCnt == rCnt)
        {
            ret++;
            lCnt = 0, rCnt = 0;
        }
    }
    return ret;
}

int main() {
    return 0;
}