//
// Created by ousun on 2025/5/1.
// 根据身高重建队列：https://www.programmercarl.com/0406.%E6%A0%B9%E6%8D%AE%E8%BA%AB%E9%AB%98%E9%87%8D%E5%BB%BA%E9%98%9F%E5%88%97.html
// 根据身高重建队列：https://leetcode.cn/problems/queue-reconstruction-by-height/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

static bool cmp(const vector<int>& a, const vector<int>& b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[0] < b[0];
}

// 先排序，再一个一个插入结果中
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> ret;
    for (int i = 0; i < people.size(); ++i) {
        // 由于这里身高是从小到大排的，新插入的要优先放到后面
        // 如果身高是从大到小排的，新插入的就可以优先放到前面
        int cnt = 0;
        auto it = ret.begin();
        while (it != ret.end()) {
            if ((*it)[0] >= people[i][0]) cnt++;
            if (cnt > people[i][1]) {
                ret.insert(it, people[i]);
                break;
            }
            it++;
        }
        if (it == ret.end()) ret.insert(it, people[i]);
    }
    return ret;
}

int main() {
    vector<int> v1{7,0};
    vector<int> v2{4,4};
    vector<int> v3{7,1};
    vector<int> v4{5,0};
    vector<int> v5{6,1};
    vector<int> v6{5,2};
    vector<vector<int>> people{v1, v2, v3, v4, v5, v6};
    reconstructQueue(people);
    return 0;
}