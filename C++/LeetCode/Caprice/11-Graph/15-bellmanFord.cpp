//
// Created by ousun on 2025/5/5.
// Bellman_Ford算法：https://www.programmercarl.com/kamacoder/0095.%E5%9F%8E%E5%B8%82%E9%97%B4%E8%B4%A7%E7%89%A9%E8%BF%90%E8%BE%93II.html
// Bellman_Ford算法：https://kamacoder.com/problempage.php?pid=1152
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <unordered_map>

// 本质上的思维是动态规划
// 维护一个还未更新距离的列表，不断从中取出一个更新距离，将更新了距离的元素加到列表中，直到不可以更新为止
int bellmanFord(vector<unordered_map<int, int>>& graph, int m, int s, int t) {
    vector<int> distance(m + 1, INT_MAX);
    unordered_set<int> set;
    distance[s] = 0, set.insert(s);
    while (!set.empty()) {
        int i = *(set.begin());
        set.erase(set.begin());
        for (auto v : graph[i]) {
            if (distance[i] + v.second < distance[v.first])
                distance[v.first] = distance[i] + v.second, set.insert(v.first);
        }
    }
    return distance[t];
}

int main() {
    int m ,n;
    cin >> m >> n;
    vector<unordered_map<int, int>> graph(m + 1, unordered_map<int, int>());
    for (int i = 0; i < n; ++i) {
        int s, t, val;
        cin >> s >> t >> val;
        graph[s][t] = val;
    }
    int ret = bellmanFord(graph, m, 1, m);
    if (ret == INT_MAX) cout << "unconnected" << endl;
    else cout << ret << endl;
    return 0;
}