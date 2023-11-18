#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<stack>

/*
    维护一个单调递增栈，当出现减元素时结算
    在开头增加一个哨兵，用于结算最后还未出栈的元素
*/

int largestRectangleArea(vector<int>& heights) {
    int ans = 0, i = 0;
    stack<int> s;
    s.push(-1);
    while (1) {
        if(i == heights.size()) {
            while (s.top() != -1) {
                int height = heights[s.top()];
                s.pop();
                int width = i - s.top() - 1;
                ans = max(height * width, ans);
            }
            break;
        }
        while(s.top() != -1 && heights[i] < heights[s.top()]) {
            int height = heights[s.top()];
            s.pop();
            int width = i - s.top() - 1;
            ans = max(height * width, ans);
        }
        s.push(i);
        i++;
    }
    return ans;
}

int main() {
    vector<int> heights{2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
