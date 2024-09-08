//
// Created by ousun on 2024/9/8.
// https://leetcode.cn/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>

string reverseWords(string s) {
    string ret;
    int i = s.size() - 1;
    while(i >= 0) {
        if (s[i] == ' ') {
            i--;
            continue;
        }
        int left = i;
        while (left >= 0 && s[left] != ' ') {
            left--;
        }
        for (int j = left + 1; j <= i; j++) {
            ret.push_back(s[j]);
        }
        ret.push_back(' ');
        i = left - 1;
    }

    // 移除多余的空格
    i = ret.size() - 1;
    while (ret[i] == ' '){
        ret.erase(i--, 1);
    }

    return ret;
}

int main() {
    cout << reverseWords("  hello world  ") << endl;
    return 0;
}