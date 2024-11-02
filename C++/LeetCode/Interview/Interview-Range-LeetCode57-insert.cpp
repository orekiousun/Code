//
// Created by cd_ouymh on 2024/10/1.
// https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 返回的索引idx满足 intervals[idx][intervalIdx] <= number <= intervals[idx + 1][intervalIdx]
int binaryFind(vector<vector<int>>& intervals, int number, int intervalIdx, int left, int right) {
    if (left >= right)
        return right;
    int mid = (left + right) / 2;
    if (number <= intervals[mid][intervalIdx])
        return binaryFind(intervals, number, intervalIdx, left, mid);
    else
        return binaryFind(intervals, number, intervalIdx, mid + 1, right);
}

// 1.先二分查找newInterval[1]和newInterval[2]应该放到的位置
// 2.将两个位置之间的区间全部剔除（可以合并）
// 3.再检测前后的区间是否还可以合并
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int left = newInterval[0];
    int right = newInterval[1];
    bool placed = false;
    vector<vector<int>> ans;
    for (auto interval : intervals) {
        if (interval[0] > right) {
            // 在插入区间的右侧且无交集
            if (!placed) {
                ans.push_back({left, right});
                placed = true;
            }
            ans.push_back(interval);
        }
        else if (interval[1] < left){
            // 在插入区间的左侧且无交集，直接添加
            ans.push_back(interval);
        }
        else {
            // 在插入区间之间，合并区间
            left = min(left, interval[0]);
            right = max(right, interval[1]);
        }
    }
    if (!placed) {
        ans.push_back({left, right});
    }
    return ans;
}

int main() {
    vector<int> l1{1, 2};
    vector<int> l2{3, 5};
    vector<int> l3{6, 7};
    vector<int> l4{8, 10};
    vector<int> l5{12, 16};
    vector<vector<int>> intervals{l1, l2, l3, l4, l5};
    vector<int> newInterval{4, 8};
    insert(intervals, newInterval);
    return 0;
}
