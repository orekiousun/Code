#include<iostream>
using namespace std;
#include<unordered_map>
#include<vector>


void dfs(int b, unordered_map<int, vector<int>>& map, vector<int>& res) {
    for(auto item : map[b]) {
        if(res[item] == 0) {
            res[item] = b;
            dfs(item, map, res);
        }
    }
    return;
}

int main(int argc, char const *argv[]) {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> map;
    vector<int> res(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        int b, e;
        cin >> b >>e;
        map[b].push_back(e);
        map[e].push_back(b);
    }
    dfs(n, map, res);
    for (int i = 1; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
