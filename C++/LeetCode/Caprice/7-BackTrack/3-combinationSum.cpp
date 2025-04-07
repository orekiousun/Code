//
// Created by cd_ouymh on 2025/4/7.
// 组合总和：https://www.programmercarl.com/0039.%E7%BB%84%E5%90%88%E6%80%BB%E5%92%8C.html
// 组合总和：https://leetcode.cn/problems/combination-sum/
//

#include <iostream>
using namespace std;
#include <vector>

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

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ret;
    vector<int> tmp;
    backtrack(ret, tmp, 0, target, 0, candidates);
    return ret;
}

int main() {
    vector<int> candidates{2,3,5};
    combinationSum(candidates, 8);
    return 0;
}