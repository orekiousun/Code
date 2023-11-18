#include<iostream>
using namespace std;
#include<vector>


void BubbleSort(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    vector<int> nums{3, 4, 5, 1, 2};
    BubbleSort(nums);
    return 0;
}
