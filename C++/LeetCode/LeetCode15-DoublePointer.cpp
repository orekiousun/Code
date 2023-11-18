#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

/*
    1.特判，对于数组长度 n,如果数组为 null 或者数组长度小于 3,返回 []
    2.对数组进行排序。
    3.遍历排序后数组：
        若nums[i]>0：因为已经排序好，所以后面不可能有三个数加和等于 00，直接返回结果
        对于重复元素：跳过，避免出现重复解
            令左指针 L=i+1，右指针 R=n-1，当 L<R 时，执行循环：
            当 nums[i]+nums[L]+nums[R]==0,执行循环，判断左界和右界是否和下一位置重复，去除重复，解并同时将 L,R 移到下一位置，寻找新的解
            若和大于 0，说明 nums[R] 太大，R 左移
            若和小于 0，说明 nums[L] 太小，L 右移
    仍然是双指针的思想
*/

int main()
{
    vector<int> nums{-1,0,1,2,-1,-4};
    vector<vector<int>> res;
    sort(nums.begin(), nums.end(), less<int>());
    int size = nums.size();

    for(int first = 0; first < size; first++)
    {
        if(first != 0 && nums[first] == nums[first - 1]) continue;
        if(nums[i] > 0) break;
        int second = first + 1, third = size - 1;
        while (second < third)
        {
            // 重复的数字只执行一次
            while (second != first + 1 && nums[second] == nums[second - 1] && second < third)
            {
                second++;
            }
            while (third != size - 1 && nums[third] == nums[third + 1] && second < third)
            {
                third--;
            }
            // 有可能达到前后一致，直接退出循环
            if(second == third) break;

            // 进行双指针的移动
            if(nums[first] + nums[second] + nums[third] > 0)
            {
                third--;
            }
            else if(nums[first] + nums[second] + nums[third] < 0)
            {
                second++;
            }
            else
            {
                vector<int> temp{nums[first], nums[second], nums[third]};
                res.push_back(temp);
                second++;
                third--;
            }
        }
    }

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    system("pause");
    return 0;
}