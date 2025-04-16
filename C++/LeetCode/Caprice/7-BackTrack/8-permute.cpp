//
// Created by cd_ouymh on 2025/4/16.
// 全排列：https://www.programmercarl.com/0046.%E5%85%A8%E6%8E%92%E5%88%97.html
// 全排列：https://leetcode.cn/problems/permutations/
// 全排列II：https://www.programmercarl.com/0047.%E5%85%A8%E6%8E%92%E5%88%97II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 全排列II：https://leetcode.cn/problems/permutations-ii/
//

#include <iostream>
using namespace std;
#include <vector>
#include <array>
#include <algorithm>

// 使用used数组记录那些使用过了
void backtrack(vector<vector<int>>& ret, vector<int>& tmp, vector<bool>& used, vector<int>& nums) {
    if (tmp.size() == nums.size()) {
        ret.push_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) continue;
        tmp.push_back(nums[i]);
        used[i] = true;
        backtrack(ret, tmp, used, nums);
        tmp.pop_back();
        used[i] = false;
    }
}

// 全排列：https://leetcode.cn/problems/permutations/
// 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<bool> used(nums.size(), false);
    backtrack(ret, tmp, used, nums);
    return ret;
}

// 使用used数组记录那些使用过了
void backtrackUnique(vector<vector<int>>& ret, vector<int>& tmp, vector<bool>& used, vector<int>& nums) {
    if (tmp.size() == nums.size()) {
        ret.push_back(tmp);
        return;
    }

    // 注意本次遍历过了就不再遍历了
    for (int i = 0; i < nums.size(); ++i) {
        // 同一层的前一个使用过，且数值相等，跳过
        // used[i - 1] = true, 说明同一树层nums[i - 1]使用过
        // used[i - 1] = false, 说明当前这个for循环nums[i - 1]使用过
        if (i > 0 && used[i - 1] == false && nums[i - 1] == nums[i]) continue;
        // 当前这个使用过，跳过
        if (used[i]) continue;
        tmp.push_back(nums[i]);
        used[i] = true;
        backtrackUnique(ret, tmp, used, nums);
        tmp.pop_back();
        used[i] = false;
    }
}

// 不推荐上面的做法，有点难想，这样更直观一点
void backtrackUnique2(vector<vector<int>>& ret, vector<int>& tmp, vector<bool>& used, vector<int>& nums) {
    if (tmp.size() == nums.size()) {
        ret.push_back(tmp);
        return;
    }

    // 注意本次遍历过了就不再遍历了
    array<bool, 21> record;
    record.fill(false);
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i] || record[nums[i] + 10]) continue;
        tmp.push_back(nums[i]);
        used[i] = true;
        backtrackUnique2(ret, tmp, used, nums);
        tmp.pop_back();
        used[i] = false;
        record[nums[i] + 10] = true;
    }
}

// https://leetcode.cn/problems/permutations-ii/
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ret;
    vector<int> tmp;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    backtrackUnique(ret, tmp, used, nums);
    // backtrackUnique2(ret, tmp, used, nums); // 使用2不用sort
    return ret;
}

int main() {
    vector<int> nums{1,1,2};
    permuteUnique(nums);
    return 0;
}