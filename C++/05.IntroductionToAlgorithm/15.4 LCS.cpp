#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<string>

// 获取最长公共子序列长度
void getLCSMaxLength(string X, string Y, vector<vector<int>>& vec)
{
    for (int i = 1; i < X.size(); i++)
    {
        for (int j = 1; j < Y.size(); j++)
        {
            if(X[i] == Y[j])
            {
                vec[i][j] = vec[i - 1][j - 1] + 1;
            }
            else if(vec[i - 1][j] >= vec[i][j - 1])
            {
                vec[i][j] = vec[i - 1][j];
            }
            else
            {
                vec[i][j] = vec[i][j - 1];
            }
        }
    }
}

int main()
{
    string X = "ABCBDAB", Y = "BDCABA";
    X.insert(0, " ");
    Y.insert(0, " ");
    vector<vector<int>> vec;
    vec.resize(X.size());
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].resize(Y.size());
    }

    getLCSMaxLength(X, Y, vec);
    cout << vec[X.size() - 1][Y.size() - 1] << endl;
    system("pause");
    return 0; 
}