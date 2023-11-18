#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int>nums{5,7,7,8,8,10}; 
    int target = 8;
    int left = 0, right = nums.size() - 1;
    int mid;
    while (left != right)
    {
        mid = (left + right) / 2;
        if(target == nums[mid]) break;
        if(target < nums[mid]) right = mid;
        else left = mid + 1;
    }
    mid = (left + right) / 2;
    vector<int> res{-1, -1};
    if(target == nums[mid])
    {
        int i = mid;
        while (target == nums[i])
        {
            i--;
        }
        res[0] = ++i;
        i = mid;
        while (target == nums[i])
        {
            i++;
        }
        res[1] = --i;
    }
    cout << res[0] << ", " << res[1] << endl;
    
    

    system("pause");
    return 0;
}