//
// Created by ousun on 2025/5/12.
//

#include <iostream>
using namespace std;
#include <vector>
#include <numeric>
#include <algorithm>

// 由于这里目标和可能是负数，所以不能用背包问题解决
// 方案：将数组拆分为两半，计算两边所有情况的总和，再排序，一步一步逼近目标值
int minAbsDifference(vector<int>& nums, int goal) {
    int size = nums.size();
    int lSize = size / 2, rSize = size - lSize;
    vector<int> lVec((1 << lSize), 0), rVec((1 << rSize), 0);
    // 先计算左右两边所有的结果（用二进制位标记该节点算没算）
    // 这里要是觉得太麻烦，也可以老实用回溯做
    for (int i = 0; i < (1 << lSize); ++i) {
        for (int j = 0; j < lSize; ++j) {
            // 判断一下当前比特位有没有选这个数字
            if ((i & (1 << j)) == 0) continue;
            // 可以用之前计算过的结果重建现在的结果
            lVec[i] += lVec[i - (1 << j)] + nums[j];
            break;
        }
    }
    for (int i = 0; i < (1 << rSize); ++i) {
        for (int j = 0; j < rSize; ++j) {
            // 判断一下当前比特位有没有选这个数字
            if ((i & (1 << (j))) == 0) continue;
            // 可以用之前计算过的结果重建现在的结果
            rVec[i] += rVec[i - (1 << j)] + nums[j + lSize];
            break;
        }
    }
    // 再排下序
    sort(lVec.begin(), lVec.end());
    sort(rVec.begin(), rVec.end());
    int ret = INT_MAX;
    // 分别计算只使用左边和右边时的结果
    for (auto v : lVec) {
        ret = min(abs(goal - v), ret);
    }
    for (auto v: rVec) {
        ret = min(abs(goal - v), ret);
    }
    // 计算左右两边相加的结果
    int i = 0, j = rVec.size() - 1;
    while (i < lVec.size() && j >= 0) {
        int sum = lVec[i] + rVec[j];
        ret = min(ret, abs(sum - goal));
        if (sum < goal) i++;
        else j--;
    }
    return ret;
}

int main() {
    vector<int> nums{5, -7, 3, 5};
    cout << minAbsDifference(nums, 6);
    return 0;
}