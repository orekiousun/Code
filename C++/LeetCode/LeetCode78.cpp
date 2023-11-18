#include<iostream>
using namespace std;
#include<vector>

// 回溯
void getSubsets(vector<int>& nums, vector<vector<int>>& res, vector<int> temp, int index)
{
    for (int i = index; i < nums.size(); )
    {
        temp.push_back(nums[i]);
        res.push_back(temp);
        getSubsets(nums, res, temp, ++i);
        temp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> res;
    vector<int> temp;
    res.push_back(temp);
    getSubsets(nums, res, temp, 0);
    return res;
}

int main()
{
    vector<int> nums{1,2,3};
    vector<vector<int>> res = subsets(nums);
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";   
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}
