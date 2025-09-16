//
// Created by ousun on 2025/09/16.
// 搜索插入位置：https://www.programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html
// 搜索插入位置：https://leetcode.cn/problems/search-insert-position/
//

#include <iostream>
using namespace std;
#include <vector>

int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else
            return mid;
    }
    return left;
}

int main() {
    return 0;
}