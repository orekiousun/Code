//
// Created by ousun on 2025/08/29.
// 有多少小于当前数字的数字：https://www.programmercarl.com/1365.%E6%9C%89%E5%A4%9A%E5%B0%91%E5%B0%8F%E4%BA%8E%E5%BD%93%E5%89%8D%E6%95%B0%E5%AD%97%E7%9A%84%E6%95%B0%E5%AD%97.html
// 有多少小于当前数字的数字：https://leetcode.cn/problems/how-many-numbers-are-smaller-than-the-current-number/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 暴力解法
vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    int size = nums.size();
    vector<int> ret(size, 0);
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (nums[j] < nums[i])
                count += 1;
        }
        ret[i] = count;
    }
    return ret;
}

// 先排序再计算
vector<int> smallerNumbersThanCurrent2(vector<int>& nums) {
    int size = nums.size();
    // 拷贝一下
    vector<int> ret(nums);
    sort(nums.begin(), nums.end());
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = size - 1; j >= 0; j--) {
            if (nums[j] < ret[i]) {
                count = j + 1;
                break;
            }
        }
        ret[i] = count;
    }
    return ret;
}

int main() {
    vector<int> nums{8, 1, 2, 2, 3};
    smallerNumbersThanCurrent2(nums);
    return 0;
}