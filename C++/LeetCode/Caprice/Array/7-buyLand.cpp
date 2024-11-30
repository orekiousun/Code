//
// Created by ousun on 2024/11/30.
// 开发商购买土地：https://www.programmercarl.com/kamacoder/0044.%E5%BC%80%E5%8F%91%E5%95%86%E8%B4%AD%E4%B9%B0%E5%9C%9F%E5%9C%B0.html#%E6%80%9D%E8%B7%AF
// 开发商购买土地：https://kamacoder.com/problempage.php?pid=1044
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// acm模式
int main() {
    // 第一行输入两个正整数，代表 n 和 m。
    // 接下来的 n 行，每行输出 m 个正整数。
    int m, n;
    cin >> m >> n;
    // 构造区间和
    vector<vector<int>> arr(m, vector<int>(n));
    for (int i = 0; i < m; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            int num;
            cin >> num;
            sum += num;
            int add = i - 1 >= 0 ? arr[i - 1][j] : 0;
            arr[i][j] = sum + add;
        }
    }

    int ret = INT_MAX;
    // 遍历最后一列和最后一行
    for(int i = 0; i < m - 1; i++) {
        int num1 = arr[i][n - 1];
        int num2 = arr[m - 1][n - 1] - num1;
        ret = min(abs(num1 - num2), ret);
    }
    for (int i = 0; i < n - 1; ++i) {
        int num1 = arr[m - 1][i];
        int num2 = arr[m - 1][n - 1] - num1;
        ret = min(abs(num1 - num2), ret);
    }
    cout << ret << endl;
    return 0;
}