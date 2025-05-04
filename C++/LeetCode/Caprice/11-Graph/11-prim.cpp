//
// Created by ousun on 2025/5/4.
// Prim算法：https://www.programmercarl.com/kamacoder/0053.%E5%AF%BB%E5%AE%9D-prim.html#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF
// Prim算法：https://kamacoder.com/problempage.php?pid=1053
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

const int intMax = 0x7fffffff;

// 贪心的策略，维护当前可到的所有节点的距离，每次取最短的前进，直到访问完所有的节点

int prim(int cnt, unordered_map<int, unordered_map<int, int>>& graph) {
    int ret = 0;
    // 维护访问过了的节点列表
    vector<int> visited(cnt + 1, false);
    visited[1] = true;
    int visitedCnt = 1;
    while (visitedCnt < cnt) {
        // 计算当前可到列表里面哪个最近
        int minDistance = intMax;
        int nextV = 0;
        for (int v1 = 1; v1 <= cnt; ++v1) {
            if (visited[v1] == false) continue;
            for (auto j: graph[v1]) {
                int v2 = j.first, val = j.second;
                if (visited[v2] == false && val < minDistance)
                    nextV = v2, minDistance = val;
            }
        }
        ret += minDistance;
        visitedCnt++;
        visited[nextV] = true;
    }
    return ret;
}

int main() {
    int v, e;
    cin >> v >> e;
    unordered_map<int, unordered_map<int, int>> graph;
    for (int i = 0; i < e; ++i) {
        int v1, v2, val;
        cin >> v1 >> v2 >> val;
        graph[v1][v2] = val;
        graph[v2][v1] = val;
    }
    cout << prim(v, graph) << endl;
    return 0;
}