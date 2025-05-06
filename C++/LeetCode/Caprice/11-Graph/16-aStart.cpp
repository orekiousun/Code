//
// Created by ousun on 2025/5/5.
// A*算法：https://www.programmercarl.com/kamacoder/0126.%E9%AA%91%E5%A3%AB%E7%9A%84%E6%94%BB%E5%87%BBastar.html#astar
// A*算法：https://kamacoder.com/problempage.php?pid=1203
// F = G + H
// G = 从起点到该节点路径消耗
// H = 该节点到终点的预估消耗
//

#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string.h>
#include <array>

const int arr[8][2] = {{-1, -2}, {-2, -1}, {1, -2}, {2, -1},
                       {-1, 2}, {-2, 1}, {1, 2}, {2, 1}};

struct Node {
    int x;      // x坐标
    int y;      // y坐标
    int g;      // 距离初始点的距离
    int h;      // 距离结束点的距离
    int f;      // f = g + h
    bool operator<(const Node & n) const {
        return n.f < f;
    }
};

int aStar(const Node& start, const Node& end) {
    // 记录步数
    int step[1000][1000];
    memset(step, 0, sizeof(step));
    priority_queue<Node> q;
    q.push(start);
    Node next;
    while (!q.empty()) {
        Node cur = q.top();
        q.pop();
        if (cur.x == end.x && cur.y == end.y) break;
        for (int i = 0; i < 8; ++i) {
            next.x = cur.x + arr[i][0], next.y = cur.y + arr[i][1];
            // 超界或已经访问过了，跳过
            if (!(next.x >= 0 && next.x < 1000 && next.y >= 0 && next.y < 1000)) continue;
            if (step[next.x][next.y] != 0) continue;
            int dis = (end.x - next.x) * (end.x - next.x) + (end.y - next.y) * (end.y - next.y);
            step[next.x][next.y] = step[cur.x][cur.y] + 1;
            // 每次走 1^2 + 2^2
            next.g = cur.g + 5, next.h = dis, next.f = next.g + next.h;
            q.push(next);
        }
    }
    while (q.empty()) q.pop();
    return step[end.x][end.y];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int dis = (x1 - x1) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        Node start, end;
        start.x = x1 - 1, start.y = y1 - 1, start.g = 0, start.h = dis, start.f = dis;
        end.x = x2 - 1, end.y = y2 - 1, end.g = dis, end.h = 0, end.f = dis;
        cout << aStar(start, end) << endl;
    }
    return 0;
}
