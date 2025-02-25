//
// Created by ousun on 2025/2/21.
// 前K个高频元素：https://www.programmercarl.com/0347.%E5%89%8DK%E4%B8%AA%E9%AB%98%E9%A2%91%E5%85%83%E7%B4%A0.html
// 前K个高频元素：https://leetcode.cn/problems/top-k-frequent-elements/
// 优先队列(堆)
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

// 自定义比较类，默认为大顶堆，即返回值为true时，即a<b时，为大顶堆
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    // 先遍历一遍，把所有数字出现的次数记录下来
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] ++;
    }

    // 插入大顶堆中
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pQueue(map.begin(), map.end());
    vector<int> ret(k, 0);
    while (k--) {
        auto v = pQueue.top();
        pQueue.pop();
        ret[k] = v.first;
    }
    return ret;
}

int main() {
    vector<int> nums{1,1,1,2,2,3};
    topKFrequent(nums, 2);
    return 0;
}