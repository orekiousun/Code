//
// Created by ousun on 2025/7/27.
// 最长重复子数组：https://www.programmercarl.com/0718.%E6%9C%80%E9%95%BF%E9%87%8D%E5%A4%8D%E5%AD%90%E6%95%B0%E7%BB%84.html
// 最长重复子数组：https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int findLength(vector<int>& nums1, vector<int>& nums2) {
    // dp[i][j]表示nums1的前i个元素和nums2的前j个元素在尾部匹配上的最长重复子数组长度
    int ret = 0;
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    for (int i = 1; i <= nums1.size(); ++i) {
        for (int j = 1; j <= nums2.size(); ++j) {
            if (nums1[i - 1] == nums2[j - 1])
                dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}

int main() {
    vector<int> nums1{1,2,3,2,1};
    vector<int> nums2{3,2,1,4,7};
    cout << findLength(nums1, nums2) << endl;
    return 0;
}