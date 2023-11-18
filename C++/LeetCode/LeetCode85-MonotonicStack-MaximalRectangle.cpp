#include<iostream>
using namespace std;
#include<vector>
#include<stack>
#include<algorithm>

/*
    将整个矩形图每一行都看作一个柱状图，逐行计算再求最大值
    所以要用到LeetCode84中的结果
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

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> matrixInt(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        matrixInt[0][i] = matrix[0][i] == '1' ? 1 : 0;
    }
    int ans = largestRectangleArea(matrixInt[0]);
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++){
            matrixInt[i][j] = matrix[i][j] == '1' ? matrixInt[i - 1][j] + 1 : 0;
        }
        ans = max(ans, largestRectangleArea(matrixInt[i]));
    }
    return ans;
}

int main(int argc, const char** argv) {
    vector<char> l1{'1', '0', '1', '0', '0'};
    vector<char> l2{'1', '0', '1', '1', '1'};
    vector<char> l3{'1', '1', '1', '1', '1'};
    vector<char> l4{'1', '0', '0', '1', '0'};
    vector<vector<char>> matrix{l1, l2, l3, l4};
    cout << maximalRectangle(matrix) << endl;
    system("pause");
    return 0;
}