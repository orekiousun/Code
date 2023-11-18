#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

/*
    数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
    摩尔投票法：
        若记众数的票数为 +1，非众数 的票数为 −1，则一定有所有数字的 票数和 >0
        若数组的前 a 个数字的 票数和 =0 ，则 数组剩余 (n−a) 个数字的 票数和一定仍 >0，即后 (n−a) 个数字的 众数仍为 x
        即当发生 票数和 =0 时，剩余数组的众数一定不变

*/

// 摩尔投票法
int majorityElement(vector<int>& nums) {
    int x = 0, votes = 0;
    for (int num : nums) {
        if(votes == 0) x = num;
        votes += num == x ? -1 : 1;
    }
    return x;
}

// 哈希表映射法
int majorityElement(vector<int>& nums, bool flag) {
    int threshold = nums.size() / 2;
    unordered_map<int, int> map;
    for (int num : nums) {
        map[num]++;
        if(map[num] > threshold) return num;
    }
    return 0;
}



int main(int argc, char const *argv[]) {
    vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    cout << majorityElement(nums) << endl;
    return 0;
}
