//
// Created by ousun on 2025/5/3.
// 所有可达路径：https://www.programmercarl.com/kamacoder/0098.%E6%89%80%E6%9C%89%E5%8F%AF%E8%BE%BE%E8%B7%AF%E5%BE%84.html#%E6%8F%92%E6%9B%B2
// 所有可达路径：https://leetcode.cn/problems/all-paths-from-source-to-target/
//

#include <iostream>
using namespace std;
#include <vector>


void backtrack(vector<vector<int>>& ret, vector<int>& path, vector<vector<int>>& graph, int start, int end) {
    if (start == end) {
        ret.push_back(path);
        return;
    }

    for (int i = 0; i < graph[start].size(); ++i) {
        int cur = graph[start][i];
        path.push_back(cur);
        backtrack(ret, path, graph, cur, end);
        path.pop_back();
    }
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int>> ret;
    vector<int> path{0};
    backtrack(ret, path, graph, 0, graph.size() - 1);
    return ret;
}

int main() {
    vector<int> v1{1,2};
    vector<int> v2{3};
    vector<int> v3{3};
    vector<int> v4{};
    vector<vector<int>> graph{v1, v2, v3, v4};
    allPathsSourceTarget(graph);
    return 0;
}
