#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// 动态规划
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};

bool canJump(vector<int>& nums)
{
    int maxPos = 0 + nums[0];
    for (int i = 1; i < nums.size() && i <= maxPos; i++)
    {
        maxPos = max(i + nums[i], maxPos);
        // int temp = i + nums[i];
        // if(temp > maxPos)
        // {
        //     maxPos = temp;
        // } 
        // if(maxPos >= nums.size() - 1)
        // {
        //     return true;
        // }
    }
    if(maxPos >= nums.size() - 1) return true;   // 判断[0]时的情况
    return false;
}

int main()
{
    vector<int> nums{2,2,0,1,0,4};
    cout << canJump(nums) << endl;
    
    system("pause");
    return 0;
}