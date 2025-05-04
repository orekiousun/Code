//
// Created by ousun on 2025/5/3.
// 岛屿的周长：https://www.programmercarl.com/kamacoder/0106.%E5%B2%9B%E5%B1%BF%E7%9A%84%E5%91%A8%E9%95%BF.html#%E6%80%9D%E8%B7%AF
// 岛屿的周长：https://kamacoder.com/problempage.php?pid=1178
//

#include <iostream>
using namespace std;
#include <vector>

const int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int perimeter(vector<vector<int>>& island) {
    int m = island.size(), n = island[0].size();
    int ret = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (island[i][j] == 0) continue;
            // 计数其周围0的个数
            for (int k = 0; k < 4; ++k) {
                int x = i + arr[k][0], y = j + arr[k][1];
                ret += (x >= 0 && x < m && y >= 0 && y < n) ? (island[x][y] == 0 ? 1 : 0) : 1;
            }
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
    cout << perimeter(island) << endl;
    return 0;
}