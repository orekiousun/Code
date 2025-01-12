//
// Created by ousun on 2025/1/12.
// 三数之和：https://www.programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html
// 三数之和：https://leetcode.cn/problems/3sum/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 双指针法
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    if (nums[0] > 0) return ret;
    int len = nums.size();
    // 先定义一个初始锚点i，在1次循环中i不变
    for (int i = 0; i < len; ++i) {
        // 对a去重
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        // 定义left和right，根据a，b，c的总和动态调整left和right的位置
        int left = i + 1;
        int right = len - 1;
        while (left < right) {
            int num = nums[i] + nums[left] + nums[right];
            if (num < 0) left++;
            else if (num > 0) right--;
            else {
                ret.push_back(vector<int>{nums[i], nums[left], nums[right]});
                // 对b，c去重
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;
                left++, right--;
            }
        }
    }

    return ret;
}

int main() {
    return 0;
}
