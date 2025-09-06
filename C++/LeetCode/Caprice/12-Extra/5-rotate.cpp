//
// Created by ousun on 2025/09/06.
// 旋转数组：https://www.programmercarl.com/0189.%E6%97%8B%E8%BD%AC%E6%95%B0%E7%BB%84.html
// 旋转数组：https://leetcode.cn/problems/rotate-array/
// 

#include <iostream>
using namespace std;
#include <vector>

void reverse_by_index(vector<int>& nums, int start, int end) {
    int mid = (start + end) / 2;
    for (int i = start; i <= mid; i++) {
        swap(nums[i], nums[end - i + start]);
    }
}

void rotate(vector<int>& nums, int k) {
    // 1,2,3,4,5,6,7 3
    // 5,6,7,1,2,3,4
    // 反转前面n-k长度数组，再反转后面k长度数组，最后反转整个数组
    if (k <= 0) return;
    int n = nums.size();
    if (k >= n) k = k % n;
    reverse_by_index(nums, 0, n - k - 1);
    reverse_by_index(nums, n - k, n - 1);
    reverse_by_index(nums, 0, n - 1);
}

int main() {
    return 0;
}