//
// Created by cd_ouymh on 2025/4/7.
// 组合总和：https://www.programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html
// 组合总和：https://leetcode.cn/problems/combination-sum/
// 组合总和II：https://www.programmercarl.com/0040.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8CII.html
// 组合总和II：https://leetcode.cn/problems/combination-sum-ii/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 可包含重复的数字
void backtrack(vector<vector<int>>& ret, vector<int>& tmp, int curSum, int target, int beginIdx, vector<int>& candidates) {
    if (curSum >= target) {
        if (curSum == target) ret.push_back(tmp);
        return;
    }

    for (int i = beginIdx; i < candidates.size(); ++i) {
        int num = candidates[i];
        tmp.push_back(num);
        backtrack(ret, tmp, curSum + num, target, i, candidates);
        tmp.pop_back();
    }
}

// 组合总和：https://leetcode.cn/problems/combination-sum/
// 可包含重复的数字
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, 0, target, 0, candidates);
    return ret;
}

// 不可包含重复的数字
void backtrack2(vector<vector<int>>& ret, vector<int>& tmp, int curSum, int target, int beginIdx, vector<int>& candidates) {
    if (curSum >= target) {
        if (curSum == target) ret.push_back(tmp);
        return;
    }

    // 每次循环不处理重复的元素
    int pre = -1;
    for (int i = beginIdx; i < candidates.size(); ++i) {
        int num = candidates[i];
        if (num == pre) continue;
        tmp.push_back(num);
        backtrack2(ret, tmp, curSum + num, target, i + 1, candidates);
        tmp.pop_back();
        pre = num;
    }
}

// 组合总和II：https://leetcode.cn/problems/combination-sum-ii/description/
// 不可包含重复的数字
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    backtrack2(ret, tmp, 0, target, 0, candidates);
    return ret;
}

int main() {
    vector<int> candidates{10,1,2,7,6,1,5};
    combinationSum2(candidates, 8);
    return 0;
}