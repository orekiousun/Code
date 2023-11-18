#include<iostream>
using namespace std;
#include<vector>
#include<queue>

void BFS(vector<vector<char>>& grid, int i, int j) {
    int row = grid.size();
    int column = grid[0].size();
    grid[i][j] = '-1';
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    while (!q.empty()) {
        pair<int, int> temp = q.front();
        q.pop();
        if(temp.first + 1 < row && grid[temp.first + 1][temp.second] == '1') {
            q.push(make_pair(temp.first + 1, temp.second));
            grid[temp.first + 1][temp.second] = '-1';
        }
            
        if(temp.second + 1 < column && grid[temp.first][temp.second + 1] == '1') {
            q.push(make_pair(temp.first, temp.second + 1));
            grid[temp.first][temp.second + 1] = '-1';
        }

        if(temp.first - 1 >= 0 && grid[temp.first - 1][temp.second] == '1') {
            q.push(make_pair(temp.first - 1, temp.second));
            grid[temp.first - 1][temp.second] = '-1';
        }
            
        if(temp.second - 1 >= 0 && grid[temp.first][temp.second - 1] == '1') {
            q.push(make_pair(temp.first, temp.second - 1));
            grid[temp.first][temp.second - 1] = '-1';
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int column = grid[0].size();
    int row = grid.size();
    int result = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if(grid[i][j] == '1') {
                BFS(grid, i, j);
                result++;
            }
        }
    }
    return result;
}

int main() {
    vector<char> l1{'1','1','1'};
    vector<char> l2{'0','1','0'};
    vector<char> l3{'1','1','1'};

    vector<vector<char>> grid{l1, l2, l3};
    cout << numIslands(grid) << endl;
    system("pause");
    return 0;
}