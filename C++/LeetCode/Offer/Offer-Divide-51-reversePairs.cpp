#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数
    例如数组[7, 5, 6, 4]中，逆序对有[7, 5], [7, 6], [7, 4], [5, 4], [6, 4]共5对

    方法：
        此题为归并排序的变种，归并排序时，会先排序两边的数组，再进行合并
        此时，如果右边数组的第 j 个小于左边数组的第 i 个，则可以记录 左边数组大小 - i 个的逆序对，依次递推
    
    注意归并排序的几个点：
        1.不用每次合并都新开空间，可以一直维护一个数组用于暂存排序后的数据
        2.统计不用额外时间，合并的时候可以顺便统计
*/

#pragma region 原来的方法，每次开新的空间
// void merge(vector<int>& nums, int begin, int mid, int right, int& ans) {
//     vector<int> vecLeft(nums.begin() + begin, nums.begin() + mid);
//     vector<int> vecRight(nums.begin() + mid, nums.begin() + right + 1);
//     int i = 0, j = 0;
//     for (; j < vecRight.size() && i < vecLeft.size(); j++) {
//         while (i < vecLeft.size() && vecRight[j] >= vecLeft[i]) {
//             i++;
//         }
//         ans += vecLeft.size() - i;
//     }
//     int k = begin;
//     i = 0, j = 0;
//     while (i < vecLeft.size() || j < vecRight.size()) {
//         if(i == vecLeft.size()) nums[k] = vecRight[j++];
//         else if(j == vecRight.size()) nums[k] = vecLeft[i++];
//         else nums[k] = vecLeft[i] < vecRight[j] ? vecLeft[i++] : vecRight[j++];
//         k++;
//     }
// }

// void mergeSort(vector<int>& nums, int begin, int end, int& ans) {
//     if(begin >= end) return;
//     int mid = (begin + end)/ 2;
//     mergeSort(nums, begin, mid, ans);
//     mergeSort(nums, mid + 1, end, ans);
//     merge(nums, begin, mid + 1, end, ans);
// }
#pragma endregion

#pragma region 新方法，始终使用同一个空间
// 利用一个常存的tmp数组来进行合并，可以不用开新的空间
void merge(vector<int>& nums, vector<int>& tmp, int begin, int mid, int end, int& ans) {
    for(int i = begin; i <= end; i++) {
        tmp[i] = nums[i];
    }
    int k = begin;
    int i = begin, j = mid;
    while (i < mid || j <= end) {
        if(i == mid) nums[k] = tmp[j++];
        else if(j == end + 1 || tmp[i] <= tmp[j]) nums[k] = tmp[i++];
        else {
            // 说明此时tmp[i] > tmp[j]，i后面的均可构成逆序对，统计即可
            nums[k] = tmp[j++];
            ans += mid - i;
        } 
        k++;
    }
}

void mergeSort(vector<int>& nums, vector<int>& tmp, int begin, int end, int& ans) {
    if(begin >= end) return;
    int mid = (begin + end)/ 2;
    mergeSort(nums, tmp, begin, mid, ans);
    mergeSort(nums, tmp, mid + 1, end, ans);
    merge(nums,tmp, begin, mid + 1, end, ans);
}
#pragma endregion

int reversePairs(vector<int>& nums) {
    int ans = 0;
    vector<int> tmp(nums.begin(), nums.end());
    mergeSort(nums, tmp, 0, nums.size() - 1, ans);
    return ans;
}

// 最终
class Solution {
public:
    int ans;
    vector<int> tmp;

    void mergeSort(vector<int>& nums, int begin, int end) {
        if(begin >= end) return;
        int mid = (begin + end) / 2;
        mergeSort(nums, begin, mid);
        mergeSort(nums, mid + 1, end);
        // 合并
        for(int i = begin; i <= end; i++) {
            tmp[i] = nums[i];
        }
        int k = begin;
        int i = begin, j = mid + 1;
        while (i <= mid || j <= end) {
            if(i == mid + 1) nums[k] = tmp[j++];
            else if(j == end + 1 || tmp[i] <= tmp[j]) nums[k] = tmp[i++];
            else {
                // 说明此时tmp[i] > tmp[j]，i后面的均可构成逆序对，统计即可
                nums[k] = tmp[j++];
                ans += mid - i + 1;
            } 
            k++;
        }
    }

    int reversePairs(vector<int>& nums) {
        ans = 0;
        tmp.resize(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums{7, 5, 6, 4};  // 5
    cout << reversePairs(nums) << endl;
    return 0;
}
