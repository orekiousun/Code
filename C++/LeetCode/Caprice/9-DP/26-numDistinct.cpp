//
// Created by ousun on 2025/08/09.
// 不同的子序列：https://www.programmercarl.com/0115.%E4%B8%8D%E5%90%8C%E7%9A%84%E5%AD%90%E5%BA%8F%E5%88%97.html
// 不同的子序列：https://leetcode.cn/problems/distinct-subsequences/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

// 给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
// 算法正确了，但是中间结果会超出long long范围，比如aaaaaaaaaaaaaaaaaaa..匹配aaa就可能有很多一个数字很大的结果
// i可以保证是一直大于等于j的，不需要i<j的结果
int numDistinct(string s, string t) {
    int sSize = s.size(), tSize = t.size();
    vector<vector<int>> dp(sSize + 1, vector<int>(tSize + 1, 0));
    for (int i = 0; i <= sSize; ++i) 
        dp[i][0] = 1;
    for (int i = 1; i <= sSize; ++i) {
        for (int j = 1; j <= tSize; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[sSize][tSize];
}

// 匹配dp[i][j]需要dp[i-1][j]和dp[i-1][j-1]，可以进行适当的剪枝操作
// 需要避免i很大，j很小的情况
int numDistinctFix(string s, string t) {
    int sSize = s.size(), tSize = t.size();
    vector<vector<long long>> dp(sSize + 1, vector<long long>(tSize + 1, 0));
    for (int i = 0; i <= sSize; ++i) 
        dp[i][0] = 1;
    for (int i = 1; i <= sSize; ++i) {
        int beginIdx = max(1, tSize - (sSize - i));
        for (int j = beginIdx; j <= tSize; ++j) {
            dp[i][j] = dp[i - 1][j];
            if (s[i - 1] == t[j - 1])
                dp[i][j] += dp[i - 1][j - 1];
        }
    }
    return dp[sSize][tSize];
}

// 这个函数可以迭代看运行的过程中使用了哪些索引
void calcUseIdx(int size1, int size2, vector<vector<int>>& rec) {
    if (size1 < 0 || size2 < 0)
        return;
    
    rec[size1][size2] = 1;
    calcUseIdx(size1 - 1, size2, rec);
    calcUseIdx(size1 - 1, size2 - 1, rec);
}

int main() {
    cout << numDistinctFix("babgbag", "bag") << endl;
    vector<vector<int>> dp(7 + 1, vector<int>(3 + 1, 0));
    return 0;
}