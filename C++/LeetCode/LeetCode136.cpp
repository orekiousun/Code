#include<iostream>
using namespace std;
#include<vector>

int singleNumber(vector<int>& nums) {
    int ret = 0;
    for(auto num : nums) ret ^= num;
    return ret;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;
    return 0;
}
