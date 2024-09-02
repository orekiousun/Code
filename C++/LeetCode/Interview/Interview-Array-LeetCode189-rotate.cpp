#include<iostream>
using  namespace std;
#include<vector>

/*
    给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数。
    输入: nums = [1,2,3,4,5,6,7], k = 3
    输出: [5,6,7,1,2,3,4]
    思路：就是将后面 k 个移动到前面 k 个地方来，关键点在于如何权衡空间和时间复杂度
    方法：先将整个数组翻转，再分别翻转前 k 个和后 k 个元素，注意 k 可能 >size，取模之后再使用
*/

void reverse(vector<int>& nums, int l, int r) {
    while (l < r) {
        swap(nums[l++], nums[r--]);
    }
}

void rotate(vector<int>& nums, int k) {
    int len = nums.size();
    k %= len;
    reverse(nums, 0, len - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, len - 1);
}

int main() {
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 3);
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it ++) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
