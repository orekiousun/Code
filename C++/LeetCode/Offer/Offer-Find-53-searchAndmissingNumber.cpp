#include<iostream>
using namespace std;
#include<vector>

/*
    题目一：统计一个数字在排序数组中出现的次数。
    方法：
        1.通过二分查找找到这个数，再分别从前和从后遍历统计次数

    题目二：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0～n-1之内。在范围0～n-1内的n个数字中有且只有一个数字不在该数组中，请找出这个数字。
*/

int binarySearch(vector<int>& nums, int left, int right, int target) {
    if(left > right) return -1;
    int mid = (left + right) / 2;
    if(nums[mid] == target) return mid;
    else if(left == right) return -1;
    else if(nums[mid] < target) return binarySearch(nums, mid + 1, right, target);
    else return binarySearch(nums, left, mid, target);
}

int search(vector<int>& nums, int target) {
    int pos = binarySearch(nums, 0, nums.size() - 1, target);
    if(pos == -1) return 0;
    int forward = pos, back = pos;
    while (forward < nums.size() && nums[forward] == target) {
        forward++;
    }
    while (back >= 0 && nums[back] == target) {
        back--;
    }
    return forward - back - 1;
}

int missingNumber(vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
    if(nums[i] != nums[i - 1] + 1)
        return nums[i] - 1;
    }
    return nums[0] == 0 ? nums[nums.size() - 1] + 1 : 0;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{0, 2, 3, 4, 5, 6};
    cout << search(nums, 6) << endl;
    cout << missingNumber(nums) << endl;
    return 0;
}
