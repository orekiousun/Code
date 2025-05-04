//
// Created by ousun on 2025/5/3.
// 建造最大岛屿：https://www.programmercarl.com/kamacoder/0104.%E5%BB%BA%E9%80%A0%E6%9C%80%E5%A4%A7%E5%B2%9B%E5%B1%BF.html
// 建造最大岛屿：https://kamacoder.com/problempage.php?pid=1176
//


#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

const int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int buildMaxIslandDfs(vector<vector<int>>& island, vector<vector<int>>& islandIdx, int x, int y, int idx) {
    int m = island.size(), n = island[0].size();
    if (!(x >= 0 && x < m && y >= 0 && y < n)) return 0;
    if (islandIdx[x][y] != 0 || island[x][y] == 0) return 0;
    // 将此次visited做标记，用于标识此次访问过了
    islandIdx[x][y] = idx;
    int ret = 1;
    for (int i = 0; i < 4; ++i) {
        int x0 = x + arr[i][0], y0 = y + arr[i][1];
        ret += buildMaxIslandDfs(island, islandIdx, x0, y0, idx);
    }
    return ret;
}

int buildMaxIsland(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    // islandIdx[i][j] 里面的数字表示该节点处于哪个岛屿，索引从2开始
    vector<vector<int>> islandIdx(m, vector<int>(n, 0));
    // 第一步，计算所有岛屿的面积，将岛屿的数字更新为所在岛屿的面积
    int ret = 0;
    int idx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if(islandIdx[i][j] != 0 || island[i][j] == 0) continue;
            idx ++;
            int size = buildMaxIslandDfs(island, islandIdx, i, j, idx);
            ret = max(ret, size);
            // 遍历完成后，将visited为-1的（这次访问的）面积更新为size
            for (int k = 0; k < m; ++k) {
                for (int l = 0; l < n; ++l) {
                    if (islandIdx[k][l] == idx)
                        island[k][l] = size;
                }
            }
        }
    }

    // 第二步，计算又有0的节点变为1时可以变成的最大岛屿的面积所有岛屿的邻接点的面积
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (island[i][j] != 0) continue;
            // 记录哪些访问过了
            vector<bool> record(idx + 1, false);
            // 计算把这个为0的水域变成岛屿最终可以获得的面积
            int tmpRet = 1;
            for (int k = 0; k < 4; ++k) {
                int x = i + arr[k][0], y = j + arr[k][1];
                if (x >= 0 && x < m && y >= 0 && y < n && record[islandIdx[x][y]] == false)
                    tmpRet += island[x][y], record[islandIdx[x][y]] = true;
            }
            ret = max(ret, tmpRet);
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
    cout << buildMaxIsland(island) << endl;
    return 0;
}
