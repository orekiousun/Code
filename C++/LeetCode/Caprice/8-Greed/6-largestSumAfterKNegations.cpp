//
// Created by ousun on 2025/5/1.
// K次取反后最大化的数组和：https://www.programmercarl.com/1005.K%E6%AC%A1%E5%8F%96%E5%8F%8D%E5%90%8E%E6%9C%80%E5%A4%A7%E5%8C%96%E7%9A%84%E6%95%B0%E7%BB%84%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE
// K次取反后最大化的数组和：https://leetcode.cn/problems/maximize-sum-of-array-after-k-negations/description/
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int cnt = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < 0) cnt += 1;
    }

    // 重新转换k值
    if (k > cnt) {
        if ((k - cnt) % 2 == 0) k = cnt;
        else {
            // 选择绝对值最小的那个数字改变符号
            if (cnt == 0) k = cnt + 1;
            else if(cnt == nums.size()) k = cnt - 1;
            else k = abs(nums[cnt]) < abs(nums[cnt - 1]) ? cnt + 1 : cnt - 1;
        }
    }

    int add = 0;
    for (int i = 0; i < nums.size(); ++i) {
        add += k > 0 ? -nums[i] : nums[i];
        k--;
    }
    return add;
}

int main() {
    return 0;
}