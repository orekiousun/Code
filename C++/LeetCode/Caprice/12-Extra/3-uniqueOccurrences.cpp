//
// Created by ousun on 2025/08/29.
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