#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<queue>

/*
    题目一：
        给定一个数组 nums 和滑动窗口的大小 k，请找出所有滑动窗口里的最大值。
        例如：nums = [1,3,-1,-3,5,3,6,7], 和 k = 3   输出：[3,3,5,5,6,7] 

    方法：
        单调递减（不递增）双端队列
            1.如果新加入的数 <= 队尾，就把这个数直接添加到队尾
            2.如果新加入的数 > 队尾，就一直把队尾的数弹出，直到新加入的数 <= 队尾

    题目二：
        请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
        若队列为空，pop_front 和 max_value 需要返回 -1
*/

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res(nums.size() - k + 1);
    deque<int> q;
    for(int i = 0; i < k - 1; i ++) {
        if(q.empty()) q.push_back(nums[i]);
        else if(nums[i] <= q.back()) q.push_back(nums[i]);
        else {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
        }
    }
    for (int i = k - 1; i < nums.size(); i++) {
        if(q.empty()) q.push_back(nums[i]);
        else if(nums[i] <= q.back()) q.push_back(nums[i]);
        else {
            while(!q.empty() && nums[i] > q.back()) q.pop_back();
            q.push_back(nums[i]);
        }
        res[i - k + 1] = q.front();
        if(nums[i - k + 1] == q.front()) q.pop_front();
    }
    return res;
}

class MaxQueue {
public:
    deque<int> deque;
    queue<int> queue;
    MaxQueue() {

    }
    
    int max_value() {
        if(queue.empty()) return -1;
        return deque.front();
    }
    
    void push_back(int value) {
        queue.push(value);
        if(deque.empty()) deque.push_back(value);
        else if(value <= deque.back()) deque.push_back(value);
        else {
            while (!deque.empty() && value > deque.back()) deque.pop_back();
            deque.push_back(value);
        }
    }
    
    int pop_front() {
        if(queue.empty()) return -1;
        int value = queue.front();
        if(value == deque.front()) deque.pop_front();
        queue.pop();
        return value;
    }
};

int main(int argc, char const *argv[]) {
    MaxQueue* maxQueue = new MaxQueue();
    maxQueue->push_back(1);
    cout << maxQueue->pop_front() << endl;
    maxQueue->push_back(3);
    maxQueue->push_back(-1);
    cout << maxQueue->max_value() << endl;
    maxQueue->push_back(-3);
    maxQueue->push_back(5);
    maxQueue->push_back(3);
    cout << maxQueue->max_value() << endl;
    maxQueue->push_back(6);
    maxQueue->push_back(7);
    return 0;
}
