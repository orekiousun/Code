#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>

/*
    我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数
    注意：
        1.1是丑数，还有2, 3, 5的倍数
        2.只包含质因子2, 3, 5表示不能包含其它质因子 例如14就通知包含了质因子2, 7不满足条件
    1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15
    1  2  3  4  5  6  7  8  9   10  11

    思路：
        1.新的数一定都是原来的某个数*2 *3 *5得来的
        2.需要满足 
            dp[a - 1] * 2 =< dp[i - 1] < dp[a] * 2
            dp[b - 1] * 3 =< dp[i - 1] < dp[b] * 3
            dp[c - 1] * 5 =< dp[i - 1] < dp[c] * 5
        dp[i] = min(dp[a] * 2, dp[b] * 3, dp[c] * 5)
        用3个值记录a, b, c即可，每次命中后 +1
*/

int nthUglyNumber(int n) {
    int dp[n];
    dp[0] = 1;
    int mul2 = 0, mul3 = 0, mul5 = 0;
    for (int i = 1; i < n; i++) {
        // 错误，要保证在原来的数的基础上乘数，这样就不会出现新的质因子
        // mul2 = (dp[i - 1] / 2 + 1) * 2;
        // mul3 = (dp[i - 1] / 3 + 1) * 3;
        // mul5 = (dp[i - 1] / 5 + 1) * 5;
        int n2 = dp[mul2] * 2;
        int n3 = dp[mul3] * 3;
        int n5 = dp[mul5] * 5;
        dp[i] = min(min(n2, n3), n5);
        if(dp[i] == n2) mul2++;
        if(dp[i] == n3) mul3++;
        if(dp[i] == n5) mul5++;
    }
    return dp[n - 1];
}

int main(int argc, char const *argv[]) {
    cout << nthUglyNumber(11) << endl;
    return 0;
}
