#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>

// 笨方法
int trap(vector<int>& height, bool flag) {
    int ans = 0;
    int currentHeight = -1;
    for (int i = 0; i < height.size(); ) {
        int add = 0, j = i, maxHeight = 0;
        if(currentHeight == -1) {
            currentHeight = height[i];
            while (j != height.size() && currentHeight >= height[j]) {
                maxHeight = j == i ? maxHeight : max(maxHeight, height[j]);
                add += currentHeight - height[j];
                j++;
            }
        }
        else {
            while (j != height.size() && currentHeight > height[j]) {
                maxHeight = j == i ? maxHeight : max(maxHeight, height[j]);
                add += currentHeight - height[j];
                j++;
            }
        }
        if(j == height.size() && currentHeight > height[j - 1]) {
            currentHeight = maxHeight;
            i++;
        }
        else {
            currentHeight = -1;
            ans += add;
            i = j;
        }
    }
    return ans;
}

// 优化 --  单调栈
/*
    维护单调递减栈，当出现增元素时结算
    当出现高于栈顶的柱子时 41. 说明可以对前面的柱子结算了
    计算已经到手的雨水，然后出栈前面更低的柱子
*/
int trap(vector<int>& height) {
    int size = height.size();
    int ans = 0;
    stack<int> heightStack;
    for (int i = 0; i < size; i++) {
        while (!heightStack.empty() && height[heightStack.top()] < height[i]) {
            int current = heightStack.top();
            heightStack.pop();
            if(heightStack.empty()) break;
            int l = heightStack.top();
            int r = i;
            int h = min(height[r], height[l]) - height[current];
            ans += (r - l - 1) * h;
        }
        heightStack.push(i);
    }
    return ans;
}

int main() {
    vector<int> height{0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height) << endl;
    system("pause");
    return 0;
}