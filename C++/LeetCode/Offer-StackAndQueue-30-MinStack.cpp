#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。

    方法：
        法1：利用一个辅助数组，记录从0到i的最小值
        法2优化：利用一个辅助单调栈，单调不递增（注意可以相等，避免出现前面有多个相同的最小值，一次pop后辅助栈为空的情况），当弹出栈顶的元素=辅助栈栈顶元素时，弹出辅助栈栈顶元素
*/

class MinStack {
public:
    vector<int> stack;
    vector<int> minNum;
    MinStack() {

    }
    
    void push(int x) {
        stack.push_back(x);
        if(minNum.empty())
            minNum.push_back(x);
        else if(x <= minNum[minNum.size() - 1])  // 这里新增一个=，代表单调不递减
            minNum.push_back(x);
    }
    
    void pop() {
        if(stack[stack.size() - 1] == minNum[minNum.size() - 1])
            minNum.pop_back();
        stack.pop_back();
    }
    
    int top() {
        return stack[stack.size() - 1];
    }
    
    int min() {
        return minNum[minNum.size() - 1];
    }
};

int main(int argc, char const *argv[]) {
    
    return 0;
}
