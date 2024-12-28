//
// Created by ousun on 2024/12/28.
// 两个数组的交集：https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 两个数组的交集：https://leetcode.cn/problems/intersection-of-two-arrays/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // 可以直接通过这种方式通过数组初始化set
    unordered_set<int> set(nums1.begin(), nums1.end());

    unordered_set<int> ret;
    for (auto v : nums2) {
        if (set.count(v) > 0)
            ret.insert(v);
    }

    // 也可以通过这种方式构造数组，迭代器就可这样构造，十分方便
    return vector<int>(ret.begin(), ret.end());
}

int main() {
    return 0;
}
