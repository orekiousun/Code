#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

/*
    找到重复的数字：哈希表
*/

int findRepeatNumber(vector<int>& nums) {
    unordered_map<int, bool> map;
    for(int num : nums) {
        if(map.find(num) != map.end()) return num;
        else map[num] = true;
    }
    return -1;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    cout << findRepeatNumber(nums) << endl;
    return 0;
}
