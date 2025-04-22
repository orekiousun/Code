//
// Created by cd_ouymh on 2025/4/21.
// 重新安排行程：https://www.programmercarl.com/0332.%E9%87%8D%E6%96%B0%E5%AE%89%E6%8E%92%E8%A1%8C%E7%A8%8B.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 重新安排行程：https://leetcode.cn/problems/reconstruct-itinerary/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <queue>

// 使用map来递归，通过返回值直接操作返回，避免ret被清空
// 这里注意，如果只需要一个结果的，可以提前返回，这里会超时，有一个案例过不去
bool backtrack(vector<string>& ret, unordered_map<string, map<string, int>>& map, int retSize) {
    if (ret.size() == retSize) return true;
    string orin = ret.back();
    for (auto v : map[orin]) {
        if (v.second <= 0) continue;
        v.second--;
        ret.push_back(v.first);
        if (backtrack(ret, map, retSize)) return true;
        v.second++;
        ret.pop_back();
    }
    return false;
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
    // 后面这个容器选择map，使其有排序关系，而不是根据哈希函数来排序
    unordered_map<string, map<string, int>> map;
    for (auto ticket : tickets) {
        map[ticket[0]][ticket[1]]++;
    }
    vector<string> ret{"JFK"};
    backtrack(ret, map, tickets.size() + 1);
    return ret;
}


// 使用dfs实现
void dfs(vector<string>& ret, unordered_map<string, priority_queue<string, vector<string>, greater<string>>>& map,
         const string& cur) {
    while (map.count(cur) > 0 && map[cur].size() > 0) {
        string tmp = map[cur].top();
        map[cur].pop();
        dfs(ret, map, move(tmp));
    }
    // 这里先把遍历完了的加到结果里面去，这个递归执行完成后，前一个递归的cur一定和当前递归的cur是相连的
    ret.emplace_back(cur);
}

vector<string> findItinerary2(vector<vector<string>>& tickets) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> map;
    for (auto v: tickets) {
        map[v[0]].push(v[1]);
    }
    vector<string> ret;
    dfs(ret, map, "JFK");
    reverse(ret.begin(), ret.end());
    return ret;
}


int main() {
    // [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
    vector<string> v1{"JFK","SFO"};
    vector<string> v2{"JFK","ATL"};
    vector<string> v3{"SFO","ATL"};
    vector<string> v4{"ATL","JFK"};
    vector<string> v5{"ATL","SFO"};
    vector<vector<string>> tickets{v1, v2, v3, v4, v5};
    findItinerary2(tickets);
    return 0;
}