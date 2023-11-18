#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool matches(char a, char b) {
    if (a == b) return true;
    if (a == '.' || b == '.') return true;
    return false;
}

bool isMatch(string s, string p) {
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
    // f[i][j] 表示 s 的前 i 个字符与 p 中的前 j 个字符是否能够匹配
    
    /** 
    base case: s为空串，匹配成功只有两种情况：
    - p 也为空串
    - p 的形式为：#*#*#*...
    **/
    dp[0][0] = 1;
    for (int j = 2; j <= n; j++) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];
        }
    }

    /**
    下面的i j 表示的均为dp数组下标
    对应s串和p串的长度
    对应s[i-1]和p[j-1]所在位置的字符
    **/
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == '*') {
                dp[i][j] == dp[i][j - 2] || dp[i][j];   // 对*匹配0次
                if (matches(s[i - 1], p[j - 2])) {
                    dp[i][j] = dp[i - 1][j - 2] || dp[i][j];    
                    dp[i][j] = dp[i - 1][j] || dp[i][j];
                }
            } else {
                if (matches(s[i - 1], p[j - 1])) {
                    dp[i][j] = dp[i - 1][j - 1] || dp[i][j];
                }
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s = "ab", p = ".*c";
    cout << isMatch(s, p) << endl;
    system("pause");
    return 0;
}