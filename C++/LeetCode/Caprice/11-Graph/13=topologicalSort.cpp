//
// Created by ousun on 2025/5/4.
// 拓扑排序：https://www.programmercarl.com/kamacoder/0117.%E8%BD%AF%E4%BB%B6%E6%9E%84%E5%BB%BA.html#%E6%8B%93%E6%89%91%E6%8E%92%E5%BA%8F%E7%9A%84%E8%83%8C%E6%99%AF
// 拓扑排序：https://kamacoder.com/problempage.php?pid=1191
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <array>
#include <queue>

vector<int> topologicalSort(int m, vector<vector<int>>& graph, vector<int>& inDegree) {
    // 找到入度为0的节点遍历
    vector<int> ret;
    queue<int> q;
    // 将入度为0的节点加入结果集中，可能会有多个
    for (int i = 0; i < m; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }
    while (!q.empty()) {
        int front = q.front();
        ret.push_back(front);
        q.pop();
        for (int i = 0; i < graph[front].size(); ++i) {
            inDegree[graph[front][i]]--;
            // 入度为0了，才加进队列中，保证了访问顺序
            // 也可以用来判断有环，如果出现了环，这里入度就不会出现0
            if (inDegree[graph[front][i]] == 0)
                q.push(graph[front][i]);
        }
    }
    return ret;
}

int main() {
    int m, l, s, t;
    cin >> m >> l;
    vector<vector<int>> graph(m, vector<int>());
    vector<int> inDegree(m, 0);
    for (int i = 0; i < l; ++i) {
        cin >> s >> t;
        graph[s].push_back(t);
        inDegree[t]++;
    }
    vector<int> ret = topologicalSort(m, graph, inDegree);
    if (ret.size() == m) {
        for (int i = 0; i < m - 1; ++i) {
            cout << ret[i] << " ";
        }
        cout << ret[m - 1];
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}
