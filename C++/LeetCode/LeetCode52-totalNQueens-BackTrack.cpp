#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    n 皇后问题 研究的是如何将 n 个皇后放置在 n × n 的棋盘上，并且使皇后彼此之间不能相互攻击。
    给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 */

bool checkFill(vector<vector<bool>>& map, int x, int y) {
    // 检测竖列是否有元素
    for (int i = 0; i < map.size(); ++i) {
        if(map[i][y] && i != x) return false;
    }

    // 检测斜列是否有元素，朝四个方向发散检测

    // 左上
    int i, j;
    i = x - 1, j = y - 1;
    while (i >= 0 && j >= 0) {
        if (map[i][j]) return false;
        i--, j--;
    }

    // 右上
    i = x - 1, j = y + 1;
    while (i >= 0 && j < map.size()) {
        if (map[i][j]) return false;
        i--, j++;
    }

    // 左下
    i = x + 1, j = y - 1;
    while (i < map.size() && j >= 0) {
        if (map[i][j]) return false;
        i++, j--;
    }

    // 右下
    i = x + 1, j = y + 1;
    while (i < map.size() && j < map.size()) {
        if (map[i][j]) return false;
        i++, j++;
    }

    return true;
}

void fillNQueenMap(vector<vector<bool>>& map, int& res, int line, int curFillCnt) {
    if (line == map.size()) {
        if (curFillCnt == map.size())
            res += 1;
        return;
    }

    // 从第一个位置开始填充，检查该位置是是否可以填入数字
    for (int i = 0; i < map.size(); ++i) {
        if (checkFill(map, line, i)) {
            map[line][i] = true;
            curFillCnt += 1;
            fillNQueenMap(map, res, line + 1, curFillCnt);
            curFillCnt -= 1;
            map[line][i] = false;
        }
    }
}

// 递归实现
int totalNQueens(int n) {
    vector<vector<bool>> map(n, vector<bool>(n));
    int res = 0;
    fillNQueenMap(map, res, 0, 0);
    return res;
}

int main() {
    cout << totalNQueens(4) << endl;
    system("pause");
    return 0;
}