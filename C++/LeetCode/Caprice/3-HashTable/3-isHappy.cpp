//
// Created by ousun on 2024/12/28.
// 快乐数：https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html
// 快乐数：https://leetcode.cn/problems/happy-number///
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

int calc_bit_square(int n) {
    int ret = 0;
    while (n != 0) {
        int tmp = n % 10;
        n /= 10;
        ret = ret + tmp * tmp;
    }
    return ret;
}

// 使用unordered_set记录算过了哪些数，出现重复的就返回false
bool isHappy(int n) {
    unordered_set<int> set;
    while (n != 1) {
        n = calc_bit_square(n);
        if (set.count(n) == 0)
            set.insert(n);
        else
            return false;
    }

    return true;
}

int main() {
    cout << isHappy(19) << endl;
    return 0;
}