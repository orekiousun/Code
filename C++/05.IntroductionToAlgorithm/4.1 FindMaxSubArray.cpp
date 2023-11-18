#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    通过分治的算法找到一组数组中最大的子数组和
    分治：分别找到左半数组和右半数组中的最大数组和
    合并：如果最大数组和包括了中间值，从中间值向左右相加，找到最大数组
    取左半数组，右半数组和包括中间值的交叉数组的最大值
*/

int findMaxCrossArray(vector<int> nums, int left, int mid, int right)
{
    int leftMax = 0;
    int leftAdd = 0;
    for(int i = mid; i >= left; i--)
    {
        leftAdd += nums[i];
        if(leftAdd > leftMax) leftMax = leftAdd;
    }
    int rightMax = 0;
    int rightAdd = 0;
    for(int i = mid + 1; i <= right; i++)
    {
        rightAdd += nums[i];
        if(rightAdd > rightMax) rightMax = rightAdd;
    }
    return leftMax + rightMax;
}

int findMaxSubArray(vector<int> nums, int left, int right)
{
    if(left == right) return nums[left];
    else
    {
        int mid = (left + right) / 2;
        int leftMax = findMaxSubArray(nums, left, mid);
        int rightMax = findMaxSubArray(nums, mid +1, right);
        int crossMax = findMaxCrossArray(nums, left, mid, right);
        if(leftMax > rightMax) return max(leftMax, crossMax);
        else return max(rightMax, crossMax);
    }
}

int main()
{
    vector<int> nums{13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    cout << "the max subarray is: " << findMaxSubArray(nums, 0, nums.size() - 1) << endl; 
    system("pause");
    return 0;
}