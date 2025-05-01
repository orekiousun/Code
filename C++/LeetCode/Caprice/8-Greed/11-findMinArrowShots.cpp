//
// Created by ousun on 2025/5/1.
// 用最少数量的箭引爆气球：https://www.programmercarl.com/0452.%E7%94%A8%E6%9C%80%E5%B0%91%E6%95%B0%E9%87%8F%E7%9A%84%E7%AE%AD%E5%BC%95%E7%88%86%E6%B0%94%E7%90%83.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 用最少数量的箭引爆气球：https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int ret = 1;
    int beginPos = points[0][0], endPos = points[0][1];
    // 一直贪心的收缩范围
    for (int i = 1; i < points.size(); ++i) {
        if (points[i][0] > endPos) {
            // 界外
            ret++;
            beginPos = points[i][0], endPos = points[i][1];
        }
        else {
            // 界内
            beginPos = points[i][0];
            endPos = min(endPos, points[i][1]);
        }
    }

    return ret;
}

int main() {
    return 0;
}
