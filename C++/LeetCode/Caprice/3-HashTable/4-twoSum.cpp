//
// Created by cd_ouymh on 2025/1/2.
// 两数之和：https://www.programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 两数之和：https://leetcode.cn/problems/two-sum/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        int num = nums[i];
        if (map.count(target - num) > 0)
            return vector<int>{i, map[target - num]};
        map[num] = i;
    }

    return vector<int>{};
}

int main() {
    return 0;
}