//
// Created by ousun on 2025/5/5.
//

#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

static bool cmp(const string& s1, const string& s2) {
    return s1 + s2 > s2 + s1;
}

string maxNum(vector<string>& nums) {
    sort(nums.begin(), nums.end(), cmp);
    string ret = "";
    for (int i = 0; i < nums.size(); ++i) {
        ret += nums[i];
    }
    return ret;
}

int main() {
    vector<string> nums;
    string num;
    while (cin >> num) {
        nums.push_back(num);
    }
    cout << maxNum(nums) << endl;
    return 0;
}
