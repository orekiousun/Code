#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
    最经典的动态规划，dp[i] 表示以 i 结尾的子数组和的最大值
    空间优化为不用 dp 数组，只用一个 preMax 记录 dp[i - 1]
*/

int maxSubArray(vector<int>& nums) {
    int preMax = 0, curMax, ans = -0x7fffffff;
    for (int num : nums) {
        curMax = max(preMax + num, num);
        preMax = curMax;
        ans = max(ans, curMax);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(nums) << endl;
    return 0;
}
