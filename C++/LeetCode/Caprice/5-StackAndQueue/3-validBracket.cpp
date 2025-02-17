//
// Created by cd_ouymh on 2025/2/13.
// 有效的括号：https://www.programmercarl.com/0020.%E6%9C%89%E6%95%88%E7%9A%84%E6%8B%AC%E5%8F%B7.html
// 有效的括号：https://leetcode.cn/problems/valid-parentheses/description/
//

#include <iostream>
using namespace std;
#include <stack>
#include <string>

// 栈实现，比较简单，不再赘述
bool isValid(string str) {
    stack<char> s;
    for(auto c : str) {
        if (s.empty()) {
            s.push(c);
            continue;
        }
        char top = s.top();
        if ((c == ']' && top == '[') ||
            (c == '}' && top == '{') ||
            (c == ')' && top == '(')) {
            s.pop();
        }
        else {
            s.push(c);
        }
    }

    return s.empty();
}

int main() {
    string str = "([([]){}([]{})]))";
    cout << isValid(str) << endl;
    return 0;
}