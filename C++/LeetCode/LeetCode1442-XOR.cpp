#include<iostream>
using namespace std;
#include<vector>

int main()
{
    vector<int> arr;
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(7);

    int size = arr.size();
    vector<int> xorArr;
    xorArr.push_back(0);
    for(int i = 0; i < arr.size(); i++)
    {
        int temp = xorArr[i] ^ arr[i];
        xorArr.push_back(temp);
    }

    int res = 0;
    for(int i = 0; i < xorArr.size(); i++)
    {
        for(int j = i + 1; j < xorArr.size(); j++)
        {
            if(xorArr[j] == xorArr[i])
                res += j - i - 1;
        }
    }


    cout << res << endl;

    system("pause");
    return 0;
}