#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution
{
public:
    bool operator()(vector<int>& v1, vector<int>& v2)
    {
        return v1[0] < v2[0];
    } 
};

// 超时
/*
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), Solution());
        vector<vector<int>>::iterator it = intervals.begin();
        int i = 0;
        int size = intervals.size();
        while (i + 1 < size)
        {
            while(i + 1 < size && intervals[i][1] >= intervals[i + 1][0])
            {
                if(intervals[i][1] <= intervals[i + 1][1])
                    intervals[i][1] = intervals[i + 1][1];
                intervals.erase(it + i + 1);    
                size--;            
            }
            i++;
        }
        return intervals;
    }
*/

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    // 可以不用仿函数
    sort(intervals.begin(), intervals.end());
    int left = intervals[0][0], right = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++)
    {
        if(right >= intervals[i][0])
        {
            if(right <= intervals[i][1])
            {
                right = intervals[i][1];
            }
        }
        else
        {
            vector<int> temp{left, right};
            res.push_back(temp);
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    vector<int> temp{left, right};
    res.push_back(temp);
    return res;
}

int main()
{
    vector<int> v1{1, 3};
    vector<int> v2{3, 6};
    vector<int> v3{8, 16};
    vector<int> v4{11, 13};
    vector<int> v5{14, 18};
    
    vector<vector<int>> intervals{v1, v2, v3, v4, v5};
    vector<vector<int>> res = merge(intervals);
    

    for (int i = 0; i < res.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    system("pause");
    return 0;
}