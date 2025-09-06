//
// Created by ousun on 2025/09/06.
// 移动零：https://www.programmercarl.com/0283.%E7%A7%BB%E5%8A%A8%E9%9B%B6.html
// 移动零：https://leetcode.cn/problems/move-zeroes/
//

#include <iostream>
using namespace std;
#include <vector>

void moveZeroes(vector<int>& nums) {
    // 统计不为0的索引
    int idx = 0;
    for (int num : nums) {
        if (num != 0)
            nums[idx++] = num;
    }
    for (int i = idx; i < nums.size(); ++i) {
        nums[i] = 0;
    }
}

int main() {
    
    return 0;
}