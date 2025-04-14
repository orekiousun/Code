//
// Created by cd_ouymh on 2025/4/9.
// 子集问题：https://www.programmercarl.com/0078.%E5%AD%90%E9%9B%86.html
// 子集问题：https://leetcode.cn/problems/subsets/
// 子集问题II：https://www.programmercarl.com/0090.%E5%AD%90%E9%9B%86II.html
// 子集问题II：https://leetcode.cn/problems/subsets-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void backtrack(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int idx) {
    ret.push_back(tmp);
    for (int i = idx; i < nums.size(); ++i) {
        tmp.push_back(nums[i]);
        backtrack(ret, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

// https://leetcode.cn/problems/subsets/
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, nums, 0);
    return ret;
}

void backtrackWithDup(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int idx) {
    ret.push_back(tmp);
    for (int i = idx; i < nums.size(); ++i) {
        if (i != idx && nums[i] == nums[i - 1]) continue;
        tmp.push_back(nums[i]);
        backtrackWithDup(ret, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

// https://leetcode.cn/problems/subsets-ii/
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    // 优先保证有序
    sort(nums.begin(), nums.end());
    backtrackWithDup(ret, tmp, nums, 0);
    return ret;
}

int main() {
    vector<int> nums{1, 2, 2};
    subsetsWithDup(nums);
    return 0;
}
