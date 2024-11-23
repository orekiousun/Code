//
// Created by ousun on 2024/11/16.
// https://leetcode.cn/problems/squares-of-a-sorted-array/
// 有序数组的平方
//

#include <iostream>
using namespace std;
#include <vector>

// https://leetcode.cn/problems/squares-of-a-sorted-array/
vector<int> sortedSquares(vector<int>& nums) {
    vector<int> ret(nums.size(), 0);
    int left = 0, right = nums.size() - 1;
    int idx = nums.size() - 1;
    while (left <= right) {
        int leftSquare = nums[left] * nums[left];
        int rightSquare = nums[right] * nums[right];
        if (leftSquare > rightSquare) {
            ret[idx--] = leftSquare;
            left++;
        }
        else {
            ret[idx--] = rightSquare;
            right--;
        }
    }

    return ret;
}


int main() {
    vector<int> nums{-7, -3, 2, 3, 11};
    vector<int> ret = sortedSquares(nums);
    return 0;
}
