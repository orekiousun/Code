#include<iostream>
using namespace std;

/*
    艾雅法拉数e
*/

int countOfE(int n) {
    int ans = 0;
    int dp0[n + 1];   // 记录前面没有e的字符串的个数
    int dp1[n + 1];   // 记录最后一个字符为e的字符串中e的个数
    int dp2[n + 1];   // 记录最后一个字符不为e字符串中e的个数

    dp0[0] = 25;
    dp1[0] = 1;
    dp2[0] = 0;

    for (int i = 1; i < n; i++) {
        dp0[i] = dp0[i - 1] * 24;
        dp1[i] = dp0[i - 1] + dp2[i- 1];
        dp2[i] = dp1[i - 1] * 25 + dp2[i - 1] * 24;
    }
    return dp1[n - 1] + dp2[n - 1];
}

int main(int argc, const char** argv) {
    cout << countOfE(3) << endl;
    system("pause");
    return 0;
}