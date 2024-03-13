#include <iostream>
using namespace std;
#include <vector>
#include <numeric>

/*
    n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
    你需要按照以下要求，给这些孩子分发糖果：
    每个孩子至少分配到 1 个糖果。
    相邻两个孩子评分更高的孩子会获得更多的糖果。
    请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。

    思路：从前往后再从后往前遍历两次
 */

int candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> record(n, 1);
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            record[i] = record[i - 1] + 1;
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1] && record[i] <= record[i + 1]) {
            record[i] = record[i + 1] + 1;
        }
    }

    return accumulate(record.begin(), record.end(), 0);
}

int main() {
    vector<int> ratings{1,3,4,5,2}; // 121123    132123
    cout << candy(ratings) << endl;
    return 0;
}