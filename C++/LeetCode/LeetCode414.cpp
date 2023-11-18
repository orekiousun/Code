#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

int main()
{
    vector<int> nums;
    // nums.push_back(2);
    nums.push_back(-2147483648);
    nums.push_back(2);
    nums.push_back(1);

    sort(nums.begin(), nums.end(), greater<int>());
    for (int i = 1, diff = 1; i < nums.size(); i++) 
    {
        if (nums[i] != nums[i - 1]) 
        { // 此时 nums[i] 就是第三大的数
            diff ++;
        }
        if(diff == 3) return nums[i];
    }
    return nums[0];

    

    system("pause");
    return 0;
}