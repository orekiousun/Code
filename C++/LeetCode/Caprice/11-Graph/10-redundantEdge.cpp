//
// Created by ousun on 2025/5/4.
// 冗余连接：https://www.programmercarl.com/kamacoder/0108.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5.html#%E6%80%9D%E8%B7%AF
// 冗余连接：https://kamacoder.com/problempage.php?pid=1181
// 冗余连接II：https://www.programmercarl.com/kamacoder/0109.%E5%86%97%E4%BD%99%E8%BF%9E%E6%8E%A5II.html
// 冗余连接II：https://kamacoder.com/problempage.php?pid=1182
//

#include <iostream>
using namespace std;
#include <vector>
#include <array>

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

// 冗余连接：https://kamacoder.com/problempage.php?pid=1181
void redundantEdgeI() {
    int n;
    cin >> n;
    UnionFind* unionFind = new UnionFind(n + 1);
    int retU, retV;
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        if (unionFind->isSame(u, v))
            retU = u, retV = v;
        unionFind->join(u, v);
    }
    cout << retU << " " << retV;
}

// 判断删除一条边后，剩余的节点还是不是连通的
bool checkDeleteEdge(int n, vector<array<int, 2>>& input, int deleteIdx) {
    UnionFind* unionFind = new UnionFind(n + 1);
    for (int i = 0; i < input.size(); ++i) {
        if (i == deleteIdx) continue;
        int u = input[i][0], v = input[i][1];
        unionFind->join(u, v);
    }

    // 遍历所有边，判断是否有不在一个集合里面的
    for (int i = 2; i <= n; ++i) {
        if (!unionFind->isSame(i, i - 1)) return false;
    }
    return true;
}

// 冗余连接II：https://kamacoder.com/problempage.php?pid=1182
void redundantEdgeII() {
    int n;
    cin >> n;
    // 记录输入
    vector<array<int, 2>> input(n, array<int, 2>({0, 0}));
    vector<int> inDegree(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> input[i][0] >> input[i][1];
        inDegree[input[i][1]]++;
    }
    UnionFind* unionFind = new UnionFind(n + 1);
    int retU = 0, retV = 0;
    for (int i = 0; i < n; ++i) {
        int u = input[i][0], v = input[i][1];
        // 1-入度为2时，尝试删除这条边，如果删除后还是联通的，就记录结果
        if(inDegree[v] > 1 && checkDeleteEdge(n, input, i))
            retU = u, retV = v;
        unionFind->join(u, v);
    }

    if (retV != 0 && retU != 0) {
        cout << retU << " " << retV << endl;
    }
    else {
        // 2-如果并查集里两个点已经是再同一个集合里面了，说明新加进来的边是重复的
        unionFind->init();
        for (int i = 0; i < n; ++i) {
            int u = input[i][0], v = input[i][1];
            if (unionFind->isSame(u, v))
                retU = u, retV = v;
            unionFind->join(u, v);
        }
        cout << retU << " " << retV << endl;
    }
}

// 并查集判断环，如果当前的节点 u，v本身都在一个集合里面，再给他们两个加一个边，就成了环
int main() {
//    redundantEdgeI();
    redundantEdgeII();
    return 0;
}
