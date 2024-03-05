#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<string>
#include<algorithm>

/*
    dp[i]记录了以i为结尾的最长有效括号的长度
*/
int longestValidParentheses(string s) {
    int size = s.size(), maxElement = 0;
    if(size <= 1) return 0;
    int dp[size];
    stack<int> stack;
    if(s[0] == '(') stack.push(0);
    dp[0] = 0;
    for (int i = 1; i < size; i++) {
        if(s[i] == '(') {
            stack.push(i);
            dp[i] = 0;
        }
        else {
            if(!stack.empty()) {
                if(stack.top() == 0)
                    dp[i] = dp[i - 1] + 2;
                else
                    dp[i] = dp[stack.top() - 1] + dp[i - 1] + 2;
                stack.pop();
            }
            else {
                dp[i] = 0;
            }
        }
        maxElement = max(maxElement, dp[i]);
    }
    return maxElement;
}

int main() {
    string s = "(()())";
    cout << longestValidParentheses(s) << endl;
    system("pause");
    return 0;
}