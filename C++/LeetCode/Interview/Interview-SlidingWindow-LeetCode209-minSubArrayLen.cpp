//
// Created by cd_ouymh on 2024/8/31.
// https://leetcode.cn/problems/minimum-size-subarray-sum/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int minSubArrayLen(int target, vector<int>& nums) {
    int left = 0, right = 0;
    int add = 0;
    int ret = nums.size() + 1;
    while (right < nums.size()) {
        add += nums[right++];
        while (add >= target) {
            ret = min(ret, right - left);
            add -= nums[left++];
        }
    }

    return ret > nums.size() ? 0 : ret;
}

int main() {
    vector<int> nums{2, 3, 1, 2, 4, 3};
    cout << minSubArrayLen(7, nums) << endl;
    return 0;
}