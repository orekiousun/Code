//
// Created by ousun on 2025/09/30.
// 同构字符串：https://www.programmercarl.com/0205.%E5%90%8C%E6%9E%84%E5%AD%97%E7%AC%A6%E4%B8%B2.html
// 同构字符串：https://leetcode.cn/problems/isomorphic-strings/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

bool isIsomorphic(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char, char> map;
    for (int i = 0; i < s.size(); ++i) {
        auto sChar = s[i];
        auto tChar = t[i];   
        if (map.count(sChar) == 0) {
            // 检查一下是否有别的字符映射到tChar
            for (auto item: map) {
                if (item.second == tChar)
                    return false;
            }
            map[sChar] = tChar;
        }
        else if (map[sChar] != tChar) 
            return false;
    }
    return true;
}

int main() {
    // "badc" "baba"
    cout << isIsomorphic("foo", "bar") << endl;
    return 0;
}