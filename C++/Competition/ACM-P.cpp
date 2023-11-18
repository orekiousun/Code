#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>
#include<set>
#include<algorithm>

void dfs(unordered_map<int, vector<int>>& map, vector<bool>& visited, int s, int& temp) {
    temp++;
    visited[s] = 1;
    for (auto item : map[s]) {
        if(!visited[item])
            dfs(map, visited, item, temp);
    }
    return;
}

void func(int n) {
    unordered_map<int, vector<int>> map;
    vector<vector<int>> triangles(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> triangles[i][0];
        cin >> triangles[i][1];
        cin >> triangles[i][2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 3; k++) {
                if(triangles[i][k] == triangles[j][0] || triangles[i][k] == triangles[j][1] || triangles[i][k] == triangles[j][2])
                    count++;
            }
            if(count == 2) {
                map[i].push_back(j);
            }
        }
    }
    int cnt = 0;
    multiset<int> res;
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++) {
        if(!visited[i]) {
            int temp = 0;
            visited[i] = 1;
            dfs(map, visited, i, temp);
            cnt++;
            res.insert(temp);
        }
    }
    cout << cnt << endl;
    for (set<int>::iterator it = res.begin(); it != res.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;
}

void func(int n, int flag) {
    unordered_map<int, int> parent;
    unordered_map<int, vector<int>> unionFind;
    vector<vector<int>> triangles(n, vector<int>(3));
    for (int i = 0; i < n; i++) {
        cin >> triangles[i][0];
        cin >> triangles[i][1];
        cin >> triangles[i][2];
        parent[i] = i;
        unionFind[i].push_back(i);
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int count = 0;
            for (int k = 0; k < 3; k++) {
                if(triangles[i][k] == triangles[j][0] || triangles[i][k] == triangles[j][1] || triangles[i][k] == triangles[j][2])
                    count++;
            }
            if(count == 2) {
                if(parent[j] != parent[i]) {
                    // 更新parent[j]及其并查集
                    for(auto item : unionFind[parent[j]]) {
                        unionFind[parent[i]].push_back(item);
                        parent[item] = parent[i];
                    }
                    parent[j] = parent[i];
                }
            }
        }
    }
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        count[parent[i]]++;
    }

    multiset<int> res;
    cout << count.size() << endl;
    for (auto item : count) {
        res.insert(item.second);
    }
    for (auto item : res) {
        cout << item << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        func(n, 1);
    }
    return 0;
}
