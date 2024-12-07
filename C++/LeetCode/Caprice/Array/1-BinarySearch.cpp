//
// Created by ousun on 2024/11/9.
// 二分查找：https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E6%80%9D%E8%B7%AF
// x的平方根：https://leetcode.cn/problems/sqrtx/description/
// 有效的完全平方数：https://leetcode.cn/problems/valid-perfect-square/submissions/579226990/
//

#include <iostream>
using namespace std;
#include <vector>

// 第一种写法，在 [left,right] 左闭右闭区间内查找
// 推荐这种写法
int search1(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
    while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
        int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
        if (nums[middle] > target) {
            right = middle - 1; // target 在左区间，所以[left, middle - 1]
        } else if (nums[middle] < target) {
            left = middle + 1; // target 在右区间，所以[middle + 1, right]
        } else { // nums[middle] == target
            return middle; // 数组中找到目标值，直接返回下标
        }
    }
    // 未找到目标值
    return -1;
}

// 第二种写法，在 [left,right) 左闭右开区间内查找
int search2(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size(); // 定义target在左闭右开的区间里，即：[left, right)
    while (left < right) { // 因为left == right的时候，在[left, right)是无效的空间，所以使用 <
        int middle = left + ((right - left) >> 1);
        if (nums[middle] > target) {
            right = middle; // target 在左区间，在[left, middle)中
        } else if (nums[middle] < target) {
            left = middle + 1; // target 在右区间，在[middle + 1, right)中
        } else { // nums[middle] == target
            return middle; // 数组中找到目标值，直接返回下标
        }
    }
    // 未找到目标值
    return -1;
}

// 求x的算术平方根：https://leetcode.cn/problems/sqrtx/description/
int mySqrt(int x) {
    // 在0-x范围内进行二分查找
    int left = 0, right = x, ret = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if ((long long)mid * mid <= x) {
            ret = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ret;
}

// 判断num是否是一个有效的完全平方数：https://leetcode.cn/problems/valid-perfect-square/submissions/579226990/
bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
        int mid = (left + right) / 2;
        if((long long) mid * mid < num) {
            left = mid + 1;
        } else if((long long) mid * mid > num) {
            right = mid - 1;
        } else {
            return true;
        }
    }

    return false;
}

int main() {
    cout << mySqrt(18) << endl;
    cout << mySqrt(15) << endl;
    cout << isPerfectSquare(16) << endl;
    cout << isPerfectSquare(8) << endl;
    return 0;
}
