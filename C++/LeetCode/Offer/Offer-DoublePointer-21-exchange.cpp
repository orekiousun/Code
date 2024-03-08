#include<iostream>
using namespace std;
#include<vector>

/*
    将数组中所有奇数移到偶数前

    方法：
        双指针，记录奇数尾部和偶数尾部的位置，遍历交换即可
*/

vector<int> exchange(vector<int>& nums) {
    int pre = 0, next = 0;
    for (; next < nums.size(); next++) {
        if (nums[next] % 2 == 1) {
            int temp = nums[pre];
            nums[pre] = nums[next];
            nums[next] = temp;
            pre++;
        }
    }
    return nums;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8};
    exchange(nums);
    return 0;
}

