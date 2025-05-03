//
// Created by ousun on 2025/5/3.
// 柱状图中最大的矩形：https://www.programmercarl.com/0084.%E6%9F%B1%E7%8A%B6%E5%9B%BE%E4%B8%AD%E6%9C%80%E5%A4%A7%E7%9A%84%E7%9F%A9%E5%BD%A2.html
// 柱状图中最大的矩形：https://leetcode.cn/problems/largest-rectangle-in-histogram/
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int largestRectangleArea(vector<int>& heights) {
    // 对于每个柱子，计算以自己的高为最终矩形的高，所能勾勒出来的最大矩形的面积
    // 对于任意一个柱子高度i，需要知道i之前第一个高度<heights[i]的 柱子的位置和i之后第一个高度<height[i]的位置
    // 左右边界的高度都锚定为0
    int len = heights.size();
    // 从后往前，维护一个递增的栈
    stack<int> sBehind;
    vector<int> behind(len, 0);
    for (int i = len - 1; i >= 0; --i) {
        while (!sBehind.empty() && heights[sBehind.top()] >= heights[i])
            sBehind.pop();
        if (sBehind.empty()) behind[i] = len;
        else behind[i] = sBehind.top();
        sBehind.push(i);
    }

    // 从前往后，还是维护一个递增的栈
    stack<int> sFront;
    int ret = 0;
    for (int i = 0; i < len; ++i) {
        while (!sFront.empty() && heights[sFront.top()] >= heights[i])
            sFront.pop();
        int size = 0;
        if (sFront.empty()) size = heights[i] * (behind[i] - 0);
        else size = heights[i] * (behind[i] - sFront.top() - 1);
        ret = max(ret, size);
        sFront.push(i);
    }
    return ret;
}

int main() {
    vector<int> heights{2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}