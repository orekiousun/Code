//
// Created by cd_ouymh on 2025/1/2.
// 四数相加：https://www.programmercarl.com/0454.%E5%9B%9B%E6%95%B0%E7%9B%B8%E5%8A%A0II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 四数相加：https://leetcode.cn/problems/4sum-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// 通用方案：适用于可以放任意多个数组的情况
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    vector<vector<int>> numsL{nums1, nums2, nums3, nums4};
    unordered_map<int, int> map;
    for(auto nums : numsL) {
        unordered_map<int, int> newMap;
        for (auto num : nums) {
            for(auto v : map) {
                newMap[v.first - num] += v.second;
            }
            if (map.size() == 0) newMap[0 - num] += 1;
        }
        map = newMap;
    }

    return map[0];
}


// 性能方案：针对四个数的性能优化方案
int fourSumCount1(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> map;
    for (auto num1: nums1) {
        for (auto num2:nums2) {
            map[num1+num2] += 1;
        }
    }

    int cnt = 0;
    for (auto num3: nums3) {
        for (auto num4:nums4) {
            cnt += map[0 - (num3 + num4)];
        }
    }

    return cnt;
}

int main() {
    vector<int> nums1{1, 2};
    vector<int> nums2{-2, -1};
    vector<int> nums3{-1, 2};
    vector<int> nums4{0, 2};
    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}