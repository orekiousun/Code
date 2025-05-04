//
// Created by ousun on 2025/5/4.
// 并查集：https://www.programmercarl.com/kamacoder/%E5%9B%BE%E8%AE%BA%E5%B9%B6%E6%9F%A5%E9%9B%86%E7%90%86%E8%AE%BA%E5%9F%BA%E7%A1%80.html#%E8%B7%AF%E5%BE%84%E5%8E%8B%E7%BC%A9
//

#include <iostream>
using namespace std;
#include <vector>

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