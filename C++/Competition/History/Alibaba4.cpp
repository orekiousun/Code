#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int func(vector<vector<bool>> nums) {
    int m = nums.size(), n = nums[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    dp[0][0] = nums[0][0] ? 1 : 0;
    for (int i = 1; i < m; i++) {
        if(nums[i][0] == false)
            dp[i][0] = dp[i - 1][0];
        else {
            if(nums[i - 1][0] == false)
                dp[i][0] = dp[i - 1][0] + 1;
            else
                dp[i][0] = dp[i - 1][0];
        }
    }
    for (int i = 1; i < n; i++) {
        if(nums[0][i] == false)
            dp[0][i] = dp[0][i - 1];
        else {
            if(nums[0][i - 1] == false)
                dp[0][i] = dp[0][i - 1] + 1;
            else
                dp[0][i] = dp[0][i - 1];
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if(nums[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            else {
                if(nums[i - 1][j - 1] == 0 && nums[i - 1][j] == 1 && nums[i][j - 1] == 1) {
                    if(dp[i - 1][j - 1] == dp[i - 1][j] && dp[i - 1][j - 1] == dp[i][j - 1])
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] - 1;
                }
                else if(nums[i - 1][j] == 0 && nums[i][j - 1] == 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }
    return dp[m - 1][n - 1];
}
    


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m, n, x;
        cin >> m >> n >> x;
        vector<vector<bool>> nums(m, vector<bool>(n));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                int temp;
                cin >> temp;
                if(temp <= x) nums[j][k] = 1;
                else nums[j][k] = 0;
            }
        }
        int res = func(nums);
        cout << (res == 0 ? "Orz" : to_string(res)) << endl;
    }
    return 0;
}

// int func(vector<vector<bool>> nums) {
//     int m = nums.size(), n = nums[0].size();
//     vector<vector<int>> dp(m, vector<int>(n));
//     dp[0][0] = nums[0][0] ? 1 : 0;
//     for (int i = 1; i < m; i++) {
//         if(nums[i][0] == false)
//             dp[i][0] = dp[i - 1][0];
//         else {
//             if(nums[i - 1][0] == false)
//                 dp[i][0] = dp[i - 1][0] + 1;
//             else
//                 dp[i][0] = dp[i - 1][0];
//         }
//     }
//     for (int i = 1; i < n; i++) {
//         if(nums[0][i] == false)
//             dp[0][i] = dp[0][i - 1];
//         else {
//             if(nums[0][i - 1] == false)
//                 dp[0][i] = dp[0][i - 1] + 1;
//             else
//                 dp[0][i] = dp[0][i - 1];
//         }
//     }

//     for (int i = 1; i < m; i++) {
//         for (int j = 1; j < n; j++) {
//             if(nums[i][j] == 0)
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//             else {
//                 if(nums[i - 1][j] == 0 && nums[i][j - 1] == 0)
//                     dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + 1;
//                 else {
//                     if(nums[i - 1][j - 1] == 0 && nums[i - 1][j] == 1 && nums[i][j - 1] == 1)
//                         dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] - 1;
//                     else
//                         dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
//                 }
//             }
//         }
//     }
//     return dp[m - 1][n - 1];
// }
   