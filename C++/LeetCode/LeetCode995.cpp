#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> nums;
    int k = 3;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(0);

    vector<int> record;
    int pos = 0, flag = 0;
    int i = 0;

    for(; i <= nums.size() - k; i++)
    {
        int count = record.size() - pos;
        if(count % 2 == nums[i])
        {
            record.push_back(i);
        }
        if(record.size() > pos && i - record[pos] >= k - 1) 
        {
            pos++;    
        }
    }

    for (; i < nums.size(); i++)
    {
        int count = record.size() - pos;
        if(count % 2 == nums[i])
        {
            cout << -1 << endl;
        }
        if(record.size() > pos && i - record[pos] >= k - 1) 
        {
            pos++;    
        }
    }
    
    
    cout << record.size() << endl;
    system("pause");
    return 0;
}