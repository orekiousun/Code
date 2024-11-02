//
// Created by ousun on 2024/11/2.
// https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 思路：维护公共区间
int findMinArrowShots(vector<vector<int>>& points) {
    //  这里可以直接排序，不用写比较函数，会额外消耗时间和内存
//    sort(points.begin(), points.end(),[](vector<int> a, vector<int> b) {
//        if (a[0] == b[0])
//            return a[1] < b[1];
//        return a[0] < b[0];
//    });
    sort(points.begin(), points.end());
    int preRangeRight = INT32_MIN;
    int ret = 1;
    for (int i = 1; i < points.size(); ++i) {
        // 判断当前区间和之前的区间是否可以合并
        if (points[i][0] <= points[i - 1][1]) {
            // 再判断是否可以和前一个已合并的区间合并
            if (preRangeRight == INT32_MIN)
                preRangeRight = min(points[i - 1][1], points[i][1]);
            else {
                if (points[i][0] > preRangeRight) {
                    ret += 1;
                    preRangeRight = INT32_MIN;
                }
                else
                    preRangeRight = min(preRangeRight, points[i][1]);
            }
        }
        else {
            ret += 1;
            preRangeRight = INT32_MIN;
        }
    }

    return ret;
}

int main() {
    vector<int> p1{9, 12};
    vector<int> p2{1, 10};
    vector<int> p3{4, 11};
    vector<int> p4{8, 12};
    vector<int> p5{3, 9};
    vector<int> p6{6, 9};
    vector<int> p7{6, 7};
//    vector<int> p8{3, 9};
//    vector<int> p9{0, 6};
//    vector<int> p10{2, 8};
    vector<vector<int>> points{p1, p2, p3, p4, p5, p6, p7};
    cout << findMinArrowShots(points);
    return 0;
}
