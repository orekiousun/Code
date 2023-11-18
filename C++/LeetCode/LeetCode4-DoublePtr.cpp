#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// 找到此数组中比num小的个数
int findLessThanNumsCount(vector<int> nums, int num) {
    int left = 0, right = nums.size() - 1, mid;
    while (left <= right)  {
        mid = (left + right) / 2;
        if(nums[mid] < num) {
            if(mid + 1 >= nums.size() || nums[mid + 1] >= num) break;
            else left = mid + 1;
        } 
        else {
            if(mid == 0) mid = -1;
            right = mid - 1;
        }
    }
    return mid + 1;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int count, int flag) {
    int num = 0;
    int index1, index2;
    while (1) {
        index1 = findLessThanNumsCount(nums1, num);
        index2 = findLessThanNumsCount(nums2, num);
        if(index1 + index2 == count) 
            break;
        else if(index1 + index2 < count) {
            if(index1 == nums1.size()) index1--;
            else if(index2 == nums2.size()) index2--;
            num = max(nums1[index1], nums2[index2]);
        }
        else {
            if(index1 == nums1.size()) index1--;
            else if(index2 == nums2.size()) index2--;
            num = min(nums1[index1], nums2[index2]);
        }
    }
    if(index1 == nums1.size()) return nums2[index2];
    if(index2 == nums2.size()) return nums1[index1];
    else return min(nums1[index1], nums2[index2]);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int count) {
    int currentCount = 0;
    int index1 = 0, index2 = 0;
    while (currentCount < count) {
        if(index1 == nums1.size()) index2++;
        else if(index2 == nums2.size()) index1++;
        else if(nums1[index1] < nums2[index2])
            index1++;
        else 
            index2++;
        currentCount++;
    }
    if(index1 == nums1.size()) return nums2[index2];
    else if(index2 == nums2.size()) return nums1[index1];
    else return min(nums1[index1], nums2[index2]);
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    double ret;
    int number = nums1.size() + nums2.size();
    if(number % 2 == 1) {   // 有奇数个数字
        int count = number / 2;
        ret = findMedianSortedArrays(nums1, nums2, count);
    }
    else {   // 有偶数个数字
        int count1 = number / 2 - 1, count2 = number / 2;
        ret = (findMedianSortedArrays(nums1, nums2, count1) + findMedianSortedArrays(nums1, nums2, count2)) / 2;
    }
    return ret;
}

int main() {
    vector<int> nums1{1,2}, nums2{3, 4};
    
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    system("pause");
    return 0;
}