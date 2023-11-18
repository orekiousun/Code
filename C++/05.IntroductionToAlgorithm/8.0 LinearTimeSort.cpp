#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void printVector(const vector<int>& v)
{
    for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;   
}

// 计数排序 -- O(k + n) / O(n)
void countingSort(vector<int> nums, vector<int>& res, int max)
{
    vector<int> pos(max, 0);
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        pos[nums[i]]++;
    }
    for (int i = 1; i < max; i++)
    {
        pos[i] = pos[i] + pos[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        res[pos[nums[i]] - 1] = nums[i];
        pos[nums[i]]--;
     }
}

class MyCompare1
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 % 10 < v2 % 10;
    }
};
class MyCompare2
{
public:
    bool operator()(int v1, int v2)
    {
        return (v1 / 10) % 10 < (v2 / 10) % 10;
    }
};
class MyCompare3
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 / 100 < v2 / 100;
    }
};

// 基数排序
void radixSort(vector<int>& nums)
{
    // 先对地位进行排序，再对高位进行排序，适用于一些特殊的排序情况 - 例如排序年月日之类的需要有数据的优先级的排序情况
    sort(nums.begin(), nums.end(), MyCompare1());
    sort(nums.begin(), nums.end(), MyCompare2());
    sort(nums.begin(), nums.end(), MyCompare3());
}

// 桶排序 -- O(n)
void bucketSort(vector<int>& nums)
{
    vector<int> node;
    vector<vector<int>> nodeArr(5, node);
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] >=0 && nums[i] < 2)
            nodeArr[0].push_back(nums[i]);
        else if(nums[i] >= 2 && nums[i] < 4)
            nodeArr[1].push_back(nums[i]);
        else if(nums[i] >= 4 && nums[i] < 6)
            nodeArr[2].push_back(nums[i]);
        else if(nums[i] >= 6 && nums[i] < 8)
            nodeArr[3].push_back(nums[i]);
        else
            nodeArr[4].push_back(nums[i]);
    }
    int count = 0;
    for (int i = 0; i < 5; i++)
    {
        sort(nodeArr[i].begin(), nodeArr[i].end());
        for (int j = 0; j < nodeArr[i].size(); j++)
        {
            nums[count++] = nodeArr[i][j];
        }
    }
}

int main()
{
    vector<int> nums{1, 3, 4, 8, 7, 6, 3, 2, 9, 0, 3};
    vector<int> nums2{123, 634, 568, 878, 354, 120, 435, 824, 422};
    vector<int> res(11, 0);
    cout << "original array: " << endl;
    printVector(nums);

    cout << "after counting sort: " << endl;
    countingSort(nums, res, 10);
    printVector(res);

    cout << "after radix sort: " << endl;
    radixSort(nums2);
    printVector(nums2);

    cout << "after bucket sort: " << endl;
    bucketSort(nums);
    printVector(nums);

    system("pause");
    return 0;
}