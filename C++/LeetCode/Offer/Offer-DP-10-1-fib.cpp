#include<iostream>
using namespace std;
#include<vector>

/*
    求斐波拉契数列
    动态规划
        ·方案一：维护一个数组进行动归
        ·方案二：只用记录前两个数就行
*/

int fib(int n) {
    vector<int> dp{0, 1, 1};
    dp.reserve(n + 1);
    if(n <= 2) return dp[n];
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        dp[i] = dp[i] % 1000000007;
    }
    return dp[n] % 1000000007;
}

int fib(int n, bool override) {
    int pre1 = 1, pre2 = 1;
    if(n == 0) return 0;
    else if(n <= 2) return 1;
    int ans;
    for (int i = 3; i <= n; i++) {
        ans = (pre1 + pre2) % 1000000007;
        pre1 = pre2, pre2 = ans;
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    cout << fib(2) << endl;
    return 0;
}
