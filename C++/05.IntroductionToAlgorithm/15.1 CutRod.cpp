#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
    钢条切割问题：
    公司购买长钢条，将其切割为短钢条出售，不同切割长度的收益不同
    希望通过不同的切割方案得到最大的收益
    长度i 1 2 3 4 5  6  7  8  9  10
    价格p 1 5 8 9 10 17 17 20 24 30
*/

// 递归实现自顶向下动态规划
int buttomDownCutRod(vector<int>& nums, int n)
{
    if(n < nums.size())
    {
        return nums[n];
    }
    int result = -1;
    for (int i = 1; i < n; i++)
    {
        result = max(result, nums[i] + buttomDownCutRod(nums, n - i));
    }
    if(n == nums.size())
        nums.push_back(result);   // 将计算得到的子问题保存起来
        // 想要之后的结果，就一定要先计算之前的子问题
    return result;
}

// 自底向上完成动态规划，理解起来更直观
int buttomUpCutRod(vector<int>& nums,int n)
{
    if(n < nums.size()) return nums[n];
    // 先计算之前的值，记录之后根据之前记录下来的值计算之后的值
    for (int i = nums.size(); i <= n; i++)
    {
        int result = -1;
        for (int j = 1; j < i; j++)
        {
            result = max(result, nums[j] + nums[n - j]);
        }
        nums.push_back(result);
    }
    return nums[n];
}

int main()
{
    vector<int> nums{0, 1, 5, 8, 10, 13, 17, 18, 22, 25, 30};
    int n = 25;
    cout << buttomDownCutRod(nums, n) << endl;
    cout << buttomUpCutRod(nums, n) << endl;
    system("pause");
    return 0;
}