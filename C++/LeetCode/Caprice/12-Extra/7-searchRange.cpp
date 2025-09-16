//
// Created by ousun on 2025/09/16.
// 在排序数组中查找元素的第一个和最后一个位置：https://www.programmercarl.com/0034.%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.html
// 在排序数组中查找元素的第一个和最后一个位置：https://leetcode.cn/problems/find-first-and-last-position-of-element-in-sorted-array/
//

#include <iostream>
using namespace std;
#include <vector>

int binarySearch(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    // 左闭右闭区间查找
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int targetIdx = binarySearch(nums, target);
    if (targetIdx == -1)
        return vector<int>{-1, -1};
    int left = targetIdx, right = targetIdx;
    while (left >= 0 && nums[left] == target)
        left--;
    while (right < nums.size() && nums[right] == target) 
        right++;
    return vector<int>{left + 1, right - 1};
}

int main() {
    return 0;
}
