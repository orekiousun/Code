#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<vector<int>> matrix;
    vector<int> line0{5, 1, 9, 11};
    vector<int> line1{2, 4, 8, 10};
    vector<int> line2{13, 3, 6, 7};
    vector<int> line3{15, 14, 12, 16};
    matrix.push_back(line0);
    matrix.push_back(line1);
    matrix.push_back(line2);
    matrix.push_back(line3);
    cout << "original array: " << endl;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < line0.size(); j++)
        {
            cout << matrix[i][j] << " ";        
        }
        cout << endl;
    }

    int originalSize = matrix.size();
    int size = matrix.size();
    while (size > 0)
    {
        for (int j = 0; j < size - 1; j++)
        {
            int left = (originalSize - size) / 2;
            int right = left + j;

            // 交换四个值
            // 四个索引分别为
            // [left, right] [right, originalSize-1-left] 
            // [originalSize-1-left, originalSize-1-right] [originalSize-1-right,left]

            int temp1 = matrix[right][originalSize - 1 - left];
            int temp2 = matrix[originalSize - 1 - left][originalSize - 1 - right];
            
            matrix[right][originalSize - 1 - left] = matrix[left][right];
            matrix[originalSize - 1 - left][originalSize - 1 - right] = temp1;
            temp1 = matrix[originalSize - 1 - right][left];
            matrix[originalSize - 1 - right][left] = temp2;
            matrix[left][right] = temp1;

        }
        size -= 2;
    }
    
    cout << "after rotate: " << endl;
    
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < line0.size(); j++)
        {
            cout << matrix[i][j] << " ";        
        }
        cout << endl;
    }
    system("pause");
    return 0;
}

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // C++ 这里的 = 拷贝是值拷贝，会得到一个新的数组
        auto matrix_new = matrix;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                matrix_new[j][n - i - 1] = matrix[i][j];
            }
        }
        // 这里也是值拷贝
        matrix = matrix_new;
    }
};
