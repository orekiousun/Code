#include<iostream>
using namespace std;
#include<vector>

/*
    给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。
    一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

    方法：动态规划，dp[i]表示从个位到i位的数字可以翻译的方法次数
        1.i 和 i + 1 位组合起来的两位数 10 <= a <= 25，则 dp[i] = dp[i - 1] + dp[i - 2]
        2.i 和 i + 1 位组合起来的两位数 > 25，则 dp[i] = dp[i - 1]
*/

int translateNum(int num) {
    vector<int> dp(2);
    dp[0] = 1;
    dp[1] = 1;
    int preNum = num % 10, i = 2;
    num /= 10;
    while (num != 0) {
        int temp = num % 10 * 10 + preNum;
        int ans = temp <= 25 && temp >= 10 ? dp[i - 1] + dp[i - 2] : dp[i - 1];
        dp.push_back(ans);
        preNum = num % 10;
        num /= 10;
        i++;
    }
    return dp[dp.size() - 1];
}

// 动态规划空间优化
int translateNum(int num, bool flag) {
    int pre1 = 1, pre2 = 1;
    int preNum = num % 10, i = 2;
    num /= 10;
    while (num != 0) {
        // 计算出之前的两位数 num % 10 为一位数
        int temp = num % 10 * 10 + preNum;
        int ans = temp <= 25 && temp >= 10 ? pre1 + pre2 : pre1;
        pre2 = pre1;
        pre1 = ans;
        preNum = num % 10;
        num /= 10;
        i++;
    }
    return pre1;
}

int main(int argc, char const *argv[]) {
    cout << translateNum(506) << endl;
    return 0;
}
