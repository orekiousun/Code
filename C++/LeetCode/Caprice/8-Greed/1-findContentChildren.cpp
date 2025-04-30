//
// Created by cd_ouymh on 2025/4/30.
// 分发饼干：https://www.programmercarl.com/0455.%E5%88%86%E5%8F%91%E9%A5%BC%E5%B9%B2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 分发饼干：https://leetcode.cn/problems/assign-cookies/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <unordered_map>

int findContentChildren(vector<int>& g, vector<int>& s) {
    // 贪心策略：优先满足胃口小的
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int sIdx = 0, ret = 0;
    for (int gIdx = 0; gIdx < g.size(); ++gIdx) {
        // 找到第一个满足的饼干，分配
        while (sIdx < s.size() && g[gIdx] > s[sIdx]) {
            sIdx++;
        }
        if (sIdx < s.size() && g[gIdx] <= s[sIdx]) {
            ret++;
            sIdx++;
        }
    }
    return ret;
}

int main() {
    vector<int> g{1, 2};
    vector<int> s{1, 2, 3};
    cout << findContentChildren(g, s) << endl;
    return 0;
}
