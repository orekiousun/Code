//
// Created by ousun on 2024/11/30.
// 螺旋矩阵：https://www.programmercarl.com/0059.%E8%9E%BA%E6%97%8B%E7%9F%A9%E9%98%B5II.html
// 螺旋矩阵：https://leetcode.cn/problems/spiral-matrix/description/
// 螺旋遍历二维数组：https://leetcode.cn/problems/shun-shi-zhen-da-yin-ju-zhen-lcof/description/
//

#include <iostream>
using namespace std;
#include <vector>

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

int main() {

}