#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> map;
    for (auto item : nums) {
        map[item]++;
        if(map[item] > n / 2) return item;
    }
    return -1;
}

int main(int argc, const char** argv) {
    vector<int> nums{2,2,1,1,1,2,2};
    cout << majorityElement(nums) << endl;
    return 0;
}