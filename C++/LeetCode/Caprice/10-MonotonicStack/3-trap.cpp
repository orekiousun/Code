//
// Created by ousun on 2025/5/3.
// 接雨水：https://www.programmercarl.com/0042.%E6%8E%A5%E9%9B%A8%E6%B0%B4.html
// 接雨水：https://leetcode.cn/problems/trapping-rain-water/
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int trap(vector<int>& height) {
    // 遍历两次，第一次记录从后往前最高的位置，第二次记录从前往后计算结果
    int behindMax = 0;
    vector<int> behindMaxVec(height.size(), 0);
    for (int i = height.size() - 1; i >= 0; --i) {
        behindMaxVec[i] = behindMax;
        behindMax = max(behindMax, height[i]);
    }

    int ret = 0;
    int frontMax = 0;
    for (int i = 0; i < height.size(); ++i) {
        int tmp = min(frontMax, behindMaxVec[i]);
        if (height[i] < tmp)
            ret += tmp - height[i];
        frontMax = max(frontMax, height[i]);
    }
    return ret;
}

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    return 0;
}