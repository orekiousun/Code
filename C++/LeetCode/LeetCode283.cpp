#include<iostream>
using namespace std;
#include<vector>

void moveZeroes(vector<int>& nums) {
    int left = nums.size() - 1, right = left;
    for (; left >= 0; left--) {
        if(nums[left] == 0) {
            vector<int>::iterator it = nums.begin();
            nums.erase(it + left);
            nums.push_back(0);
        }
    }
}

// 可以利用内置的swap函数做交换
void moveZeros(vector<int>& nums, bool flag) {
    int slow=0;
    for(int fast = 0; fast < nums.size(); fast++){
        if(nums[fast] != 0)
            swap(nums[fast],nums[slow++]);
    }
}



int main(int argc, char const *argv[]) {
    vector<int> nums{0, 1, 0, 3, 1, 12};
    moveZeroes(nums);
    return 0;
}
