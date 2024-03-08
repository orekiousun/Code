#include<iostream>
using namespace std;
#include<stack>

/*
    用两个栈实现队列：
    加入队尾 appendTail()函数： 将数字 val 加入栈 A 即可。
    删除队首deleteHead()函数： 有以下三种情况。
        ·当栈 B 不为空： B中仍有已完成倒序的元素，因此直接返回 B 的栈顶元素
        ·否则，当 A 为空： 即两个栈都为空，无元素，因此返回 −1
        ·否则： 将栈 A 元素全部转移至栈 B 中，实现元素倒序，并返回栈 B 的栈顶元素
*/

class CQueue {
private:
    stack<int> sIn, sOut;

public:
    CQueue() {

    }

    void appendTail(int value) {
        sIn.push(value);
    }

    int deleteHead() {
        int ans;
        if(!sOut.empty()) {
            ans = sOut.top();
            sOut.pop();
        }
        else if(sIn.empty()) ans = -1;
        else {
            while (!sIn.empty()) {
                sOut.push(sIn.top());
                sIn.pop();
            }
            ans = sOut.top();
            sOut.pop();
        }
        return ans;
    }
};