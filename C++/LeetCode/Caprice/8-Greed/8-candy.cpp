//
// Created by ousun on 2025/5/1.
// 分发糖果：https://www.programmercarl.com/0135.%E5%88%86%E5%8F%91%E7%B3%96%E6%9E%9C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 分发糖果：https://leetcode.cn/problems/candy/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int candy(vector<int>& ratings) {
    int len = ratings.size();
    if (len == 1) return 1;
    vector<int> candyCnt(len, 1);
    // 先从前往后，只考虑左边，不考虑右边（局部最优）
    for (int i = 1; i < len; ++i) {
        if (ratings[i - 1] < ratings[i]) candyCnt[i] = candyCnt[i - 1] + 1;
    }
    for (int i = len - 2; i >= 0; i--) {
        // 取最大值，使其比两边都大
        if (ratings[i + 1] < ratings[i]) candyCnt[i] = max(candyCnt[i + 1] + 1, candyCnt[i]);
    }
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret += candyCnt[i];
    }
    return ret;
}

int main() {
    return 0;
}
