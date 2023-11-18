#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int maxProduct(vector<int>& nums) 
{
    int maxNum = nums[0];
    int minNum = nums[0];
    int maxResult = nums[0];
    for (int i = 1; i < nums.size(); i++) 
    {
        int temp = maxNum;
        maxNum = max(maxNum * nums[i], max(nums[i], minNum * nums[i]));
        minNum = min(minNum * nums[i], min(nums[i], temp * nums[i]));
        if(maxNum > maxResult)
        {
            maxResult = maxNum;
        }
    }
    return maxResult;

}

int main()
{
    vector<int> nums{2, 3, -2, 4, -2};
    cout << maxProduct(nums) << endl;
    system("pause");
    return 0;
}