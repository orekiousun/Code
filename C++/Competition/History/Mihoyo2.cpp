#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main() {
    long n, x;
    cin >> n >> x;
    long nums[n];
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    string str;
    cin >> str;

    long dp[n];
    dp[0] = nums[0];
    if(n == 1) return dp[0];
    if(str[0] == str[1]) dp[1] = dp[0] + nums[1];
    else {
        dp[1] = min(x, dp[0] + nums[1]);
    }
    for (int i = 2; i < n; i++) {
        if(str[i] != str[i - 1])
            dp[i] = min(dp[i - 2] + x, dp[i - 1] + nums[i]);
        else
            dp[i] = dp[i - 1] + nums[i];
    }
    cout << dp[n - 1] << endl;


    return 0;
}