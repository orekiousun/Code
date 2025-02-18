//
// Created by cd_ouymh on 2025/2/18.
// 滑动窗口最大值：https://www.programmercarl.com/0239.%E6%BB%91%E5%8A%A8%E7%AA%97%E5%8F%A3%E6%9C%80%E5%A4%A7%E5%80%BC.html
// 滑动窗口最大值：https://leetcode.cn/problems/sliding-window-maximum/
//

#include <iostream>
using namespace std;
#include <vector>
#include <deque>

// ！！！双向递减队列
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;
    vector<int> ret(nums.size() - k + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
        if (q.empty()) q.push_back(i);
        else {
            while (!q.empty() && q.front() < i - k + 1) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
        }
        if (i >= k - 1) ret[i - k + 1] = nums[q.front()];
    }
    return ret;
}

int main() {
    vector<int> nums{1,3,-1,-3,5,3,6,7};
    maxSlidingWindow(nums, 3);
    return 0;
}
