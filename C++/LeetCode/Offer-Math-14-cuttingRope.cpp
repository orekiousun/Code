#include<iostream>
using namespace std;
#include<vector>


/*
    将一个n段的绳子减成m段，m的值可以自定，求这m段绳子长度成绩的最大值
    ·法一：动态规划
    ·法二：可以通过数学方法求导得当x = e时乘积最大，所以分段长度得最优长度为3，次优为2，次次优为1
*/

#pragma region 动态规划
int cuttingRope(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1, dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = max(max(dp[j], j) * max(dp[i - j], i - j), dp[i]);
        }
    }
    return dp[n];
}
#pragma endregion

#pragma region 数学方法 -- 可以结合快速幂
// 不结合快速幂
int cuttingRope(int n, bool override, bool override2) {
    if(n <= 3) return n - 1;
    else if(n == 4) return 4;
    int ans = 1;
    while (n > 4) {
        ans *= 3;
        n -= 3;
    }
    ans *= n;
    return ans;
}

// 快速幂，求x^k的快速幂
// 同时取模：(a * b) mod c = (a mod c)(b mod c) mod c !!!
long fastPow(int x, int k, int mod) {
    int num = 1, ans = 1;
    while (num <= k) {
        int temp = num & k;
        if(temp) ans = (ans % mod) * (x % mod) % mod;
        x = (x % mod) * (x % mod) % mod;
        num = (2 * num) % mod;
    }
    return ans;
}

long cuttingRope(int n, bool override) {
    if(n <= 3) return n - 1;
    int pow = (n - 2) / 3;
    return (n - 3 * pow) * fastPow(3, pow, 1000000007) % 1000000007;
}
#pragma endregion

int main(int argc, char const *argv[]) {
    // cout << fastPow(3, 2) << endl;
    cout << cuttingRope(4, 1) << endl;
    return 0;
}
