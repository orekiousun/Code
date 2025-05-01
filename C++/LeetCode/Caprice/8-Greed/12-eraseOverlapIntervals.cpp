//
// Created by ousun on 2025/5/1.
// 无重叠区间：https://www.programmercarl.com/0435.%E6%97%A0%E9%87%8D%E5%8F%A0%E5%8C%BA%E9%97%B4.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 无重叠区间：https://leetcode.cn/problems/non-overlapping-intervals/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] < b[1];
}

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int ret = 0;
    int beginPos = intervals[0][0], endPos = intervals[0][1];
    // 一直贪心的收缩范围
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= endPos) {
            // 刷新区间
            beginPos = intervals[i][0], endPos = intervals[i][1];
        }
        else {
            // 需要移除区间，谁的endPos更小就移除哪一个
            ret++;
            endPos = min(endPos, intervals[i][1]);
        }
    }

    return ret;
}

int main() {
    return 0;
}