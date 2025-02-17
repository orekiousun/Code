//
// Created by cd_ouymh on 2025/2/17.
// 逆波兰表达式求值：https://www.programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html
// 逆波兰表达式求值：https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

bool isSymbol(string& symbol) {
    return symbol == "+" || symbol == "-" || symbol == "*" || symbol == "/";
}

int calculate(int a, int b, string& symbol) {
    if (symbol == "+") return a + b;
    if (symbol == "-") return a - b;
    if (symbol == "*") return a * b;
    if (symbol == "/") return a / b;
}

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (auto str : tokens) {
        if (not isSymbol(str)) {
            s.push(stoi(str));
        }
        else {
            int num1, num2;
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            s.push(calculate(num1, num2, str));
        }
    }

    return s.top();
}

int main() {
    vector<string> tokens{"2","1","+","3","*"};
    cout << evalRPN(tokens) << endl;
    return 0;
}