#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> weights;
    weights.push_back(1);
    weights.push_back(2);
    weights.push_back(3);
    weights.push_back(4);
    weights.push_back(5);
    weights.push_back(6);
    weights.push_back(7);
    weights.push_back(8);
    weights.push_back(9);
    weights.push_back(10);
    int days = 5;

    int res, total = 0, max = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        total += weights[i];
        if(weights[i] > max) max = weights[i];
    }
    if(days == 1) res = total;

    // 从最小开始向后遍历
    if(total % days != 0) res = total / days + 1;
    else res = total / days;

    if(max > res) res = max;

    // int daysNew;
    // while (1)
    // {
    //     daysNew = 1;
    //     int i = 0, countNow = 0;
    //     while (i < weights.size())
    //     {
    //         countNow += weights[i];
    //         if(countNow > res) 
    //         {
    //             countNow = 0;
    //             daysNew++;
    //             if(daysNew > daysNew) break;
    //         } 
    //         else
    //         {
    //             i++;
    //         }
    //     }
    //     if(daysNew <= days) break;
    //     else res++;
    // }
    
    // 优化为二分查找，在最小可能值res和最大可能值total之间找到最后的答案
    int left = res, right = total;
    while (left < right)
    {
        int weight = (left + right) / 2;
        int countNow = 0, daysNow = 1, i = 0;
        while (i < weights.size())
        {
            countNow += weights[i];
            if(countNow > weight) 
            {
                countNow = 0;
                daysNow++;
            } 
            else
            {
                i++;
            }
        }
        if(daysNow <= days)
        {
            right = weight;
        }
        else
        {
            left = weight + 1;
        }
    }
    
    
    cout << left << endl;

    system("pause");
    return 0;
}