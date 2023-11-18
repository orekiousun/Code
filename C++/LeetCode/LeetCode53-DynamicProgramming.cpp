#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

// 动态规划

int main()
{
    vector<int> nums{-2,1,-3,4,-1,2,1,-5,4};
    int pre = 0, maxNum = nums[0];
    for (int i = 0; i < nums.size(); i++)
    {
        // 每次求解的值是将当前数字作为数组的末尾的最大值
        if(pre + nums[i] > nums[i]) pre = pre + nums[i];
        else pre = nums[i];
        // pre永远是之前的数中的相加最大值
        if(pre > maxNum) maxNum = pre;
        // 如果pre大于maxNum，就更新maxNum
    }
    cout << maxNum << endl;
    system("pause");
    return 0;
}
