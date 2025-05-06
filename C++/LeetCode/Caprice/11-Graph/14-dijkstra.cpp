//
// Created by ousun on 2025/5/5.
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>

// 核心：不断更新各个节点到源节点的最短路径，注意需要把所有的边都遍历完，最短路不是第一时间就更新了的
int dijkstra(vector<unordered_map<int, int>>& graph, int m, int s, int t) {
    // 维护每个节点到初始节点的最短距离
    vector<int> distance(m + 1, -1);
    vector<bool> visited(m + 1, false);
    // 初始化distance和visited数组
    distance[s] = 0;
    // 每次只多加一个节点，保证把所有边都遍历完
    for (int i = 1; i <= m; ++i) {
        int minDistance = INT_MAX;
        int minI = -1;
        // 找到distance中最短路
        for (int j = 1; j <= m; ++j) {
            if (distance[j] == -1) continue;
            if (visited[j] == false && distance[j] < minDistance)
                minDistance = distance[j], minI = j;
        }
        // 没有更新过，说明没有其他节点相连了，直接返回
        if (minI == -1) break;
        // 更新visited和distance
        visited[minI] = true;
        for (int j = 1; j <= m; ++j) {
            if (visited[j] == false) continue;
            for (auto v: graph[j]) {
                if (distance[v.first] == -1) distance[v.first] = distance[j] + v.second;
                else distance[v.first] = min(distance[v.first], distance[j] + v.second);
            }
        }
    }
    return distance[t];
}

class MyCmp {
public:
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

// 优先队列实现
int dijkstraHeap(vector<unordered_map<int, int>>& graph, int m, int s, int t) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, MyCmp> q;
    vector<int> distance(m + 1, -1);
    vector<bool> visited(m + 1, false);
    q.push({s, 0}), distance[s] = 0;
    // 队列里面没有元素，表示没有更短的路径加进去了
    // 这里区别于上面不用for循环来做的原因是，可能会出现两次while取出来的top.first的值相等的情况
    // 比如有多条路径到节点x的距离都是5，就会重复pop一次
    // 而上面是在取的时候加了一层节点没有访问过的判断
    while (!q.empty()) {
        // 找到q中最短路
        pair<int, int> top = q.top();
        q.pop();
        // 更新visited和distance
        visited[top.first] = true;
        for (int j = 1; j <= m; ++j) {
            if (visited[j] == false) continue;
            for (auto v: graph[j]) {
                int curDistance = distance[j] + v.second;
                if (distance[v.first] == -1 || curDistance < distance[v.first]) {
                    distance[v.first] = curDistance;
                    q.push({v.first, curDistance});
                }
            }
        }
    }

//    // 如果想用for循环，也可以这么写
//    for (int i = 1; i <= m; ++i) {
//        // 找到q中最短路
//        while(!q.empty() && visited[q.top().first])
//            q.pop();
//        if(q.empty()) break;
//        pair<int, int> top = q.top();
//        q.pop();
//        visited[top.first] = true;
//        // 更新visited和distance
//        for (int j = 1; j <= m; ++j) {
//            if (visited[j] == false) continue;
//            for (auto v: graph[j]) {
//                int curDistance = distance[j] + v.second;
//                if (distance[v.first] == -1 || curDistance < distance[v.first]) {
//                    distance[v.first] = curDistance;
//                    q.push({v.first, curDistance});
//                }
//            }
//        }
//    }
    return distance[t];
}

int main() {
    int m ,n, s, t, val;
    cin >> m >> n;
    vector<unordered_map<int, int>> graph(m + 1, unordered_map<int, int>());
    for (int i = 0; i < n; ++i) {
        cin >> s >> t >> val;
        graph[s][t] = val;
    }
    cout << dijkstraHeap(graph, m, 1, m) << endl;
    return 0;
}