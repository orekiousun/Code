#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include<unordered_map>

/*
    给你一个变量对数组 equations 和一个实数值数组 values 作为已知条件，其中 equations[i] = [Ai, Bi] 和 values[i] 共同表示等式 Ai / Bi = values[i] 。每个 Ai 或 Bi 是一个表示单个变量的字符串。
    另有一些以数组 queries 表示的问题，其中 queries[j] = [Cj, Dj] 表示第 j 个问题，请你根据已知条件找出 Cj / Dj = ? 的结果作为答案。
    返回 所有问题的答案 。如果存在某个无法确定的答案，则用 -1.0 替代这个答案。如果问题中出现了给定的已知条件中没有出现的字符串，也需要用 -1.0 替代这个答案。
    注意：输入总是有效的。你可以假设除法运算中不会出现除数为 0 的情况，且不存在任何矛盾的结果。
*/
// 方案：建图DFS
double DFS(unordered_map<string, unordered_map<string, double>>& strMap, unordered_map<string, bool>& visited, string begin, string end) {
    if(begin == end) return 1;
    visited[begin] = true;
    double res = 1.0;
    for (unordered_map<string, double>::iterator it = strMap[begin].begin(); it != strMap[begin].end(); it++) {
        string temp = (*it).first;
        if(visited[temp] == false) {
            res = strMap[begin][temp] * DFS(strMap, visited, temp, end);
            if(res != 0) return res;
        }
    }
    return 0;
}

vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    vector<double> res(queries.size(), 0);
    unordered_map<string, unordered_map<string, double>> strMap;
    unordered_map<string, bool> visited;
    for (int i = 0; i < equations.size(); i++) {
        strMap[equations[i][0]][equations[i][1]] = values[i];
        strMap[equations[i][1]][equations[i][0]] = 1 / values[i];
        visited[equations[i][0]] = false;
        visited[equations[i][1]] = false;
    }
    for(int i = 0; i < queries.size(); i++) {
        if(strMap.find(queries[i][0]) == strMap.end() || strMap.find(queries[i][1]) == strMap.end()) {
            // 问题中出现了给定的已知条件中没有出现的字符串
            res[i] = -1.0;
        }
        else {
            unordered_map<string, bool> visitedNew = visited;
            res[i] = DFS(strMap, visitedNew, queries[i][0], queries[i][1]);
            res[i] = res[i] == 0 ? -1.0 : res[i];
        }
    }
    return res;
}

int main() {
    vector<string> e1{"a", "b"};
    vector<string> e2{"b", "c"};
    vector<vector<string>> equations{e1, e2};
    vector<double> values{2.0, 3.0};
    vector<string> q1{"a", "c"};
    vector<string> q2{"b", "a"};
    vector<string> q3{"a", "e"};
    vector<string> q4{"a", "a"};
    vector<string> q5{"x", "x"};
    vector<vector<string>> queries{q1, q2, q3, q4, q5};
    vector<double> res = calcEquation(equations, values, queries);
    system("pause");
    return 0;
}