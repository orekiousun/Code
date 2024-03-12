#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

/*
    在一条环路上有 n 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
    你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
    给定两个整数数组 gas 和 cost ，如果你可以按顺序绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1 。如果存在解，则 保证 它是 唯一 的。
 */

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int sum = accumulate(gas.begin(), gas.end(), 0) - accumulate(cost.begin(), cost.end(), 0);
    if(sum < 0) return -1;
    int left = 0, right = 0;
    sum = 0;
    while (right < gas.size()) {
        sum += gas[right] - cost[right];
        if (sum < 0) {
            sum = 0;
            left = right + 1;
        }
        right++;
    }
    return left;
}

int main() {
    vector<int> gas{1, 2, 3, 4, 5};
    vector<int> cost{3, 4, 5, 1, 2};
    cout << canCompleteCircuit(gas, cost) << endl;
    return 0;
}