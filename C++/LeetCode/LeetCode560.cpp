#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

/*
    给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的连续子数组的个数 。
*/

/*
    前缀和
    map用于记录前缀和为x的个数有多少个
*/
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    map[0] = 1;
    int size = nums.size(), ret = 0, total = 0;
    for (int i = 0; i < size; i++) {
        total += nums[i];
        if(map.find(total - k) != map.end()) {
            ret += map[total - k];
        }
        map[total]++;
    }
    return ret;
}

int main() {
    vector<int> nums{1, 1};
    int k = 1;
    cout << subarraySum(nums, k) << endl;
    system("pause");
    return 0;
}