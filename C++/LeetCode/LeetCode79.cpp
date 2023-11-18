#include<iostream>
using namespace std;
#include<vector>
#include<string>

bool search(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string& word, int currentIndex)
{
    currentIndex++;
    if(currentIndex == word.size())
        return 1;
    visited[i][j] = 1;
    bool res = 0;
    for (int k = 0; k < 4; k++)
    {
        switch (k)
        {
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

bool exist(vector<vector<char>>& board, string word) 
{
    int width = board[0].size();
    int height = board.size();
    vector<bool> vec(width, 0);
    vector<vector<bool>> visited(height, vec);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if(board[i][j] == word[0])
            {
                if(search(board, visited, i, j, word, 0))
                {
                    return 1;
                }
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