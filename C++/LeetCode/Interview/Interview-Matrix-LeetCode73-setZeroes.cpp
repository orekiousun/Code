//
// Created by ousun on 2024/10/17.
// https://leetcode.cn/problems/set-matrix-zeroes/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>

//  使用两个二进制数来分别表示行、列的状态是否为0(会遇到数组过大导致二进制位数不够用的情况)
void setZeroes(vector<vector<int>>& matrix) {
    int mBytes = 0, nByes = 0;
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0) {
                mBytes |= 1 << i;
                nByes |= 1 << j;
            }
        }
    }

    // 处理行
    for (int i = 0; i < m; ++i) {
        if((mBytes & (1 << i)) != 0) {
            for (int j = 0; j < n; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // 处理列
    for (int i = 0; i < n; ++i) {
        if((nByes & (1 << i)) != 0) {
            for (int j = 0; j < m; ++j) {
                matrix[j][i] = 0;
            }
        }
    }
}

// 使用矩阵的第一行和第一列表标识对应的行、列是否存在0
// 需要用两个参数来记录原本第一行和第一列是否存在 0
void setZeros_1(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool flagM = false, flagN = false;
    for (int i = 0; i < m; ++i) {
        if (matrix[i][0] == 0)
            flagM = true;
    }
    for (int j = 0; j < n; ++j) {
        if (matrix[0][j] == 0)
            flagN = true;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 0)
                matrix[i][0] = 0, matrix[0][j] = 0;
        }
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
    }
    if (flagM) {
        for (int i = 0; i < m; ++i) {
            matrix[i][0] = 0;
        }
    }
    if (flagN) {
        for (int j = 0; j < n; ++j) {
            matrix[0][j] = 0;
        }
    }
}

int main() {
    vector<int> l1{0, 1, 2, 0};
    vector<int> l2{3, 4, 5, 2};
    vector<int> l3{1, 3, 1, 5};
    vector<vector<int>> matrix{l1, l2, l3};
    setZeroes(matrix);
    return 0;
}
