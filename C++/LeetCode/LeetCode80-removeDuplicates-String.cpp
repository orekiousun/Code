#include <iostream>
using namespace std;
#include <vector>

/*
    给你一个有序数组 nums ，请你 原地 删除重复出现的元素，使得出现次数超过两次的元素只出现两次 ，返回删除后数组的新长度。
    不要使用额外的数组空间，你必须在 原地 修改输入数组 并在使用 O(1) 额外空间的条件下完成。
*/


int removeDuplicates(vector<int>& nums) {
    int curCnt = 1;
    int i = 1;

    if (nums.size() <= 2) return nums.size();

    while (i < nums.size()){
        if (nums[i] == nums[i - 1]) {
            curCnt++;
            if (curCnt > 2) {
                nums.erase(nums.begin() + i);
                continue;
            }
        }
        else {
            curCnt = 1;
        }
        i++;
    }
    return nums.size();
}

int main(){
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    cout << removeDuplicates(nums) << endl;
    system("pause");
    return 0;
}

