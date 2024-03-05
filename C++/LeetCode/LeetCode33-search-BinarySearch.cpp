#include<iostream>
using namespace std;
#include<vector>

// 二分查找，把数组分为两个区间，两个区间中一定有一个区间有序，通过有序区间判断数字是否在该区间内，在就在该有序区间内查找，不在就在无序区间内查找
// 重点是从二分后的区间内选一个区间
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int binarySearch(vector<int> nums, int target,int left, int right, int size)
{   
    int mid = (left + right) / 2;
    
    if(nums[mid] == target) return mid;
    if(nums[left] == target) return left;
    if(nums[right] == target) return right;
    if(left == right) return -1;

    // 左半边有序
    if(nums[left] < nums[mid])
    {
        if(target < nums[mid] && target >= nums[left])
            return binarySearch(nums, target, left, mid, size);
        else
            return binarySearch(nums, target, mid + 1, right, size);
    }
    // 右半边有序
    else
    {
        if(target > nums[mid] && target <= nums[right])
            return binarySearch(nums, target, mid + 1, right, size);
        else
            return binarySearch(nums, target, left, mid, size);
    }
}

int main()
{
    vector<int> nums{3,1};
    int target = 1;
    cout << binarySearch(nums, target, 0, nums.size() - 1, nums.size())<< endl;;
    system("pause");
    return 0;                                                 
}



