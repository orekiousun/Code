#include<iostream>
using namespace std;
#include<vector>
#include<string>

/*
    在二维字符网格中找到特定的单词
    利用深度优先搜索，利用回溯的思想往深处一直搜，搜索失败就回溯
*/

bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int currentIndex)
{
    currentIndex++;
    if(currentIndex == word.size())
        return 1;
    visited[i][j] = 1;
    bool res = 0;
    for (int k = 0; k < 4; k++) {
        switch (k) {
        case 0:   // 上
            if(i - 1 >= 0 && board[i - 1][j] == word[currentIndex] && visited[i - 1][j] == 0)
                res = search(board, visited, i - 1, j, word, currentIndex);
            break;
        case 1:   // 下
            if(i + 1 < board.size() && board[i + 1][j] == word[currentIndex] && visited[i + 1][j] == 0)
                res = search(board, visited, i + 1, j, word, currentIndex);
            break;
        case 2:   // 左
            if(j - 1 >= 0 && board[i][j - 1] == word[currentIndex] && visited[i][j - 1] == 0)
                res = search(board, visited, i, j - 1, word, currentIndex);
            break;
        case 3:   // 右
            if(j + 1 < board[0].size() && board[i][j + 1] == word[currentIndex] && visited[i][j + 1] == 0)
                res = search(board, visited, i, j + 1, word, currentIndex);
            break;
        }
        if(res == 1)
            return 1;
    }
    visited[i][j] = 0;
    return res;
}

bool exist(vector<vector<char>>& board, string word)  {
    int width = board[0].size();
    int height = board.size();
    vector<vector<bool>> visited(height, vector<bool>(width));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if(board[i][j] == word[0]) {
                if(search(board, visited, i, j, word, 0))
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    vector<char> v1{'A', 'B', 'C', 'E'};
    vector<char> v2{'S', 'F', 'E', 'S'};
    vector<char> v3{'A', 'D', 'E', 'E'};
    vector<vector<char>> board{v1, v2, v3};
    cout << exist(board, "ABCESEEEFS") << endl;
    system("pause");
    return 0;    
}


// 力扣版本
/*

class Solution {
public:
    vector<vector<bool>> visited;
    int M;
    int N;
    int K;
    int ans;

    void find(int i, int j) {
        if(i >= M || j >= N || visited[i][j])
            return;
        visited[i][j] = true;
        if(i / 10 + i % 10 + j / 10 + j % 10 <= K)
            ans++;
        else
            return;
        find(i + 1, j);
        find(i, j + 1);
    }

    int movingCount(int m, int n, int k) {
        M = m, N = n, K = k;
        ans = 0;
        visited.resize(m, vector<bool>(n));
        find(0, 0);
        return ans;
    }
};

*/