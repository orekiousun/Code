//
// Created by ousun on 2025/5/5.
//

#include <iostream>
using namespace std;
#include <vector>

const int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int m, int n, vector<vector<int>>& graph, vector<vector<bool>>& visited, int x, int y) {
    if (!(x >= 0 && x < m && y >= 0 && y < n)) return;
    if (visited[x][y] || graph[x][y] == 0) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        dfs(m, n, graph, visited, x + arr[i][0], y + arr[i][1]);
    }
}

int islandCnt(int m, int n, vector<vector<int>>& graph) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (visited[i][j] || graph[i][j] == 0) continue;
            dfs(m, n, graph, visited, i, j);
            ret += 1;
        }
    }
    return ret;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> graph(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }
    cout << islandCnt(m, n, graph) << endl;
    return 0;
}
