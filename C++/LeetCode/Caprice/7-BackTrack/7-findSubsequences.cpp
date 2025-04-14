//
// Created by cd_ouymh on 2025/4/14.
// 非递减子序列：https://www.programmercarl.com/0491.%E9%80%92%E5%A2%9E%E5%AD%90%E5%BA%8F%E5%88%97.html
// 非递减子序列：https://leetcode.cn/problems/non-decreasing-subsequences/
//

/*
    给你一个整数数组nums ，找出并返回所有该数组中不同的递增子序列，递增子序列中 至少有两个元素 。你可以按任意顺序返回答案。
    数组中可能含有重复元素，如出现两个整数相等，也可以视作递增序列的一种特殊情况。
    示例 1：
    输入：nums = [4,6,7,7]
    输出：[[4,6],[4,6,7],[4,6,7,7],[4,7],[4,7,7],[6,7],[6,7,7],[7,7]]
    示例 2：
    输入：nums = [4,4,3,2,1]
    输出：[[4,4]]
 */

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

void backtrack(vector<vector<int>>& ret, vector<int> tmp, vector<int>& nums, int idx) {
    if (tmp.size() > 1) ret.push_back(tmp);

    unordered_set<int> uSet;
    for (int i = idx; i < nums.size(); ++i) {
        // 注意，这里不能用之前的方法去重，由于数组是无序的，前面操作过的元素后面就不要操作了
        int num = nums[i];
        if (uSet.count(num) > 0) continue;
        if (tmp.empty() || num >= tmp[tmp.size() - 1]) {
            tmp.push_back(num);
            backtrack(ret, tmp, nums, i + 1);
            tmp.pop_back();
            uSet.insert(num);
        }
    }
}

void backtrack2(vector<vector<int>>& ret, vector<int> tmp, vector<int>& nums, int idx) {
    if (tmp.size() > 1) ret.push_back(tmp);

    // 数字范围在-100~100之间，初始化数组内的所有值为false
    bool used[201] = {false};
    for (int i = idx; i < nums.size(); ++i) {
        // 注意，这里不能用之前的方法去重，由于数组是无序的，前面操作过的元素后面就不要操作了
        int num = nums[i];
        if (used[num + 100] == true) continue;
        if (tmp.empty() || num >= tmp[tmp.size() - 1]) {
            tmp.push_back(num);
            backtrack2(ret, tmp, nums, i + 1);
            tmp.pop_back();
            used[num + 100] = true;
        }
    }
}

vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, nums, 0);
    return ret;
}

int main() {
    vector<int> nums{4,6,7,7};
    findSubsequences(nums);
    return 0;
}