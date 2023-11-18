#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void combinationSum(vector<int>& candidates, vector<int> tempVector, vector<vector<int>>& res, int target, int i)
{
    int tempTarget = target; 
    for (; i < candidates.size(); i++)
    {
        tempTarget -= candidates[i];
        tempVector.push_back(candidates[i]);
        if(tempTarget == 0)
        {
            res.push_back(tempVector);
        }
        else if(tempTarget > 0)
        {
            combinationSum(candidates, tempVector, res, tempTarget, i);
        }
        else
        {
            return;
        }
        tempVector.pop_back();
        tempTarget = target;
    }
}

int main()
{
    vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> tempVector;
    combinationSum(candidates, tempVector, res, target, 0);

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