//
// Created by ousun on 2025/5/1.
// 跳跃游戏：https://www.programmercarl.com/0055.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8F.html
// 跳跃游戏：https://leetcode.cn/problems/jump-game/
// 跳跃游戏II：https://www.programmercarl.com/0045.%E8%B7%B3%E8%B7%83%E6%B8%B8%E6%88%8FII.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// 跳跃游戏II：https://leetcode.cn/problems/jump-game-ii/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

// 跳跃游戏：https://leetcode.cn/problems/jump-game/
// 贪心策略：从前向后遍历，走到最远的位置，知道可以抵达结果
// 性能更好的方法
bool canJump(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    while (1) {
        int maxIdx = i + nums[i];
        int i_ = i;
        if (maxIdx >= len - 1) return true;
        for (int j = i + 1; j <= i + nums[i]; j++) {
            int reachIdx = j + nums[j];
            if (reachIdx >= maxIdx) {
                maxIdx = reachIdx;
                i_ = j;
            }
        }
        // i 没有更新，表示最终无法往前进一步，返回false
        if (i == i_) return false;
        i = i_;
    }
    return true;
}

// 跳跃游戏：https://leetcode.cn/problems/jump-game/
// 更适合理解的方法：更新覆盖范围
// 存在重复遍历，性能会差一点
bool canJump2(vector<int>& nums) {
    int cover = 0;
    for (int i = 0; i <= cover; ++i) {
        cover = max(cover, i + nums[i]);
        if (cover >= nums.size() - 1) return true;
    }
    return false;
}

// 跳跃游戏II：https://leetcode.cn/problems/jump-game-ii/description/
// 计算最小跳跃步数，每次往最远了跳即可
int jump(vector<int>& nums) {
    if (nums.size() == 1) return 0;
    int len = nums.size();
    int i = 0;
    int ret = 0;
    while (1) {
        int maxIdx = i + nums[i];
        int i_ = i;
        if (maxIdx >= len - 1) return ret + 1;
        for (int j = i + 1; j <= i + nums[i]; j++) {
            int reachIdx = j + nums[j];
            if (reachIdx >= maxIdx) {
                maxIdx = reachIdx;
                i_ = j;
            }
        }
        // i 没有更新，表示最终无法往前进一步，返回-1
        if (i == i_) return -1;
        else ret++;
        i = i_;
    }
    return ret;
}

int main() {
    vector<int> nums{2,3,1,1,4};
    cout << canJump(nums) << endl;
    return 0;
}
