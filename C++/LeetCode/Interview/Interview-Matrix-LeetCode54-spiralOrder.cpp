//
// Created by ousun on 2024/9/29.
// https://leetcode.cn/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>

// 按圈遍历
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int len = m * n;
    vector<int> ret(m * n, 0);
    int idx = 0;
    // 遍历第i圈
    int x, y;
    for(int i = 0; i < (m + 1) / 2; i++) {
        x = i, y = i;
        // 第一行
        while (y < n - i - 1 && idx < len)
            ret[idx++] = matrix[x][y++];
        while (x < m - i - 1 && idx < len)
            ret[idx++] = matrix[x++][y];
        while (y > i && idx < len)
            ret[idx++] = matrix[x][y--];
        while (x > i && idx < len)
            ret[idx++] = matrix[x--][y];
    }
    if (idx != len)
        ret[idx++] = matrix[x][y];
    return ret;
}

int main() {
    vector<int> l1{1,2,3};
    vector<int> l2{4,5,6};
    vector<int> l3{7,8,9};
    vector<vector<int>> matrix{l1, l2, l3};
    vector<int> ret = spiralOrder(matrix);
    for(vector<int>::iterator it = ret.begin(); it != ret.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}