#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>

vector<int> func(vector<int> nums) {
    stack<int> s;
    vector<int> ans(2, 0);
    int maxNum = 0;
    s.push(nums[0]);
    int pre = 0;
    for (int i = 1; i < nums.size(); i++) {
        // 1.新来的数字大于栈顶，计算到栈顶的最大容量
        if(!s.empty() && nums[i] > s.top()) {
            int temp = (i - pre) * nums[pre];
            if(temp > maxNum) {
                maxNum = temp;
                ans[0] = pre, ans[1] = i;
            }
        }
        // 维护单调递减栈
        while(!s.empty() && nums[i] > s.top()) {
            s.pop();
        }
        if(s.empty()) {
            pre = i;
            s.push(nums[i]);
        }
        else {
            s.push(nums[i]);
            int temp = (i - pre) * nums[i];
            if(temp > maxNum) {
                maxNum = temp;
                ans[0] = pre, ans[1] = i;
            }
        }
    }
    return ans;
}

int func2(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int func3(int n) {
    int dp[n + 1];
    dp[1] = 1;
    int sum = dp[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = sum + 1;
        sum += dp[i];
    }
    return dp[n];
}

vector<vector<int>> rotate(vector<vector<int>>& matrix) {
    int N = matrix.size();
    int size = N * 2;
    for (int i = 0; i < N / 2; i++) {
        size /= 2;
        for (int j = 0; j < size - 1; j++) {
            int val1 = matrix[i][i + j], val2 = matrix[i + j][N - 1 - i],
                val3 = matrix[N - 1 - i][N - 1 - i - j], val4 = matrix[N - 1 - i - j][i];
            matrix[i][i + j] = val4, matrix[i + j][N - 1 - i] = val1, 
            matrix[N - 1 - i][N - 1 - i - j] = val2, matrix[N - 1 - i - j][i] = val3;
        }
    }
    return matrix;
}

class Item {


};

int main(int argc, char const *argv[]) {
    vector<int> v1{1, 8, 6, 2, 5, 4, 8, 3, 7};

    vector<int> ans = func(v1);


    return 0;
}
