#include<iostream>
using namespace std;
#include<vector>

/*
// 单指针两次遍历
void sortColors(vector<int>& nums) 
{
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            index++;
        }
    }
    for (int i = index; i < nums.size(); i++)
    {
        if(nums[i] == 1)
        {
            int temp = nums[i];
            nums[i] = nums[index];
            nums[index] = temp;
            index++;
        }
    }
}
*/

// 双指针一次遍历
void sortColors(vector<int>& nums) 
{
    int index0 = 0;
    int index1 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            int temp = nums[i];
            nums[i] = nums[index0];
            nums[index0] = temp;
            index0++;
            if(index0 - 1 != index1)
            {
                temp = nums[i];
                nums[i] = nums[index1];
                nums[index1] = temp;
            }
            index1++;
        }
        else if(nums[i] == 1)
        {
            int temp = nums[i];
            nums[i] = nums[index1];
            nums[index1] = temp;
            index1++;
        }
    }
    
}

int main()
{
    vector<int> nums{2,0,2,1,1,0};
    sortColors(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;    
    system("pause");
    return 0;
}