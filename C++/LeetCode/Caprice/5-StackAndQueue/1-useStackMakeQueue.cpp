//
// Created by cd_ouymh on 2025/2/10.
// 用栈实现队列：https://www.programmercarl.com/0232.%E7%94%A8%E6%A0%88%E5%AE%9E%E7%8E%B0%E9%98%9F%E5%88%97.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 用栈实现队列：https://leetcode.cn/problems/implement-queue-using-stacks/description/
//

#include <iostream>
using namespace std;
#include <stack>

class MyQueue {
private:
    stack<int> _s1;
    stack<int> _s2;
public:
    MyQueue() {

    }

    void push(int x) {
        _s1.push(x);
    }

    int pop() {
        if (!_s2.empty()) {
            int top = _s2.top();
            _s2.pop();
            return top;
        }
        else {
            while (!_s1.empty()) {
                _s2.push(_s1.top());
                _s1.pop();
            }
            int top = _s2.top();
            _s2.pop();
            return top;
        }
    }

    int peek() {
        if (!_s2.empty()) {
            return _s2.top();
        }
        else {
            while (!_s1.empty()) {
                _s2.push(_s1.top());
                _s1.pop();
            }
            return _s2.top();
        }
    }

    bool empty() {
        return _s1.empty() && _s2.empty();
    }
};

int main() {
    MyQueue* q = new MyQueue();
    q->push(1);
    q->push(2);
    cout << q->peek() << endl;
    cout << q->pop() << endl;
    cout << q->peek() << endl;
    return 0;
}


