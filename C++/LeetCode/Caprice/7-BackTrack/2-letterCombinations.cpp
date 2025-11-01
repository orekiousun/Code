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

static const unordered_map<char, string> phoneMap{
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
};

void backtrack(vector<string> &ret, string &str, string &digits, int startIdx) {
    if (startIdx >= digits.size()) {
        ret.push_back(str);
        return;
    }

    string phoneStr = phoneMap.at(digits[startIdx]);
    for (int i = 0; i < phoneStr.size(); ++i) {
        str[startIdx] = phoneStr[i];
        backtrack(ret, str, digits, startIdx + 1);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ret;
    if (digits.size() == 0) return ret;
    string str(digits.size(), ' ');
    backtrack(ret, str, digits, 0);
    return ret;
}

int main() {
    letterCombinations("23");
    return 0;
}