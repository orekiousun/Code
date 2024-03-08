#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。

    方法：
        先排序，记录0的个数和不连续的个数
*/

bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, count0 = 0, add = 0;
    while (nums[i] == 0) {
        count0++;
        i++;
    }
    while (i < 4) {
        int temp = nums[i + 1] - nums[i] - 1;
        if(temp < 0) return false;
        add += temp;
        i++;
    }
    return add <= count0 ? true : false;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{0, 0, 1, 2, 4};
    cout << isStraight(nums);
    return 0;
}
