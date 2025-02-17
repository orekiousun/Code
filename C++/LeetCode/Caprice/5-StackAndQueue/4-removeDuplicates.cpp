//
// Created by ousun on 2025/2/15.
// 删除字符串中的所有相邻重复项：https://www.programmercarl.com/1047.%E5%88%A0%E9%99%A4%E5%AD%97%E7%AC%A6%E4%B8%B2%E4%B8%AD%E7%9A%84%E6%89%80%E6%9C%89%E7%9B%B8%E9%82%BB%E9%87%8D%E5%A4%8D%E9%A1%B9.html
// 删除字符串中的所有相邻重复项：https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>

string removeDuplicates(string str) {
    stack<char> s;
    for (int i = 0; i < str.size(); ++i) {
        if (!s.empty() && str[i] == s.top()) s.pop();
        else s.push(str[i]);
    };
    string ret(s.size(), ' ');
    for (int i = s.size() - 1; i >= 0; --i) {
        ret[i] = s.top();
        s.pop();
    }
    return ret;
}

int main() {
    cout << removeDuplicates("abbaca") << endl;
    return 0;
}