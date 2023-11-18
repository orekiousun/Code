#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    适用于任何除数的情况
    开一个除数空间大小的数组来储存每次加一个数后不同余数的最大值
*/
int maxSumDivThree(vector<int>& nums, int number) {
    vector<int> arr, tempArr;
    arr.resize(number, 0);
    for (int i = 0; i < nums.size(); i++) {
        tempArr = arr;
        for (int j = 0; j < number; j++) {
            tempArr[j] += nums[i];
        }
        for (int j = 0; j < number; j++) {
            arr[tempArr[j] % number] = max(tempArr[j], arr[tempArr[j] % number]);
        }
    }
    return arr[0];
}

// 分类讨论，不建议
int maxSumDivThree(vector<int>& nums) {
    int total = 0;
    for (int i = 0; i < nums.size(); i++) {
        total += nums[i];
    }
    sort(nums.begin(), nums.end());
    if(total % 3 == 0) {
        // 第一种情况：可以被3整除
        return total;
    }
    else if(total % 3 == 1) {
        // 余数为1时，要么减去一个1，要么减去2个2
        int count = 0, add = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(count == 2 && nums[i] >= add) {
                return total - add;
            }
            if(nums[i] % 3 == 1) {
                return total - nums[i];
            }
            else if(nums[i] % 3 == 2 && count < 2) {
                count++;
                add += nums[i];
            }
        }
    }
    else {
        // 余数为2时，要么减去一个2，要么减去2个1
        int count = 0, add = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(count == 2 && nums[i] >= add) {
                return total - add;
            }
            if(nums[i] % 3 == 2) {
                return total - nums[i];
            }
            else if(nums[i] % 3 == 1 && count < 2) {
                count++;
                add += nums[i];
            }
        }
    }
    return total;
}



int main() {
    vector<int> nums{3, 6, 5, 1, 8};
    cout << maxSumDivThree(nums, 3) << endl;
    system("pause");
    return 0;
}