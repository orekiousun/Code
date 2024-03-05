#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void swap(vector<int>& nums, int& pos1, int& pos2)
{
    int temp = nums[pos1];
    nums[pos1] = nums[pos2];
    nums[pos2] = temp;
}
void Inverse(vector<int>& nums, int left, int right)
{
    while (left < right)
    {
        if(nums[left] > nums[right])
        {
            swap(nums, left, right);
            left++;
            right--;
        }
        else    
        {
            left++;
        }
    }
}
void printVector(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

void nextPermutation(vector<int>& nums) {
    int rightPos = 0;
    int size = nums.size();

    if(size == 1) return 0;

    int i = size - 1;
    for (; i > 0; i--)
    {
        if(nums[i] > nums[i - 1])
        {
            rightPos = i - 1;
            break;
        }
    }
    if(i == 0 && nums[1] < nums[0])
    {
        Inverse(nums, 0, size - 1);
    }
    else
    {
        int minIndex = rightPos + 1;
        int min = 101;
        for (i = size - 1; i >= rightPos + 1; i--)
        {
            if(nums[i] > nums[rightPos] && nums[i] < min)
            {
                minIndex = i;
                min = nums[i];
            }
        }
        swap(nums, rightPos, minIndex);
        Inverse(nums, rightPos + 1, size - 1);
    }
}

int main()
{
    vector<int> nums{3,4,1,4,3,3};
    printVector(nums);

    nextPermutation(nums);
    
    printVector(nums);
    
    system("pause");
    return 0;
}