#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<algorithm>

/*
    题目一：
        输入一个正整数 target ，输出所有和为 target 的连续正整数序列（至少含有两个数）。
        序列内的数字由小到大排列，不同序列按照首个数字从小到大排列。

    方法：
        滑动窗口

    题目二：
        输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们的和正好是s。如果有多对数字的和等于s，则输出任意一对即可。
    
    方法：比较重要！！当时没有想到
        双指针, 双指针 i, j 分别指向数组 nums 的左右两端 （俗称对撞双指针）。
        
*/

vector<vector<int>> findContinuousSequence(int target) {
    vector<vector<int>> res;
    vector<int> temp;
    int end = (target / 2) + 1, add = 0;
    int left = 1, right = 1;
    for (; right <= end; right++) {
        add += right;
        temp.push_back(right);
        if(add == target) {
            res.push_back(temp);
        }
        else if(add > target) {
            while (add > target) {
                temp.erase(temp.begin());
                add -= left;
                left++;
            }
            if(add == target) {
                res.push_back(temp);
            }
        }
    }
    return res;
}

vector<int> twoSum(vector<int>& nums, int target) {
    int i = 0, j = nums.size() - 1;
    while (1) {
        int s = nums[i] + nums[j];
        if(s == target) return vector<int>{nums[i], nums[j]};
        else if(s > target) j--;
        else i++;
    }
    return vector<int>{0, 0};
}

int main(int argc, char const *argv[]) {
    vector<int> nums{1, 2, 3, 4, 5, 9, 10};
    vector<int> res = twoSum(nums, 7);
    return 0;
}
