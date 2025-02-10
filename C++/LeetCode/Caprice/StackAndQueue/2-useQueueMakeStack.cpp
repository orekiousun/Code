//
// Created by cd_ouymh on 2025/2/10.
// 用队列实现栈：https://www.programmercarl.com/0225.%E7%94%A8%E9%98%9F%E5%88%97%E5%AE%9E%E7%8E%B0%E6%A0%88.html#%E4%BC%98%E5%8C%96
// 用队列实现栈：https://leetcode.cn/problems/implement-stack-using-queues/submissions/598256454/
// 注意：用队列实现栈，pop和top的时间复杂度为O(n)
//
#include <iostream>
using namespace std;
#include <queue>

class MyStack {
private:
    queue<int> _q;
public:
    MyStack() {

    }

    void push(int x) {
        _q.push(x);
    }

    int pop() {
        int size = _q.size() - 1;
        while (size--) {
            int front = _q.front();
            _q.pop();
            _q.push(front);
        }
        int front = _q.front();
        _q.pop();
        return front;
    }

    int top() {
        int size = _q.size() - 1;
        while (size--) {
            int front = _q.front();
            _q.pop();
            _q.push(front);
        }
        int front = _q.front();
        _q.pop();
        _q.push(front);
        return front;
    }

    bool empty() {
        return _q.empty();
    }
};

int main() {

    return 0;
}
