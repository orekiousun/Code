//
// Created by cd_ouymh on 2025/3/31.
// 组合：https://www.programmercarl.com/0077.%E7%BB%84%E5%90%88.html
// 组合：https://leetcode.cn/problems/combinations/
// 组合总和III：https://www.programmercarl.com/0216.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CIII.html
// 组合总和III：https://leetcode.cn/problems/combination-sum-iii/
//

#include <iostream>
using namespace std;
#include <vector>

// 回溯
void backtrack(vector<vector<int>>& ret, vector<int>& nums, int begin, int end, int k) {
    if (nums.size() == k) {
        ret.push_back(nums);
        return;
    }
//    for (int i = begin; i <= end; ++i) {
//        nums.push_back(i);
//        backtrack(ret, nums, i + 1, end, k);
//        nums.pop_back();
//    }
    // 优化，可以剪枝，后续数字量不足以填充数组时，不继续遍历
    for (int i = begin; end - i + 1 + nums.size() >= k; ++i) {
        nums.push_back(i);
        backtrack(ret, nums, i + 1, end, k);
        nums.pop_back();
    }
}

// 组合：https://leetcode.cn/problems/combinations/
// 给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, 1, n, k);
    return ret;
}

void backtrack(vector<vector<int>>& ret, vector<int>& nums, int start, int end, int curSum, int k, int n) {
    if (curSum == n && nums.size() == k) {
        ret.push_back(nums);
        return;
    }

    // 剪枝
    if (curSum + start > n) return;
    if (nums.size() > k) return;

    for(int i = start; i <= end; i++) {
        nums.push_back(i);
        curSum += i;
        backtrack(ret, nums, i + 1, end, curSum, k, n);
        nums.pop_back();
        curSum -= i;
    }
}

// https://leetcode.cn/problems/combination-sum-iii/description/
// 找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//  只使用数字1到9
//  每个数字最多使用一次
vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, 1, 9, 0, k ,n);
    return ret;
}

int main() {
    combine(4, 2);
    return 0;
}
