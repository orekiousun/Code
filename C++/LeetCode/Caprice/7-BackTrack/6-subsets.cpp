//
// Created by cd_ouymh on 2025/4/9.
// 子集问题：https://www.programmercarl.com/0078.%E5%AD%90%E9%9B%86.html
// 子集问题：https://leetcode.cn/problems/subsets/
//

#include <iostream>
using namespace std;
#include <vector>

void backtrack(vector<vector<int>>& ret, vector<int>& tmp, vector<int>& nums, int idx) {
    ret.push_back(tmp);
    for (int i = idx; i < nums.size(); ++i) {
        tmp.push_back(nums[i]);
        backtrack(ret, tmp, nums, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, nums, 0);
    return ret;
}

int main() {
    vector<int> nums{1, 2, 3};
    subsets(nums);
    return 0;
}
