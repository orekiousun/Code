//
// Created by ousun on 2024/11/16.
// 有序数组的平方：https://www.programmercarl.com/0977.%E6%9C%89%E5%BA%8F%E6%95%B0%E7%BB%84%E7%9A%84%E5%B9%B3%E6%96%B9.html
// 有序数组的平方：https://leetcode.cn/problems/squares-of-a-sorted-array/
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
