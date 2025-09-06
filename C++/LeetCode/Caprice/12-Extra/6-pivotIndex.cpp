//
// Created by ousun on 2025/09/06.
// 寻找数组的中心下标：https://www.programmercarl.com/0724.%E5%AF%BB%E6%89%BE%E6%95%B0%E7%BB%84%E7%9A%84%E4%B8%AD%E5%BF%83%E7%B4%A2%E5%BC%95.html#%E6%80%9D%E8%B7%AF
// 寻找数组的中心下标：https://leetcode.cn/problems/find-pivot-index/
//

#include <iostream>
using namespace std;
#include <vector>

// 将数组更新为前缀和
int pivotIndex(vector<int>& nums) {
    int sum = 0;
    int size = nums.size();
    for (int i = 0; i < size; ++i) {
        sum += nums[i];
        nums[i] = sum;
    }
    for (int i = 0; i < size; i++)
    {
        int front = i == 0 ? 0 : nums[i - 1];
        int end = nums[size - 1] - nums[i];
        if (front == end)
            return i;
    }
    return -1;
}

int main() {
    return 0;
}