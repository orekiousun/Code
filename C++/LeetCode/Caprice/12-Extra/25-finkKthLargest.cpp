//
// Created by ousun on 2025/11/2.
// 数组中第k个最大元素：https://leetcode.cn/problems/kth-largest-element-in-an-array/description/
//

#include <iostream>
using namespace std;
#include <vector>

// 分治，类似快排的思想，根据大小分为不同的数组
int findKthLargest(vector<int>& nums, int k) {
    int pivot = nums[rand() % nums.size()];
    vector<int> big, equal, small;
    for (auto num: nums) {
        if (num > pivot)
            big.push_back(num);
        else if(num < pivot)
            small.push_back(num);
        else
            equal.push_back(num);
    }
    // 分情况讨论第k大的元素在big、small还是equal中
    // 第k大的元素在big中
    if (big.size() >= k)
        return findKthLargest(big, k);
    // 第k大的元素在small中
    int equalBigSize = equal.size() + big.size();
    if(equalBigSize < k)
        return findKthLargest(small, k - equalBigSize);
    return pivot;
}

void fastSort(vector<int>& nums, int begin, int end) {
    if (begin >= end) return;
    int pivot = nums[begin];
    int i = begin, j = end;
    while(i != j) {
        while (i < j && nums[j] >= pivot)
            j--;
        while (i < j && nums[i] <= pivot)
            i++;
        // 交换i，j
        if (i < j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
    nums[begin] = nums[i];
    nums[i] = pivot;
    fastSort(nums, begin, i - 1);
    fastSort(nums, i + 1, end);
}

int main() {
    vector<int> nums{1,2,6,2,6,1,5,2,5,1};
    fastSort(nums, 0, nums.size() - 1);
    return 0;
}
