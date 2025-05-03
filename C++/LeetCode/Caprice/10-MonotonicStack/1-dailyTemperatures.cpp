//
// Created by ousun on 2025/5/3.
// 每日温度：https://www.programmercarl.com/0739.%E6%AF%8F%E6%97%A5%E6%B8%A9%E5%BA%A6.html
// 每日温度：https://leetcode.cn/problems/daily-temperatures/
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

vector<int> dailyTemperatures(vector<int>& temperatures) {
    // 从后往前遍历，维护一个单调递减的栈
    stack<int> s;
    vector<int> ret(temperatures.size(), 0);
    for (int i = temperatures.size() - 1; i >= 0; --i) {
        while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
            s.pop();
        }
        if (s.empty()) ret[i] = 0;
        else ret[i] = s.top() - i;
        s.push(i);
    }
    return ret;
}

int main() {
    vector<int> temperatures{73,74,75,71,69,72,76,73};
    dailyTemperatures(temperatures);
    return 0;
}
