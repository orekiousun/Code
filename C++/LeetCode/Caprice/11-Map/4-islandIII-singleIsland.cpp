//
// Created by ousun on 2025/5/3.
// 沉没孤岛：https://www.programmercarl.com/kamacoder/0102.%E6%B2%89%E6%B2%A1%E5%AD%A4%E5%B2%9B.html
// 沉没孤岛：https://www.programmercarl.com/kamacoder/0102.%E6%B2%89%E6%B2%A1%E5%AD%A4%E5%B2%9B.html
// 孤岛的总面积：https://www.programmercarl.com/kamacoder/0101.%E5%AD%A4%E5%B2%9B%E7%9A%84%E6%80%BB%E9%9D%A2%E7%A7%AF.html#%E6%80%9D%E8%B7%AF
// 孤岛的总面积：https://kamacoder.com/problempage.php?pid=1173
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// dfs（重点放在更新visited上面）
void singleIslandTotalSizeDfs(int& ret, bool& isSingle, vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    int m = island.size(), n = island[0].size();
    if (!(x >= 0 && x < m && y >= 0 && y < n)) return;
    if (visited[x][y] || island[x][y] == 0) return;

    // 判断是否与边缘相接，如果是，表示不是孤岛，直接return false
    if (x == 0 || x == m - 1 || y == 0 || y == n - 1) isSingle = false;

    visited[x][y] = true;
    ret += 1;
    singleIslandTotalSizeDfs(ret, isSingle ,island, visited, x - 1, y);
    singleIslandTotalSizeDfs(ret, isSingle, island, visited, x + 1, y);
    singleIslandTotalSizeDfs(ret, isSingle, island, visited, x, y - 1);
    singleIslandTotalSizeDfs(ret, isSingle, island, visited, x, y + 1);
    return;
}

// 深搜版本
// 孤岛的总面积：https://kamacoder.com/problempage.php?pid=1173
// 思路2：可以先遍历周边，不计算面积，最后遍历剩下的，计算面积
int singleIslandTotalSize(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || island[i][j] == 0) continue;
            int ret_ = 0;
            bool isSingle = true;
            singleIslandTotalSizeDfs(ret_, isSingle, island, visited, i, j);
            ret += isSingle ? ret_ : 0;
        }
    }

    return ret;
}

// dfs（重点放在更新visited上面）
void sunkIslandBfs(bool isSingle, vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    int m = island.size(), n = island[0].size();
    if (!(x >= 0 && x < m && y >= 0 && y < n)) return;
    if (visited[x][y] || island[x][y] == 0) return;
    visited[x][y] = true;
    sunkIslandBfs(isSingle ,island, visited, x - 1, y);
    sunkIslandBfs(isSingle, island, visited, x + 1, y);
    sunkIslandBfs(isSingle, island, visited, x, y - 1);
    sunkIslandBfs(isSingle, island, visited, x, y + 1);
    if (isSingle) island[x][y] = 0;
    return;
}

// 深搜版本
// 孤岛的总面积：https://kamacoder.com/problempage.php?pid=1173
void sunkIsland(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    // 先遍历周边，把不是孤岛的遍历出来
    for (int i = 0; i < m; ++i) {
        if (!visited[i][0] && island[i][0] == 1)
            sunkIslandBfs(false, island, visited, i, 0);
        if (!visited[i][n - 1] && island[i][n - 1] == 1)
            sunkIslandBfs(false, island, visited, i, n - 1);
    }
    for (int j = 0; j < n; ++j) {
        if (!visited[0][j] && island[0][j] == 1)
            sunkIslandBfs(false, island, visited, 0, j);
        if (!visited[m - 1][j] && island[m - 1][j] == 1)
            sunkIslandBfs(false, island, visited, m - 1, j);
    }

    // 再遍历中间，这次只会遍历到孤岛
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            if (visited[i][j] || island[i][j] == 0) continue;
            sunkIslandBfs(true, island, visited, i, j);
        }
    }
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
    sunkIsland(island);

    // 输出结果
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << island[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}