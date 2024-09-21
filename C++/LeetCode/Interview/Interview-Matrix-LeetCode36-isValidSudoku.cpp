//
// Created by cd_ouymh on 2024/9/21.
// https://leetcode.cn/problems/valid-sudoku/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <cstring>

// 判断块
bool judgeBlock(vector<vector<char>>& board, int x, int y) {
    unordered_map<char, bool> exist;
    for (int i = x; i < x + 3; ++i) {
        for (int j = y; j < y + 3; ++j) {
            if (board[i][j] != '.' and exist[board[i][j]] == true)
                return false;
            exist[board[i][j]] = true;
        }
    }

    return true;
}

// 遍历了三次，可以优化为遍历一次
bool isValidSudoku(vector<vector<char>>& board) {
    // 先检查换行
    for(auto line : board) {
        unordered_map<char, bool> exist;
        for (auto c: line) {
            if (c != '.' and exist[c] == true)
                return false;
            exist[c] = true;
        }
    }

    // 再检查列
    for (int i = 0; i < 9; ++i) {
        unordered_map<char, bool> exist;
        for (int j = 0; j < 9; ++j) {
            if (board[j][i] != '.' and exist[board[j][i]] == true)
                return false;
            exist[board[j][i]] = true;
        }
    }

    // 最后检查块
    int x = 0, y = 0;
    while (x < 9) {
        for (int i = 0; i < 3; ++i) {
            if (judgeBlock(board, x, y) == false)
                return false;
            y = y + 3;
        }
        x = x + 3, y = 0;
    }

    return true;
}

bool isValidSudoku_1(vector<vector<char>>& board) {
    int rows[9][9];
    int columns[9][9];
    int subBoxes[3][3][9];

    // 初始化数组
    memset(rows, 0, sizeof(rows));
    memset(columns, 0, sizeof(columns));
    memset(subBoxes, 0, sizeof(subBoxes));

//    或者直接用vector初始化
//    vector<vector<int>> rowsV(9, vector<int>(9, 0));
//    vector<vector<int>> columnsV(9, vector<int>(9, 0));
//    vector<vector<vector<int>>> subBoxesV(3, vector<vector<int>>(3, vector<int>(9, 0)));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if(c == '.')
                continue;
            int idx = c - '0' - 1;
            rows[i][idx]++;                 // 标记第i行中已有idx
            columns[j][idx]++;              // 标记第j列中已有idx
            subBoxes[i / 3][j / 3][idx]++;  // 标记第i/3, j/3个box中已有idx
            if (rows[i][idx] > 1 || columns[j][idx] > 1 || subBoxes[i / 3][j / 3][idx] > 1)
                return false;
        }
    }

    return true;
}

int main() {
    vector<char> l1{'5', '3', '.', '.', '7', '.', '.', '.', '.'};
    vector<char> l2{'6', '.', '.', '1', '9', '5', '.', '.', '.'};
    vector<char> l3{'.', '9', '8', '.', '.', '.', '.', '6', '.'};
    vector<char> l4{'8', '.', '.', '.', '6', '.', '.', '.', '3'};
    vector<char> l5{'4', '.', '.', '8', '.', '3', '.', '.', '1'};
    vector<char> l6{'7', '.', '.', '.', '2', '.', '.', '.', '6'};
    vector<char> l7{'.', '6', '.', '.', '.', '.', '2', '8', '.'};
    vector<char> l8{'.', '.', '.', '4', '1', '9', '.', '.', '5'};
    vector<char> l9{'.', '.', '.', '.', '8', '.', '.', '7', '9'};
    vector<vector<char>> board{l1, l2, l3, l4, l5, l6, l7, l8, l9};
    cout << isValidSudoku(board) << endl;
    return 0;
}
