//
// Created by cd_ouymh on 2025/4/23.
// 解数独：https://www.programmercarl.com/0037.%E8%A7%A3%E6%95%B0%E7%8B%AC.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 解数独：https://leetcode.cn/problems/sudoku-solver/
//

#include <iostream>
using namespace std;
#include <vector>
#include <array>

array<bool, 9> calcMatchNumberL(vector<vector<char>>& board, int x, int y) {
    array<bool, 9> arr;
    arr.fill(false);

    // 计算行
    for (int i = 0; i < 9; ++i) {
        if (board[x][i] != '.') arr[board[x][i] - '1'] = true;
    }

    // 计算列
    for (int i = 0; i < 9; ++i) {
        if (board[i][y] != '.') arr[board[i][y] - '1'] = true;
    }

    // 计算九宫格起始点
    int x0 = (x / 3) * 3;
    int y0 = (y / 3) * 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[x0 + i][y0 + j] != '.') arr[board[x0 + i][y0 + j] - '1'] = true;
        }
    }

    return arr;
}

bool solveSudoku(vector<vector<char>>& board, int x) {
    if (x == 9) return true;
    // 判断当前行是否填充满，填充满了就直接遍历下一行
    int y = -1;
    for (int i = 0; i < 9; ++i) {
        if (board[x][i] == '.') {
            y = i;
            break;
        }
    }
    if (y == -1) return solveSudoku(board, x + 1);

    // 计算row,col位置可选的数字列表
    array<bool, 9> arr = calcMatchNumberL(board, x, y);
    for (int i = 0; i < 9; ++i) {
        if (arr[i] == true) continue;
        board[x][y] = i + '1';
        if (solveSudoku(board, x)) return true;
        board[x][y] = '.';
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board, 0);
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[i].size(); ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<char> v1{'5','3','.','.','7','.','.','.','.'};
    vector<char> v2{'6','.','.','1','9','5','.','.','.'};
    vector<char> v3{'.','9','8','.','.','.','.','6','.'};
    vector<char> v4{'8','.','.','.','6','.','.','.','3'};
    vector<char> v5{'4','.','.','8','.','3','.','.','1'};
    vector<char> v6{'7','.','.','.','2','.','.','.','6'};
    vector<char> v7{'.','6','.','.','.','.','2','8','.'};
    vector<char> v8{'.','.','.','4','1','9','.','.','5'};
    vector<char> v9{'.','.','.','.','8','.','.','7','9'};
    vector<vector<char>> board{v1, v2, v3, v4, v5, v6, v7, v8, v9};
    solveSudoku(board);
    return 0;
}