//
// Created by ousun on 2025/10/24.
// Dota2参议院：https://www.programmercarl.com/0649.Dota2%E5%8F%82%E8%AE%AE%E9%99%A2.html#%E6%80%9D%E8%B7%AF
// Dota2参议院：https://leetcode.cn/problems/dota2-senate/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

const unordered_map<char, string> nameMap = {
    {'R', "Radiant"},
    {'D', "Dire"}
};

string predictPartyVictory(string senate) {
    // 贪心策略：找到后面的第一个不等于自己的字符，删除，直到找不到了就返回
    int i = 0;
    while (senate.size() > 1) {
        int size = senate.size();
        int j = (i + 1) % size;
        while (j != i && senate[i] == senate[j]) {
            j = (j + 1) % size;
        }
        if (j == i) {
            return nameMap.at(senate[i]);
        }
        else {
            senate.erase(j, 1);
            i = j > i ? (i + 1) % senate.size() : i % senate.size();
        }
    }
    return nameMap.at(senate[0]);
}

int main() {
    cout << predictPartyVictory("RRDDD") << endl;
    return 0;
}