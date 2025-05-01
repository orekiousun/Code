//
// Created by ousun on 2025/5/1.
// 合并区间：https://www.programmercarl.com/0056.%E5%90%88%E5%B9%B6%E5%8C%BA%E9%97%B4.html
// 合并区间：https://leetcode.cn/problems/merge-intervals/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    vector<vector<int>> ret;
    int beginPos = intervals[0][0], endPos = intervals[0][1];
    // 一直贪心的收缩范围
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] > endPos) {
            // 界外
            ret.push_back({beginPos, endPos});
            beginPos = intervals[i][0], endPos = intervals[i][1];
        }
        else {
            // 界内
            endPos = max(endPos, intervals[i][1]);
        }
    }
    ret.push_back({beginPos, endPos});

    return ret;

}

int main() {
    return 0;
}