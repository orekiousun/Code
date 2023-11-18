#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<deque>
#define maxInt 0x7fffffff

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> q;
    for (int i = 0; i < k; i++) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    vector<int> ans = {nums[q.front()]};
    for (int i = k; i < n; ++i) {
        while (!q.empty() && nums[i] >= nums[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
        while (q.front() <= i - k) {
            q.pop_front();
        }
        ans.push_back(nums[q.front()]);
    }
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> ans = maxSlidingWindow(nums, 3);
    for(auto item : nums) {
        cout << item << " ";
    }
    cout << endl;
    return 0;
}
