#include<iostream>
using namespace std;
#include<vector>

/*
    顺时针打印矩阵的值
*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
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

int main(int argc, char const *argv[]) {
    vector<int> l1{1, 2, 3};
    vector<int> l2{4, 5, 6};
    vector<int> l3{7, 8, 9};
    vector<vector<int>> matrix{l1, l2, l3};
    vector<int> ans = spiralOrder(matrix);
    return 0;
}

