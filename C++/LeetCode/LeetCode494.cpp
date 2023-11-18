#include<iostream>
using namespace std;
#include<vector>
#include<queue>

/*
    计数组元素和为sum，添加-号的元素和为neg，则其余添加+号的元素和为sum - neg
    最终计算结果为：sum - neg - neg = sum - 2 * neg = target
    则 neg = (sum - target) / 2
    若 sum - target 为奇数则一定不成立
    则现在问题转换为了在数组中求和为neg的组合，利用动态规划
    状态转移方程：
        dp[i][j] = dp[i - 1][j]                                 j < nums[i - 1]
        dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]    j >= nums[i - 1]
*/
int findTargetSumWays(vector<int>& nums, int target) {
    int sum=0;
    for(int item : nums) {
        sum += item;
    } 
    if(sum < abs(target)) 
        return 0;
    if((sum - target) % 2 == 1) 
        return 0;
    int neg = (sum + target) / 2;
    vector<int> temp(neg + 1, 0);
    vector<vector<int>> dp(nums.size() + 1, temp);
    dp[0][0] = 1;
    for (int i = 1; i <= nums.size(); i++) {
        for (int j = 0; j <= neg; j++) {
            if(j < nums[i - 1])
                dp[i][j] = dp[i - 1][j];
            else 
                dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j]; 
        }
    }
    return dp[nums.size()][neg];
}

// 回溯，不好用
int BackTrack(vector<int>& nums, int target, int index, int origin) {
    if(index >= nums.size()) {
        if(origin == target) return 1;
        else return 0;
    }
    int res = 0;
    res += BackTrack(nums, target, index + 1, origin + nums[index]);
    res += BackTrack(nums, target, index + 1, origin - nums[index]);
    return res;
}

int main() {
    vector<int> nums{1,1,1,1,1};
    cout << findTargetSumWays(nums, 3) << endl;
    system("pause");
    return 0;
}