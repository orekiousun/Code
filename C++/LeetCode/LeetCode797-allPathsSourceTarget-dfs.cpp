//
// Created by cd_ouymh on 2024/8/24.
// https://leetcode.cn/problems/all-paths-from-source-to-target/
//

#include <iostream>
using namespace std;
#include <vector>]
#include <stack>

// 深度搜索
void dfs(vector<vector<int>>& graph, vector<int>& s, vector<vector<int>>& ret, int cur) {
    s.push_back(cur);

    if(cur == graph.size() - 1) {
        ret.push_back(s);
//        这里由于最后一个节点没有其它叶子节点了，可以不用提前返回处理
//        s.pop_back();
//        return;
    }

    for(int i : graph[cur]) {
        dfs(graph, s, ret, i);
    }

    s.pop_back();
}

// 递归方法
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> s;
    vector<vector<int>> ret;
    dfs(graph, s, ret, 0);
    return ret;
}

// 非递归方法
vector<vector<int>> allPathsSourceTarget_stack(vector<vector<int>>& graph) {
    // 记录所有结果
    vector<vector<int>> ret;
    // 记录索引
    vector<int> idxL(graph.size(), 0);
    // 记录单条结果
    vector<int> singleRet;

    singleRet.push_back(0);
    while (!singleRet.empty()) {
        int cur = singleRet[singleRet.size() - 1];
        int idx = idxL[cur];
        if (cur == graph.size() - 1) {
            ret.push_back(singleRet);
        }
        else if (idx < graph[cur].size()) {
            int curNew = graph[cur][idx];
            singleRet.push_back(graph[cur][idx]);
            idxL[cur]++;
            idxL[curNew] = 0;
            continue;
        }

        singleRet.pop_back();
    }
    return ret;
}

int main() {
    vector<int> v0{4,3,1};
    vector<int> v1{3,2,4};
    vector<int> v2{3};
    vector<int> v3{4};
    vector<int> v4{};
    vector<vector<int>> graph{v0, v1, v2, v3, v4};

    vector<vector<int>> ret = allPathsSourceTarget_stack(graph);
    for(vector<int> vec : ret) {
        for (int point : vec) {
            cout << point << " ";
        }
        cout << endl;
    }

    return 0;
}


