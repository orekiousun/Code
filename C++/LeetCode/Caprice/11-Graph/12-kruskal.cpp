//
// Created by ousun on 2025/5/4.
// Kruskal：https://www.programmercarl.com/kamacoder/0053.%E5%AF%BB%E5%AE%9D-Kruskal.html#%E8%A7%A3%E9%A2%98%E6%80%9D%E8%B7%AF
// Kruskal：https://kamacoder.com/problempage.php?pid=1053
//


#include <iostream>
using namespace std;
#include <vector>
#include <array>
#include <algorithm>

class UnionFind {
private:
    vector<int> father;
public:
    UnionFind(int size) {
        father = vector<int>(size, 0);
        init();
    }

    void init() {
        for (int i = 0; i < father.size(); ++i) {
            father[i] = i;
        }
    }

    // 查找元素的父亲节点
    int find(int u) {
        if (father[u] == u)
            return u;
        else
            // 递归查找，路径压缩
            return father[u] = find(father[u]);
    }

    // 返回两个元素是否在一个集合里面
    bool isSame(int u, int v) {
        return find(u) == find(v);
    }

    // 添加两个元素到一个集合里面
    void join(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return;
        father[v] = u;
    }
};

static bool cmp(const array<int, 3>& a, const array<int, 3>& b) {
    return a[2] < b[2];
}

// 核心思路：从最短的边开始遍历，新加入的边需要不能和原来已经加入过的边构成环（并查集）
// kruskal并不需要用visited来标识哪个节点已经访问过了，因为全部节点都访问了一遍，图不一定是连通的
int kruskal(int n, vector<array<int, 3>>& input) {
    UnionFind* unionFind = new UnionFind(n + 1);
    sort(input.begin(), input.end(), cmp);
    int ret = 0;
    for (int i = 0; i < input.size(); ++i) {
        int v1 = input[i][0], v2 = input[i][1], val = input[i][2];
        if (unionFind->isSame(v1, v2)) continue;
        ret += val;
//        cout << "v1:" << v1 << " v2:" << v2 << " ret:" << ret << endl;
        unionFind->join(v1, v2);
    }
    delete unionFind;
    return ret;
}

int main() {
    int v, e;
    cin >> v >> e;
    vector<array<int, 3>> input(e, array<int, 3>{0, 0, 0});
    for (int i = 0; i < e; ++i) {
        cin >> input[i][0] >> input[i][1] >> input[i][2];
    }
    cout << kruskal(v, input) << endl;
    return 0;
}