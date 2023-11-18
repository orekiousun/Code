#include<iostream>
using namespace std;
#include<vector>

void printVector(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

int partition(vector<int>& nums, int left, int right)   
// 分割，将小于midNum的值放在midNum左边，大于midNum的值放在midNum右边
{
    int midNum = nums[right];
    // 随机快排 
    // int randIndex = rand() % (right-left) + left;
    // int midNum = nums[randIndex];
    // swap(nums[right], nums[randIndex])
    int i = left - 1;
    int j = left;
    for(;j < right; j++)
    {
        if(nums[j] < midNum)
        {
            i++;
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    int temp = nums[i + 1];
    nums[i + 1] = nums[right];
    nums[right] = temp;
    return i + 1;
}

void quickSort(vector<int>& nums, int left, int right)
{
    if(left < right)
    {
        int mid = partition(nums, left, right);
        quickSort(nums, left, mid - 1);
        quickSort(nums, mid + 1, right);
    }
}

int main()
{
    vector<int> nums{2,5,1,3,9,5,3,7,5,6,9,0,1};
    cout << "before sort: " << endl;
    printVector(nums);
    cout << "after sort: " << endl;
    quickSort(nums, 0, nums.size() - 1);
    printVector(nums);
    system("pause");
    return 0;
}