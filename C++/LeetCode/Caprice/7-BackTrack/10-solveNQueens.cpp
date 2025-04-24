//
// Created by cd_ouymh on 2025/4/23.
// N皇后：https://www.programmercarl.com/0051.N%E7%9A%87%E5%90%8E.html
// N皇后：https://leetcode.cn/problems/n-queens/
//

#include <iostream>
using namespace std;
#include <vector>

// 检查是否满足N皇后的规则，不在同一行、列以及斜线
bool checkMatch(vector<string>& path, int idx, int n) {
    int len = path.size();
    for (int i = len - 1; i >= 0; --i) {
        if (path[i][idx] == 'Q') return false;
        int y1 = idx - (len - i);
        if (y1 >= 0 && path[i][y1] == 'Q') return false;
        int y2 = idx + (len - i);
        if (y2 < n && path[i][y2] == 'Q') return false;
    }
    return true;
}

void backtrack(vector<vector<string>>& ret, vector<string>& path, int n) {
    int x = path.size();
    if (x == n) {
        ret.push_back(path);
        return;
    }

    string tmp(n, '.');
    for (int y = 0; y < n; ++y) {
        if (checkMatch(path, y, n)) {
            tmp[y] = 'Q';
            path.push_back(tmp);
            backtrack(ret, path, n);
            tmp[y] = '.';
            path.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> ret;
    vector<string> path;
    backtrack(ret, path, n);
    return ret;
}

int main() {
    solveNQueens(4);
    return 0;
}
