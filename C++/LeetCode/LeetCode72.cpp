#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<algorithm>


/*
    dp[i][j] 表示word1到i位值转换到word2到j位置所需要的最小步数
    状态转移方程；
        如果word1的i位与word2的j位相等，则dp[i][j] = min(dp[i - 1][j - 1], dp[i][j - 1] + 1, dp[i - 1][j] + 1)
        否则，dp[i][j] = min(dp[i - 1][j - 1] + 1, dp[i][j - 1] + 1, dp[i - 1][j] + 1)
        dp[i - 1][j - 1] + 1 代表交换
        dp[i][j - 1] + 1 代表增加
        dp[i - 1][j] + 1 代表增加
*/

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    if(n * m == 0) return m + n;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if(word1[i - 1] == word2[j - 1]) {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
            }
            else {
                dp[i][j] = min(dp[i][j - 1] + 1, dp[i - 1][j] + 1);
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "sea", word2 = "eat";
    cout << minDistance(word1 ,word2) << endl;
    system("pause");
    return 0;
}