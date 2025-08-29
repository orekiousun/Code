//
// Created by ousun on 2025/08/29.
// 有效的山脉数组：https://www.programmercarl.com/0941.%E6%9C%89%E6%95%88%E7%9A%84%E5%B1%B1%E8%84%89%E6%95%B0%E7%BB%84.html#%E6%80%9D%E8%B7%AF
// 有效的山脉数组：https://leetcode.cn/problems/valid-mountain-array/description/
// 

#include <iostream>
using namespace std;
#include <vector>

bool validMountainArray(vector<int>& arr) {
    // 分别从前往后和从后往前遍历找到山顶，山顶一致就认为是山脉数组
    int size = arr.size();
    int front_top_idx = size - 1;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] <= arr[i - 1]) {
            front_top_idx = i - 1;
            break;
        }
    }
    if (front_top_idx == size - 1) return false;

    int back_top_idx = 0;
    for (int i = arr.size() - 2; i >= 0; i--) {
        if (arr[i] <= arr[i + 1]) {
            back_top_idx = i + 1;
            break;
        }
    }
    
    if (back_top_idx == 0) return false;
    return front_top_idx == back_top_idx;
}

int main() {
    vector<int> arr = {2, 1};
    validMountainArray(arr);
    return 0;
}