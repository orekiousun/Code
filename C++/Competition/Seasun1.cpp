#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    int nums[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> nums[i][j];
        }
    }
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        dp[0][i] = 0;
        dp[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + nums[i - 1][j - 1];
        }
    }
    cout << dp[n][n] << endl;
    return 0;
}
