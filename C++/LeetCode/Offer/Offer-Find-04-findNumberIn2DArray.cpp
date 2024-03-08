#include<iostream>
using namespace std;
#include<vector>

/*
    在二维数组中找到数据，二维数组满足：同一行从左到右递增，同一列从上到下递增
    思路：从右上角或者左下角开始查找：（假设从右上角开始）
        ·如果target < 当前元素：删除（忽略）该列
        ·如果target > 当前元素：删除（忽略）该行
*/

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    if(matrix.empty()) return false;
    int i = 0, j = matrix[0].size() - 1;
    while (i < matrix.size() && j >= 0) {
        if(target < matrix[i][j]) j--;
        else if(target > matrix[i][j]) i++;
        else return true;
    }
    return false;
}

int main(int argc, char const *argv[]) {
    vector<int> v1{1, 4, 7, 11, 15};
    vector<int> v2{2, 5, 8, 12, 19};
    vector<int> v3{3, 6, 9, 16, 22};
    vector<int> v4{10, 13, 14, 17, 24};
    vector<int> v5{18, 21, 23, 26, 30};

    vector<vector<int>> matrix{v1, v2, v3, v4, v5};
    cout << findNumberIn2DArray(matrix, 13) << endl;

    return 0;
}
