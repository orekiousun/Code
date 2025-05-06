//
// Created by ousun on 2025/5/5.
// 题意有点没理解，案例就不清楚
//

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

const int arr[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// 验证是否有序
bool checkValid(vector<vector<int>>& nums) {
    int pre = 0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (nums[i][j] == 0) continue;
            if (nums[i][j] < pre) return false;
            pre = nums[i][j];
        }
    }
    return true;
}

int calcVal(vector<vector<int>>& nums) {
    int add = 0, mul = 1;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            add += mul * nums[i][j];
            mul *= 10;
        }
    }
    return add;
}

// 暴力回溯，出现重复的就停止
// 设定最大步数为999步，保证nums[x][y]一直为0
int backtrack(vector<vector<int>>& nums, int x, int y, int& oriVal) {
    if (checkValid(nums)) return 0;
    // TODO:怎么判断该状态无法恢复成有序
    if (calcVal(nums) == oriVal) return -1;

    int ret = 0x7fffffff;
    for (int i = 0; i < 4; ++i) {
        int x0 = x + arr[i][0], y0 = y + arr[i][1];
        // 执行交换
        if (x0 >= 0 && x0 < 2 && y0 >= 0 && y0 < 3) {
            int tmp = nums[x0][y0];
            nums[x0][y0] = 0;
            nums[x][y] = tmp;
            int step = backtrack(nums, x0, y0, oriVal);
            if (step != -1)
                ret = min(1 + step, ret);
            nums[x][y] = 0;
            nums[x0][y0] = tmp;
        }
    }
    return ret == 0x7fffffff ? -1 : ret;
}

int main() {
    vector<vector<int>> nums(2, vector<int>(3, 0));
    int x0, y0;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> nums[i][j];
            if (nums[i][j] == 0) x0 = i, y0 = j;
        }
    }
    int oriVal = calcVal(nums);
    cout << backtrack(nums, x0, y0, oriVal) << endl;
    return 0;
}
