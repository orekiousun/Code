#include<iostream>
using namespace std;
#include<vector>
#include<stack>

/*
    输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
    假设压入栈的所有数字均不相等。
    例如，序列 {1,2,3,4,5} 是某栈的压栈序列，序列 {4,5,3,2,1} 是该压栈序列对应的一个弹出序列，但 {4,3,5,1,2} 就不可能是该压栈序列的弹出序列。

    模拟入栈出栈即可
*/

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int i = 0, j = 0, size = pushed.size();
    if (size == 0) return true;
    stack<int> s;
    s.push(pushed[i++]);
    while (1) {
        if (!s.empty() && popped[j] == s.top()) {
            s.pop();
            j++;
            if (j == size) break;
        }
        else {
            if (i == size) break;
            s.push(pushed[i++]);
        }
    }
    if (i == size && j == size) return true;
    return false;
}

int main(int argc, char const *argv[]) {
    vector<int> pushed{1, 2, 3, 4, 5};
    vector<int> popped{4, 3, 5, 1, 2};
    cout << validateStackSequences(pushed, popped);
    return 0;
}

