//
// Created by ousun on 2025/09/16.
// 按奇偶排序数组II：https://www.programmercarl.com/0922.%E6%8C%89%E5%A5%87%E5%81%B6%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84II.html
// 按奇偶排序数组II：https://leetcode.cn/problems/sort-array-by-parity-ii/description/
//

#include <iostream>
using namespace std;
#include <vector>

int findFirstNotMatchEvenPos(vector<int>& nums, int startPos) {
    for (int i = startPos; i < nums.size(); i++) {
        if (i % 2 == 0 && nums[i] % 2 != 0)
            return i;
    }
    return -1;
}

vector<int> sortArrayByParityII(vector<int>& nums) {
    int idx = 0;
    // 找到第一个不在偶数位置的偶数，放到第一个为奇数的偶数位置
    int pos = findFirstNotMatchEvenPos(nums, 0);
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == 0 && i % 2 != 0) {
            if (idx != -1) {
                swap(nums[i], nums[pos]);
                pos = findFirstNotMatchEvenPos(nums, pos + 1);
            }
        }
    }
    return nums;
}

int main() {
    return 0;
}