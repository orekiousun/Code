//
// Created by ousun on 2024/11/16.
// https://leetcode.cn/problems/remove-duplicates-from-sorted-array/description/
// https://leetcode.cn/problems/move-zeroes/
// 移除元素
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