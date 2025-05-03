//
// Created by ousun on 2025/5/3.
// 岛屿问题I-岛屿数量：https://www.programmercarl.com/kamacoder/0099.%E5%B2%9B%E5%B1%BF%E7%9A%84%E6%95%B0%E9%87%8F%E6%B7%B1%E6%90%9C.html
// 岛屿问题I-岛屿数量：https://kamacoder.com/problempage.php?pid=1171
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// 广搜版本
int islandCntBfs(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || island[i][j] == 0) continue;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                pair<int, int> front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                if (!visited[x][y] && island[x][y] == 1) {
                    // 分别搜索上下左右
                    if (x - 1 >= 0) q.push({x - 1, y});
                    if (x + 1 < m) q.push({x + 1, y});
                    if (y - 1 >= 0) q.push({x, y - 1});
                    if (y + 1 < n) q.push({x, y + 1});
                }
                visited[x][y] = true;
            }
            ret += 1;
        }
    }

    return ret;
}

// dfs（重点放在更新visited上面）
void dfs(vector<vector<int>>& island, vector<vector<bool>>& visited, int x, int y) {
    if (visited[x][y] || island[x][y] == 0) return;
    visited[x][y] = true;
    int m = island.size(), n = island[0].size();
    if (x - 1 >= 0) dfs(island, visited, x - 1, y);
    if (x + 1 < m) dfs(island, visited, x + 1, y);
    if (y - 1 >= 0) dfs(island, visited, x, y - 1);
    if (y + 1 < n) dfs(island, visited, x, y + 1);
}

// 深搜版本
int islandCntDfs(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || island[i][j] == 0) continue;
            dfs(island, visited, i, j);
            ret++;
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
    cout << islandCntDfs(island) << endl;
    return 0;
}
