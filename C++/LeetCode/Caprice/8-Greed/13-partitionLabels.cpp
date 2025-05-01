//
// Created by ousun on 2025/5/1.
// 划分字母区间：https://www.programmercarl.com/0763.%E5%88%92%E5%88%86%E5%AD%97%E6%AF%8D%E5%8C%BA%E9%97%B4.html
// 划分字母区间：https://leetcode.cn/problems/partition-labels/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

vector<int> partitionLabels(string s) {
    unordered_map<char, int> record;
    // 先遍历一遍，记录每个字母最后的位置
    for (int i = 0; i < s.size(); ++i) {
        record[s[i]] = i;
    }

    vector<int> ret;
    int idx = 0;
    while (idx < s.size()) {
        int endPos = record[s[idx]];
        for (int i = idx; i <= endPos; ++i) {
            endPos = max(endPos, record[s[i]]);
        }
        ret.push_back(endPos - idx + 1);
        idx = endPos + 1;
    }

    return ret;
}

int main() {
    return 0;
}