#include<iostream>
using namespace std;
#include<vector>

// 动态规划
int minPathSum(vector<vector<int>>& grid) 
{
    int xSize = grid.size();
    int ySize = grid[0].size();
    int arr[xSize][ySize];
    arr[0][0] = grid[0][0];
    for (int i = 1; i < xSize; i++)
    {
        arr[i][0] = arr[i - 1][0] + grid[i][0];
    }
    for (int i = 1; i < ySize; i++)
    {
        arr[0][i] = arr[0][i - 1] + grid[0][i];
    }
    for (int x = 1; x < xSize; x++)
    {
        for (int y = 1; y < ySize; y++)
        {
            if(arr[x - 1][y] < arr[x][y - 1])
            {
                arr[x][y] = arr[x - 1][y] + grid[x][y];
            }
            else
            {
                arr[x][y] = arr[x][y - 1] + grid[x][y];
            }
        }
    }
    return arr[xSize - 1][ySize - 1];
}

int main()
{
    vector<int> v1{1,3,1};
    vector<int> v2{1,5,1};
    vector<int> v3{4,2,1};
    vector<vector<int>> grid{v1, v2 ,v3};
    
    cout << minPathSum(grid) << endl;
    system("pause");
    return 0;
}