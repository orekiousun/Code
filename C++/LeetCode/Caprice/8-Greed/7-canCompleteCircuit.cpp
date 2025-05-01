//
// Created by ousun on 2025/5/1.
// 加油站：https://www.programmercarl.com/0134.%E5%8A%A0%E6%B2%B9%E7%AB%99.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 加油站：https://leetcode.cn/problems/gas-station/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int add = 0;
    int ret = -1, maxNum = INT_MIN;
    // 计算后缀和，取后缀和最大且索引最靠后的
    for (int i = len - 1; i >= 0 ; --i) {
        add += gas[i] - cost[i];
        if (add > maxNum) {
            maxNum = add;
            ret = i;
        }
    }
    if (add < 0) return -1;
    return ret;
}

int main() {
    return 0;
}