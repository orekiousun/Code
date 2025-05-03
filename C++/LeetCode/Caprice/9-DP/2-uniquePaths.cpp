//
// Created by ousun on 2025/5/2.
// 不同路径：https://www.programmercarl.com/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 不同路径：https://leetcode.cn/problems/unique-paths/
// 不同路径 II：https://www.programmercarl.com/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.html
// 不同路径 II：https://leetcode.cn/problems/unique-paths-ii/description/
//

#include <iostream>
using namespace std;
#include <vector>

// 不同路径：https://leetcode.cn/problems/unique-paths/
int uniquePaths(int m, int n) {
    int dp[m][n];
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        dp[0][i] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// 不同路径 II：https://leetcode.cn/problems/unique-paths-ii/description/
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    int dp[m][n];
    dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;
    for (int i = 1; i < m; ++i) {
        dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
    }
    for (int i = 1; i < n; ++i) {
        dp[0][i] = obstacleGrid[0][i] == 1 ? 0 : dp[0][i - 1];
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

int main() {
    cout << uniquePaths(3, 7) << endl;
    return 0;
}