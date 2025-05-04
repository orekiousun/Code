//
// Created by ousun on 2025/5/4.
// 寻找存在的路径：https://www.programmercarl.com/kamacoder/0107.%E5%AF%BB%E6%89%BE%E5%AD%98%E5%9C%A8%E7%9A%84%E8%B7%AF%E5%BE%84.html#%E6%80%9D%E8%B7%AF
// 寻找存在的路径：https://kamacoder.com/problempage.php?pid=1179
//

#include <iostream>
using namespace std;
#include <vector>

/*
 * 给定一个包含 n 个节点的无向图中，节点编号从 1 到 n （含 1 和 n ）。
 * 你的任务是判断是否有一条从节点 source 出发到节点 destination 的路径存在。
 * 即：判断source和destination是否在一个并查集里面即可
 */

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

int main() {
    int m, n;
    cin >> m >> n;
    UnionFind* unionFind = new UnionFind(m + 1);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        unionFind->join(u, v);
    }
    int source, destination;
    cin >> source >> destination;
    cout << unionFind->isSame(source, destination) << endl;
    return 0;
}
