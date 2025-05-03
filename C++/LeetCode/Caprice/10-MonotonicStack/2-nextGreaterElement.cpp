//
// Created by ousun on 2025/5/3.
// 下一个更大的元素：https://www.programmercarl.com/0496.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0I.html
// 下一个更大的元素：https://leetcode.cn/problems/next-greater-element-i/
// 下一个更大的元素II：https://www.programmercarl.com/0503.%E4%B8%8B%E4%B8%80%E4%B8%AA%E6%9B%B4%E5%A4%A7%E5%85%83%E7%B4%A0II.html
// 下一个更大的元素II：https://leetcode.cn/problems/next-greater-element-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <stack>

// 下一个更大的元素：https://leetcode.cn/problems/next-greater-element-i/
vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map;
    stack<int> s;
    // 从后往前遍历map，记录单调栈和map
    for (int i = nums2.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums2[i] >= s.top()) {
            s.pop();
        }
        if (s.empty()) map[nums2[i]] = -1;
        else map[nums2[i]] = s.top();
        s.push(nums2[i]);
    }

    // 重构结果
    vector<int> ret(nums1.size(), 0);
    for (int i = 0; i < nums1.size(); ++i) {
        ret[i] = map[nums1[i]];
    }
    return ret;
}

//下一个更大的元素II： https://leetcode.cn/problems/next-greater-element-ii/
vector<int> nextGreaterElementsII(vector<int>& nums) {
    // 遍历两次构建单调栈，第一次什么都不做，第二次记录结果
    stack<int> s;
    // 从后往前遍历map，记录单调栈
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        s.push(nums[i]);
    }

    vector<int> ret(nums.size(), 0);
    for (int i = nums.size() - 1; i >= 0; --i) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        if (s.empty()) ret[i] = -1;
        else ret[i] = s.top();
        s.push(nums[i]);
    }

    return ret;
}

int main() {
    return 0;
}