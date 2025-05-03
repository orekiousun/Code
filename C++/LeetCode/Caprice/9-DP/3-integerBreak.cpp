//
// Created by ousun on 2025/5/2.
// 整数拆分：https://www.programmercarl.com/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.html
// 整数拆分：https://leetcode.cn/problems/integer-break/
//

#include <iostream>
using namespace std;
#include <vector>

// 优先拆3，其次拆2（数论，e = 2.6...）
int integerBreak(int n) {
    if (n <= 3) return n - 1;
    if (n == 4) return 4;
    int ret = 1;
    while (n > 4) {
        ret *= 3;
        n -= 3;
    }
    ret *= n;
    return ret;
}

int main() {
    return 0;
}