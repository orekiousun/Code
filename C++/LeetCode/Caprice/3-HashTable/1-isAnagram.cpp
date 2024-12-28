//
// Created by ousun on 2024/12/28.
// 有效的字母异位词：https://www.programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 有效的字母异味词：https://leetcode.cn/problems/valid-anagram/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

bool isAnagram(string s, string t) {
    unordered_map<char, int> sMap;
    for(auto c : s) {
        sMap[c] ++;
    }
    for (auto c : t) {
        sMap[c] --;
        if (sMap[c] < 0)
            return false;
    }
    for (auto i: sMap) {
        if (sMap[i.first] != 0)
            return false;
    }

    return true;
}

int main() {
    cout << isAnagram("a", "ab") << endl;
    return 0;
}
