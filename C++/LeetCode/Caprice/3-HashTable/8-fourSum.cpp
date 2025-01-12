//
// Created by ousun on 2025/1/12.
// 四数之和：https://www.programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 四数之和：https://leetcode.cn/problems/4sum/
//

#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>

vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int len = nums.size();
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    for (int a = 0; a < len; a++) {
        // 剪枝处理
        if (nums[a] > target && nums[a] >= 0) break;
        // 对a去重
        if (a > 0 && nums[a] == nums[a - 1]) continue;
        for (int b = a + 1; b < len; b++) {
            // 2级剪枝处理
            if (nums[a] + nums[b] > target && nums[a] + nums[b] >= 0) break;
            // 对b去重
            if (b > a + 1 && nums[b] == nums[b - 1]) continue;
            int c = b + 1;
            int d = len - 1;
            while (d > c) {
                // nums[a] + nums[b] + nums[c] + nums[d] > target 会溢出
                if ((long)nums[a] + nums[b] + nums[c] + nums[d] > target) d--;
                else if ((long)nums[a] + nums[b] + nums[c] + nums[d] < target) c++;
                else {
                    ret.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                    // 对c和d去重
                    while (d > c && nums[d] == nums[d - 1]) d--;
                    while (d > c && nums[c] == nums[c + 1]) c++;

                    // 找到答案时，双指针同时收缩
                    d--, c++;
                }
            }

        }
    }
    return ret;
}

int main() {
    vector<int> nums{-3, -1, 0, 2, 4, 5};
    fourSum(nums, 0);
    return 0;
}
