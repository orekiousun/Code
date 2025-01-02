//
// Created by cd_ouymh on 2025/1/2.
// 赎金信：https://www.programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html#%E6%80%9D%E8%B7%AF
// 赎金信：https://leetcode.cn/problems/ransom-note/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> map;
    for (auto v : magazine) {
        map[v]++;
    }

    for (auto v : ransomNote) {
        map[v]--;
        if (map[v] < 0) return false;
    }

    return true;
}

int main() {

}