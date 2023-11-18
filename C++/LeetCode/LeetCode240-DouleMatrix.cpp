#include<iostream>
using namespace std;
#include<vector>

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
        if(target > matrix[row][col])
            row++;
        else if(target < matrix[row][col])
            col--;
        else 
            return 1;
    }
    return 0;
}

int main() {
    vector<int> l1{1, 4, 7, 11, 15};
    vector<int> l2{2, 5, 8, 12, 19};
    vector<int> l3{3, 6, 9, 16, 22};
    vector<int> l4{10, 13, 14, 17, 24};
    vector<int> l5{18, 21, 23, 26, 30};
    vector<vector<int>> matrix{l1, l2, l3, l4, l5};
    cout << searchMatrix(matrix, 13) << endl;
    system("pause");
    return 0;
}