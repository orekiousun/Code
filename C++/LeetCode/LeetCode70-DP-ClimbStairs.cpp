#include<iostream>
using namespace std;
#include<vector>

int climbStairs(int n) {
    if(n == 1) return 1;
    if(n == 2) return 2;
    vector<int> dp(n + 1, 0);
    dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    return dp[n];
}

int main() {
    cout << climbStairs(10) << endl;
    system("pause");
    return 0;
}