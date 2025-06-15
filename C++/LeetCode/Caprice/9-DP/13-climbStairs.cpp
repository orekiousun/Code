//
// Created by ousun on 2025/6/15.
// 爬楼梯：https://www.programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF%E5%AE%8C%E5%85%A8%E8%83%8C%E5%8C%85%E7%89%88%E6%9C%AC.html
// 爬楼梯：https://kamacoder.com/problempage.php?pid=1067
//

#include <iostream>
using namespace std;
#include <vector>

int climbStairs(int n, int m) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        int sum = 0;
        for (int j = i - 1; j >= 0 && j >= i - m ; j--) {
            sum += dp[j];
        }
        dp[i] = sum;
    }
    return dp[n];
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << climbStairs(n, m) << endl;
    return 0;
}