#include<iostream>
using namespace std;
#include<vector>
#include<set>
#include<unordered_set>
#include<algorithm>

// 利用unordered_set可以提速
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> num_set;
        for (const int& num : nums) 
        {
            num_set.insert(num);
        }

        int longestStreak = 0;

        for (const int& num : num_set) 
        {
            if (!num_set.count(num - 1)) 
            {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) 
                {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};

int longestConsecutive(vector<int>& nums) 
{
    if(nums.empty()) return 0;
    set<int> numsCopy;
    for (int i = 0; i < nums.size(); i++)
    {
        numsCopy.insert(nums[i]);
    }
    set<int>::iterator it = numsCopy.begin();
    int backNum = *it;
    it++;
    int tempCount = 1;
    int maxCount = 1;
    for (; it != numsCopy.end(); it++)
    {
        if(backNum + 1 == *it) tempCount++;
        else tempCount = 1;
        maxCount = max(tempCount, maxCount);
        backNum = *it;
    }
    return maxCount;
}

int main()
{
    vector<int> nums{100,4,200,1,3,2};
    cout << longestConsecutive(nums) << endl;
    system("pause");
    return 0;
}