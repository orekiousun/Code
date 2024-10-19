//
// Created by cd_ouymh on 2024/10/19.
// https://leetcode.cn/problems/game-of-life/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>

// 序列化细胞
int serializeCell(int value) {
    return value == 1 ? (1 << 4) : 0;
}

// 反序列化细胞
int deserializeCell(int value) {
    return (value & (1 << 4)) == 0 ? 0 : 1;
}

// 获取周围活细胞的数量
int getAroundLiveCellCnt(vector<vector<int>>& serializeBoard, int x, int y) {
    int cnt = 0;
    int m = serializeBoard.size(), n = serializeBoard[0].size();
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int j = y - 1; j <= y + 1; ++j) {
            if (i >= 0 && i < m && j >= 0 && j < n)
                cnt += deserializeCell(serializeBoard[i][j]);
        }
    }
    // 重复计算了自己，最后减去
    if (deserializeCell(serializeBoard[x][y]) == 1)
        return cnt - 1 + (1 << 4);
    else
        return cnt;
}

// 更新细胞状态
int refreshCellState(int serializeValue) {
    int liveBytes = 1 << 4;
    int liveCellCnt = serializeValue & (liveBytes - 1);
    if ((serializeValue & liveBytes) == 0) {
        // 死细胞
        if (liveCellCnt == 3) return 1;
        return 0;
    }
    else {
        // 活细胞
        if (liveCellCnt < 2) return 0;
        if (liveCellCnt > 3) return 0;
        return 1;
    }
}


// 由于每个细胞周围最多8个活细胞，用二进制标识即最多占据4位，则我们用第5位记录细胞原本是死是活
void gameOfLife(vector<vector<int>>& board) {
    // 先更新一遍所有细胞的值，将1更新为10000，0更新不变
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = serializeCell(board[i][j]);
        }
    }

    // 更新细胞矩阵
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = getAroundLiveCellCnt(board, i, j);
        }
    }

    // 更新细胞状态
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            board[i][j] = refreshCellState(board[i][j]);
        }
    }
}

int main() {
    vector<int> l1{0, 1, 0};
    vector<int> l2{0, 0, 1};
    vector<int> l3{1, 1, 1};
    vector<int> l4{0, 0, 0};
    vector<vector<int>> matrix{l1, l2, l3, l4};
    gameOfLife(matrix);
    return 0;
}