#include<iostream>
using namespace std;
#include<vector>

// https://leetcode.cn/problems/spiral-matrix/
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

// https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/
//  顺时针打印矩阵的值
vector<int> spiralArray(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty()) return ans;
    int m = matrix.size(), n = matrix[0].size();
    int size = m * n;
    ans.resize(size, 0);
    int count = 0, begin = 0;
    while (count < size) {
        for (int i = begin; i <= begin + n - 1; i++) {
            ans[count++] = matrix[begin][i];
            if(count == size) return ans;
        }

        for (int i = begin + 1; i <= begin + m - 2; i++) {
            ans[count++] = matrix[i][begin + n - 1];
            if(count == size) return ans;
        }
        
        for (int i = n + begin - 1; i >= begin; i--) {
            ans[count++] = matrix[begin + m - 1][i];
            if(count == size) return ans;
        }
        
        for (int i = begin + m - 2; i >= begin + 1; i--) {
            ans[count++] = matrix[i][begin];
            if(count == size) return ans;
        }
        begin++, m -= 2, n -= 2;
    }
    return ans;
}

int main() {
    vector<int> l1{1, 2, 3};
    vector<int> l2{4, 5, 6};
    vector<int> l3{7, 8, 9};
    vector<vector<int>> matrix{l1, l2, l3};
    vector<int> ans = spiralOrder(matrix);
    return 0;
}

