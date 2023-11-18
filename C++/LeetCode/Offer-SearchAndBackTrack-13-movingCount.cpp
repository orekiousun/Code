#include<iostream>
using namespace std;
#include<vector>
#include<string>

/*
    地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
    一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。
    例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。
    请问该机器人能够到达多少个格子？

    图搜索算法，类似于深搜
*/

void find(vector<vector<bool>>& visited, int m, int n, int i, int j, int k, int& ans) {
    if(i >= m || j >= n || visited[i][j])
        return;
    visited[i][j] = true;
    if(i / 10 + i % 10 + j / 10 + j % 10 <= k)
        ans++;
    else
        return;
    find(visited, m, n, i + 1, j, k , ans);
    find(visited, m, n, i, j + 1, k , ans);
}

int movingCount(int m, int n, int k) {
    int ans = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    find(visited, m, n, 0, 0, k, ans);
    return ans;
}

int main(int argc, char const *argv[]) {
    cout << movingCount(3, 5, 3);
    return 0;
}


// 0,0  0,1  0,2  0,3
// 1,0  1,1, 1,2
// 2,0  2,1
