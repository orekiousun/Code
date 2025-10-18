//
// Created by ousun on 2025/10/18.
// N皇后II：https://www.programmercarl.com/0052.N%E7%9A%87%E5%90%8EII.html
// N皇后II：https://leetcode.cn/problems/n-queens-ii/
//

#include <iostream>
using namespace std;
#include <vector>

bool checkPos(vector<int>& record, int curIdx, int pos) {
    for (int i = 0; i < curIdx; ++i) {
        if (record[i] == pos)
            return false;
        if (abs(record[i] - pos) == curIdx - i)
            return false;
    }
    return true;
}

// 其实就是和N皇后问题一样，就是统计一下有多少种解法
void backtrack(int& ret, vector<int>& record, int curIdx) {
    int size = record.size();
    if (curIdx == size) {
        ret++;
        return;
    }

    for (int i = 0; i < size; ++i) {
        if (checkPos(record, curIdx, i)) {
            record[curIdx] = i;
            backtrack(ret, record, curIdx + 1);
            record[curIdx] = 0;
        }
    }
}

int totalNQueens(int n) {
    int ret = 0;
    vector<int> record(n, 0);
    backtrack(ret, record, 0);
    return ret;
}

int main() {
    totalNQueens(4);
    return 0;
}