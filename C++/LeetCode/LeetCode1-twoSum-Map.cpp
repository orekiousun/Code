#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

// 使用一个字典，边插入边查找
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> pos;
    // 边插入边查找
    for(int i = 0; i < nums.size(); ++i) {
        if(pos.count(target-nums[i])) {
            return {pos[target-nums[i]], i};
        }
        pos[nums[i]] = i;
    }

    return {};
}

int main() {
    vector<int> nums{3, 2, 4};
    vector<int> ret = twoSum(nums, 6);
    cout << 5 << endl;
    system("pause");
    return 0;
}