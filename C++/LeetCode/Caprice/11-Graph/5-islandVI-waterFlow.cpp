//
// Created by ousun on 2025/5/3.
// 水流问题：https://www.programmercarl.com/kamacoder/0103.%E6%B0%B4%E6%B5%81%E9%97%AE%E9%A2%98.html
// 水流问题：https://kamacoder.com/problempage.php?pid=1175
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 硬编码，避免后面太多重复逻辑
const int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// dfs（边遍历边更新尺寸）
void waterFlowDfs(vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    int m = island.size(), n = island[0].size();
    if (visited[x][y]) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        int x0 = x + arr[i][0], y0 = y + arr[i][1];
        // 改在这里判断一下走不走得过去，因为是倒过来遍历，所以往高处走
        if (x0 >= 0 && x0 < m && y0 >= 0 && y0 <= n && !visited[x0][y0] && island[x][y] <= island[x0][y0])
            waterFlowDfs(island, visited, x0, y0);
    }
}

// 深搜版本
// 岛屿的最大面积：https://kamacoder.com/problempage.php?pid=1172
vector<vector<bool>> waterFlow(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();

    // 先找到能流向第一组边界的节点列表
    vector<vector<bool>> visited1(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        waterFlowDfs(island, visited1, i, 0);
    }
    for (int i = 0; i < n; ++i) {
        waterFlowDfs(island, visited1, 0, i);
    }

    vector<vector<bool>> visited2(m, vector<bool>(n, false));
    for (int i = 0; i < m; ++i) {
        waterFlowDfs(island, visited2, i, n - 1);
    }
    for (int i = 0; i < n; ++i) {
        waterFlowDfs(island, visited2, m - 1, i);
    }

    // 整合两次结果到1，找到两边都能流到的
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            visited1[i][j] = visited1[i][j] and visited2[i][j];
        }
    }
    return visited1;
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
    vector<vector<bool>> ret = waterFlow(island);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ret[i][j])
                cout << i << " " << j << endl;
        }
    }
    return 0;
}
