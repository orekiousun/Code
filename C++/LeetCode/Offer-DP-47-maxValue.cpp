#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。
    你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。
    给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？

    dp[i][j]从左上角到(i,j)位置的礼物最大值
        转移方程：dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
*/

int maxValue(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    int dp[m + 1][n + 1];
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i - 1][j - 1];
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[]) {
    vector<int> v1{1,3,1};
    vector<int> v2{1,5,1};
    vector<int> v3{4,2,1};
    vector<vector<int>> grid{v1, v2, v3};
    cout << maxValue(grid) << endl;
    return 0;
}
