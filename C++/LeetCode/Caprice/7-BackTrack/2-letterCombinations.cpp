//
// Created by cd_ouymh on 2025/4/1.
// 电话号码的字母组合：https://www.programmercarl.com/0017.%E7%94%B5%E8%AF%9D%E5%8F%B7%E7%A0%81%E7%9A%84%E5%AD%97%E6%AF%8D%E7%BB%84%E5%90%88.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 电话号码的字母组合：https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_map>

void backtrack(vector<string>& ret, string& str, string& digits, int startIdx, unordered_map<char, vector<char>>& map) {
    if (startIdx >= digits.size()) {
        ret.push_back(str);
        return;
    }

    vector<char> charL = map[digits[startIdx]];
    for (int i = 0; i < charL.size(); ++i) {
        str[startIdx] = charL[i];
        backtrack(ret, str, digits, startIdx + 1, map);
    }
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, vector<char>> map;
    map['2'] = vector<char>{'a', 'b', 'c'};
    map['3'] = vector<char>{'d', 'e', 'f'};
    map['4'] = vector<char>{'g', 'h', 'i'};
    map['5'] = vector<char>{'j', 'k', 'l'};
    map['6'] = vector<char>{'m', 'n', 'o'};
    map['7'] = vector<char>{'p', 'q', 'r', 's'};
    map['8'] = vector<char>{'t', 'u', 'v'};
    map['9'] = vector<char>{'w', 'x', 'y', 'z'};
    vector<string> ret;
    if (digits.size() == 0) return ret;
    string str(digits.size(), ' ');
    backtrack(ret, str, digits, 0, map);
    return ret;
}

int main() {

    return 0;
}