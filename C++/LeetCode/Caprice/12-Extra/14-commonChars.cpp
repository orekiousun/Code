//
// Created by ousun on 2025/09/30.
// 查找常用字符：https://www.programmercarl.com/1002.%E6%9F%A5%E6%89%BE%E5%B8%B8%E7%94%A8%E5%AD%97%E7%AC%A6.html
// 查找常用字符：https://leetcode.cn/problems/find-common-characters/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <array>

// 查找在每个字符串中都出现了的字符
vector<string> commonChars(vector<string>& words) {
    int size = words.size();
    unordered_map<char, string> map;
    unordered_map<char, int> cntMap;
    string match = string(size, '1');
    for (int i = 0; i < size; i++) {
        auto word = words[i];
        unordered_map<char, int> tmpCntMap;
        for (auto c: word) {
            if (map.count(c) == 0)
                map[c] = string(size, '0');
            map[c][i] = '1';
            if (tmpCntMap.count(c) == 0)
                tmpCntMap[c] = 0;
            tmpCntMap[c]++;
        }
        for (auto item: tmpCntMap) {
            if (cntMap.count(item.first) == 0)
                cntMap[item.first] = item.second;
            else
                cntMap[item.first] = min(cntMap[item.first], item.second);
        }
    }
    vector<string> ret;
    for (auto item: map) {
        if (item.second == match) {
            while (cntMap[item.first]--)
                ret.emplace_back(1, item.first);
        }
    }
    return ret;
}

// 只遍历所有英文字符
vector<string> commonChars2(vector<string>& words) {
    int size = words.size();
    array<int, 26> cntArr;
    cntArr.fill(0);
    for (char c = 'a'; c <= 'z'; c++) {
        int num = -1;
        for (auto word: words) {
            int cnt = 0;
            for (auto c_ : word) {
                if (c_ == c) cnt++;
            }
            num = num == -1 ? cnt : min(num, cnt);
        }
        
        if (num != -1) cntArr[c - 'a'] = num;
    }

    vector<string> ret;
    for (int i = 0; i < 26; i++) {
        int num = cntArr[i];
        while (num--)
            ret.emplace_back(1, 'a' + i);
    }
    return ret;
}

int main() {
    vector<string> words{"bella","label","roller"};
    commonChars(words);
    return 0;
}