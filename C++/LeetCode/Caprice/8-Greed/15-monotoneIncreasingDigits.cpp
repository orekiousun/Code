//
// Created by ousun on 2025/5/1.
// 单调递增的数字：https://www.programmercarl.com/0738.%E5%8D%95%E8%B0%83%E9%80%92%E5%A2%9E%E7%9A%84%E6%95%B0%E5%AD%97.html
// 单调递增的数字：https://leetcode.cn/problems/monotone-increasing-digits/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int monotoneIncreasingDigits(int n) {
    int ret = 0, mul = 1;
    int cur, next;
    while (n > 0) {
        cur = n % 10;
        next = (n / 10) % 10;
        // 一旦出现了后面比前面小的，后面更新为999，借位
        if (cur < next) cur = 9, ret = mul - 1, n -= 10;
        ret += cur * mul;
        n /= 10;
        mul *= 10;
    }
    return ret;
}

int main() {
    monotoneIncreasingDigits(556487);
    return 0;
}
