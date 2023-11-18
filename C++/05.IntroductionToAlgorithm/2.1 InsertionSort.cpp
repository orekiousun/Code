#include<iostream>
using namespace std;
#include<vector>

// 插入排序

void insertionSort(vector<int>& nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        // int insertNum = nums[i];
        int j = i - 1;
        // 需要执行多次交换
        while (nums[j + 1] < nums[j] && j >= 0)
        {
            int temp = nums[j + 1];
            nums[j + 1] = nums[j];
            nums[j] = temp;
            j --;
        }
    }
}

void printVector(const vector<int> nums)
{
    for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> nums{5, 2, 4, 6, 1, 3};
    cout << "before sort:" << endl;
    printVector(nums);
    insertionSort(nums);
    cout << "after sort:" << endl;
    printVector(nums);
    system("pause");
    return 0;
}