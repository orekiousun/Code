#include<iostream>
using namespace std;
#include<vector>

int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();
    if(size == 1) return 0;
    if(size == 2) {
        if(nums[0] <= nums[1]) return 0;
        else return 2;
    }
    int left = 0, right = size - 1;
    bool flag = false;   // 用于标记left是否经过初次更新
    // 找到左边界
    for (int i = 1; i < size; i++) {
        if(nums[i] < nums[left]) {
            while (left >= 0 && nums[i] < nums[left]) {
                left--;
            }
            flag = true;
            if(left == -1) break;
        }
        else if(flag == false) {
            left = i;
        }
    }
    left = flag == true ? left + 1 : 0;

    // 找到右边界
    flag = false;
    for (int i = size - 2; i >= 0; i--) {
        if(nums[i] > nums[right]) {
            while (right <= size - 1 && nums[i] > nums[right]) {
                right++;
            }
            flag = true;
            if(right == size) break;
        }
        else if(flag == false) {
            right = i;
        }
    }
    right = flag == true ? right - 1 : -1;

    return right - left + 1;
}

int main() {
    vector<int> nums{5, 4, 3, 2, 1};
    cout << findUnsortedSubarray(nums) << endl;
    system("pause");
    return 0;
}