//
// Created by ousun on 2024/11/16.
// 移除元素：https://www.programmercarl.com/0027.%E7%A7%BB%E9%99%A4%E5%85%83%E7%B4%A0.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 删除有序数组中的重复项：https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
// 移动零：https://leetcode.cn/problems/move-zeroes/
//

#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/
// 考虑无需数据的情况
int removeDuplicates(vector<int>& nums) {
    int slow = 0;
    unordered_map<int, bool> map;
    for (int fast = 0; fast < nums.size(); ++fast) {
        if (map[nums[fast]] == false) {
            nums[slow++] = nums[fast];
            map[nums[fast]] = true;
        }
    }

    return slow;
}

// https://leetcode.cn/problems/move-zeroes/
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
        if (nums[fast] != 0) {
            nums[slow++] = nums[fast];
        }
    }

    while (slow < nums.size()) {
        nums[slow++] = 0;
    }
}

int main() {
    vector<int> nums{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
    return 0;
}