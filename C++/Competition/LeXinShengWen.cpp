#include<iostream>
using namespace std;
#include<vector>
#include<stack>

// 列出所有有可能的出栈顺序

void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int> temp, stack<int> s, int index) {
    if(index == nums.size()) {
        while (!s.empty()) {
            int num = s.top();
            temp.push_back(num);
            s.pop();
        }
        ans.push_back(temp);
        return;
    }
    s.push(nums[index]);
    // 当前栈顶元素不出栈
    backtrack(nums, ans, temp, s, index + 1);
    if(index + 1 == nums.size()) return;

    // 栈顶元素逐个出栈
    while (!s.empty()){
        temp.push_back(s.top());
        s.pop();
        backtrack(nums, ans, temp, s, index + 1);
    }
}

vector<vector<int>> allStack(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    stack<int> s;

    backtrack(nums, ans, temp, s, 0);
    return ans;
}

int main(int argc, char const *argv[]) {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans = allStack(nums);
    return 0;
}
