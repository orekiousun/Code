//
// Created by ousun on 2025/8/3.
// 判断子序列：https://www.programmercarl.com/0392.%E5%88%A4%E6%96%AD%E5%AD%90%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 判断子序列：https://leetcode.cn/problems/is-subsequence/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

bool isSubsequence(string s, string t) {
    int size = s.size();
    if (size == 0) return true;
    int idx = 0;
    if (idx == s.size()) return true;
    for (auto c: t) {
        if (c == s[idx]) {
            idx++;
            if (idx == size) return true;
        }
    }
    return false;
}

int main() {
    return 0;
}
