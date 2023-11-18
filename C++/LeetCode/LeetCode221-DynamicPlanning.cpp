#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<algorithm>

int maximalSquare(vector<vector<char>>& matrix) {
    int hor = matrix[0].size(), ver = matrix.size();
    vector<int> nums;
    nums.resize(hor * ver, 0);
    for (int i = 0; i < ver; i++) {
        for (int j = 0; j < hor; j++) {
            if(matrix[i][j] == '1')
                nums[i * hor + j] = 1;
        }
    }
    int len = 0;
    for (int i = 0; i < hor * ver; i++) {
        if(nums[i] == 0 || i % hor == 0 || i < hor) {
            len = max(nums[i], len);
        }
        else {
            nums[i] = min(min(nums[i - 1], nums[i - hor]), min(nums[i - 1], nums[i - hor - 1])) + 1;
            len = max(nums[i], len);
        }
    }
    return len * len;
}

int main() {
    vector<char> l1{'1', '0', '1', '0', '0'};
    vector<char> l2{'1', '0', '1', '1', '1'};
    vector<char> l3{'1', '1', '1', '1', '1'};
    vector<char> l4{'1', '0', '0', '1', '0'};
    vector<vector<char>> matrix{l1, l2, l3, l4};

    vector<char> l5{'0', '1'};
    vector<char> l6{'1', '0'};
    vector<vector<char>> matrix1{l5, l6};

    cout << maximalSquare(matrix1) << endl;
    system("pause");
    return 0;
}