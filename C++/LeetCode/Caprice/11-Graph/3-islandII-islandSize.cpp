//
// Created by ousun on 2025/5/3.
// 岛屿的最大面积：https://www.programmercarl.com/kamacoder/0100.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%9C%80%E5%A4%A7%E9%9D%A2%E7%A7%AF.html
// 岛屿的最大面积：https://kamacoder.com/problempage.php?pid=1172
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>


// dfs（边遍历边更新尺寸）
void islandMaxSizeDfs(int& ret, vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    int m = island.size(), n = island[0].size();
    if (!(x >= 0 && x < m && y >= 0 && y < n)) return;
    if (visited[x][y] || island[x][y] == 0) return;
    visited[x][y] = true;
    ret += 1;
    islandMaxSizeDfs(ret, island, visited, x - 1, y);
    islandMaxSizeDfs(ret, island, visited, x + 1, y);
    islandMaxSizeDfs(ret, island, visited, x, y - 1);
    islandMaxSizeDfs(ret, island, visited, x, y + 1);
}

// 深搜版本
// 岛屿的最大面积：https://kamacoder.com/problempage.php?pid=1172
int islandMaxSize(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || island[i][j] == 0) continue;
            int ret_ = 0;
            islandMaxSizeDfs(ret_, island, visited, i, j);
            ret = max(ret, ret_);
        }
    }

    return ret;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> island(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> island[i][j];
        }
    }
    cout << islandMaxSize(island) << endl;
    return 0;
}
