//
// Created by ousun on 2025/08/29.
// 独一无二的出现次数：https://www.programmercarl.com/1207.%E7%8B%AC%E4%B8%80%E6%97%A0%E4%BA%8C%E7%9A%84%E5%87%BA%E7%8E%B0%E6%AC%A1%E6%95%B0.html
// 独一无二的出现次数：https://leetcode.cn/problems/unique-number-of-occurrences/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int, int> map;
    for (auto num: arr) {
        if (map.count(num) == 0)
            map[num] = 0;
        map[num]++;
    }
    unordered_set<int> set;
    for (auto item: map) {
        if (set.count(item.second) == 0)
            set.insert(item.second);
        else
            return false;
    }
    return true;
}

int main() {

    return 0;
}