#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

/*
    给定一个三角形 triangle ，找出自顶向下的最小路径和。
    每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
    也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
 */

int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle[triangle.size() - 1].size();
    vector<vector<int>> map(m, vector<int>(n, 0));
    map[0][0] = triangle[0][0];
    if (n == 1) return map[0][0];
    int res = 0x7fffffff;

    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < triangle[i].size(); ++j) {
            int l = max(j - 1, 0), r = min(j, (int)(triangle[i - 1].size() - 1));
            map[i][j] = min(map[i - 1][l], map[i - 1][r]) + triangle[i][j];
            if (i == m - 1)
                res = min(res, map[i][j]);
        }
    }

    return res;
}


int main() {
    vector<int> line1{2};
    vector<int> line2{3, 4};
    vector<int> line3{6, 5, 7};
    vector<int> line4{4, 1, 8, 3};
    vector<vector<int>> triangle{line1, line2, line3, line4};
    cout << minimumTotal(triangle) << endl;
    system("pause");
    return 0;
}
