//
// Created by cd_ouymh on 2025/2/17.
// 逆波兰表达式求值：https://www.programmercarl.com/0150.%E9%80%86%E6%B3%A2%E5%85%B0%E8%A1%A8%E8%BE%BE%E5%BC%8F%E6%B1%82%E5%80%BC.html
// 逆波兰表达式求值：https://leetcode.cn/problems/evaluate-reverse-polish-notation/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

/*
给你一个字符串数组 tokens ，表示一个根据 逆波兰表示法 表示的算术表达式。
请你计算该表达式。返回一个表示表达式值的整数。
注意：

有效的算符为 '+'、'-'、'*' 和 '/' 。
每个操作数（运算对象）都可以是一个整数或者另一个表达式。
两个整数之间的除法总是 向零截断 。
表达式中不含除零运算。
输入是一个根据逆波兰表示法表示的算术表达式。
答案及所有中间计算结果可以用 32 位 整数表示。

输入：tokens = ["2","1","+","3","*"]
输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9
 */

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