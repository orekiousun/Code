//
// Created by cd_ouymh on 2025/4/30.
// 摆动序列：https://www.programmercarl.com/0376.%E6%91%86%E5%8A%A8%E5%BA%8F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 摆动序列：https://leetcode.cn/problems/wiggle-subsequence/description/
//

#include <iostream>
using namespace std;
#include <vector>

int wiggleMaxLength(vector<int>& nums) {
    int ret = 1;
    if (nums.size() == 1) return ret;
    int preSub = 0;
    int preNum = nums[0];
    // 递增取最大，递减取最小
    for (int i = 1; i < nums.size(); ++i) {
        int curSub = nums[i] - preNum;
        // 符号不同，刷新，结果递增
        if (curSub * preSub < 0 or (preSub == 0 && curSub != 0)) {
            preSub = curSub;
            ret++;
        }
        else {
            preSub = preSub + curSub;
        }
        preNum = nums[i];
    }
    return ret;
}

int main() {
    vector<int> nums{3,3,3,2,5};
    cout << wiggleMaxLength(nums) << endl;
    return 0;
}
