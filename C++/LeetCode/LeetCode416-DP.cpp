#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

bool canPartition(vector<int>& nums) {
    int size = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);
    if(total % 2 == 1 || size <= 1 || *max_element(nums.begin(), nums.end()) > total / 2) return false;

    // 初始化背包
    vector<vector<bool>> dp(size, vector<bool>(total, false));
    for (int i = 0; i < size; i++){
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;

    // 进行动态规划
    for (int i = 1; i < size; i++){
        for (int j = 1; j <= total / 2; j++){
            if(nums[i] <= j)
                dp[i][j] = dp[i - 1][j - nums[i]] || dp[i - 1][j];  
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[nums.size() - 1][total / 2];
}


int main() {
    vector<int> nums{1, 9, 2, 4, 10};
    cout << canPartition(nums) << endl;
    system("pause");
    return 0;
}